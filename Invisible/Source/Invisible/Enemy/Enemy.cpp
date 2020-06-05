// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"

#include "Engine.h"
#include "Invisible/ActionableObject/Locker.h"
#include "Invisible/Player/PlayerCharacter.h"
#include "Invisible/System/MyGameInstance.h"
#include "Invisible/System/SoundObject.h"
#include "Invisible/System/SoundSystem.h"
#include "Invisible/System/StencilBitValue.h"
#include "Kismet/GameplayStatics.h"

#include <string>

namespace
{
	constexpr float WALKING_THRESHOLD = 0.5f; //!< �����Ă���Ƃ݂Ȃ�臒l
	constexpr float WALKING_SOUND_PLAY_INTERVAL = 0.66f; //!< ���s���̍Đ��Ԋu

	enum class ERotateType : uint8
	{
		Right,
		Left,
	};
	ERotateType rotateType = ERotateType::Right;

	EPlayerActionMode playerActiveType = EPlayerActionMode::Default;
	float GetDeg_XY(FVector forward)
	{
		auto vector = forward;
		forward.Z = 0;
		auto normal = forward.GetSafeNormal();
		auto rad = FMath::Atan2(normal.Y, normal.X);
		auto deg = FMath::RadiansToDegrees(rad);
		return deg;
	}

	FVector VectorXY(FVector vector)
	{
		vector.Z = 0;
		return vector;
	}

	float Height()
	{
		return 150.0f;
	}
}

// Sets default values
AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("capsule"));
	capsule->InitCapsuleSize(20.0f, 80.0f);
	RootComponent = capsule;

	skeltal = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeltal"));
	skeltal->SetupAttachment(RootComponent);

	actionableArea = CreateDefaultSubobject<USphereComponent>(TEXT("ActionableArea"));
	actionableArea->InitSphereRadius(2000.0f);
	actionableArea->SetCollisionProfileName("OverlapOnlyPawn");
	actionableArea->SetSimulatePhysics(false);
	actionableArea->SetupAttachment(RootComponent);

	actionableArea->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::onComponentBeginOverlap);
	//skeltal->OnComponentHit.AddDynamic(this, &AEnemy::onComponentHit);
	//this->GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::onComponentBeginOverlap);

	silhouetteSkeltal = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SilhouetteSkeltal"));
	silhouetteSkeltal->bRenderInMainPass = false;
	silhouetteSkeltal->bRenderInDepthPass = false;
	silhouetteSkeltal->bRenderCustomDepth = true;
	silhouetteSkeltal->CustomDepthStencilValue = 0;
	silhouetteSkeltal->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	//reflection = 1;
	//thirstSpeed = 10000;
	lastSearch = GetActorLocation();

	auto actor = UGameplayStatics::GetActorOfClass(GetWorld(), APlayerCharacter::StaticClass());
	player = (actor == nullptr) ? nullptr : actor;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemy::StaticClass(), enemys);
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (UMyGameInstance::GetInstance()->getClear()) {
		return;
	}

	InLocker();
	DebugDraw();
	SetMaterial(DeltaTime);
	if (IsKill(DeltaTime))
		return;

	SearchCourse(DeltaTime);
	Moving(DeltaTime);
	playWalkSound(DeltaTime);
}

bool AEnemy::IsKill(float DeltaTime)
{
	if (IsInLocker() && (Cast<APlayerCharacter>(player)->GetCurrentInLocker()))
	{
		auto locker = Cast<APlayerCharacter>(player)->GetCurrentInLocker();
		if (VectorXY(locker->GetActorLocation() - GetActorLocation()).Size() < searchManager->GetRadius() * 2)
		{
			if (moveType != EMoveType::Kill)
			{
				PlayerKill();
			}
		}
	}

	if (moveType == EMoveType::Kill)
	{
		// �����l�ݒ�
		auto pos = GetActorLocation();

		switch (playerActiveType)
		{
		case EPlayerActionMode::GetOutOfLocker:
		case EPlayerActionMode::GoingIntoLocker:
			auto p = Cast<APlayerCharacter>(player);
			if (p->GetCurrentInLocker())
			{
				auto locker = p->GetCurrentInLocker();
				auto lockerForward = VectorXY(locker->GetActorLocation() + locker->GetActorForwardVector() * searchManager->GetRadius());
				auto vector = VectorXY(lockerForward - pos);
				if (10 < vector.Size())
				{
					pos += vector.GetSafeNormal() * walkSpeed * DeltaTime;
					SetActorLocation(pos);
				}
			}
		}

		auto vector = VectorXY(player->GetActorLocation() - pos);
		auto nor = vector.GetSafeNormal();

		// ��]
		auto r = GetActorForwardVector() + nor * DeltaTime * rotateSpeed;
		SetActorRotation(r.Rotation());
		return true;
	}
	return false;
}

// �ړ�����
void AEnemy::Moving(float DeltaTime)
{
	if (courses.Num() <= 0)
	{
		return;
	}
	if (moveType == EMoveType::None)
	{
		return;
	}
	if ((moveType == EMoveType::Move))
	{
		if (0 < searchWaitRotateTimer)
		{
			searchWaitRotateTimer = FMath::Max(0.0f, searchWaitRotateTimer - DeltaTime);

			auto rotVec = (rotateType == ERotateType::Right) ?
			    GetActorRightVector() :
			    -GetActorRightVector();

			// ��]
			auto r = GetActorForwardVector() + rotVec * DeltaTime * 6.0f / FMath::Max(1.0f, searchWaitRotateTime);
			SetActorRotation(r.Rotation());
			if (0 < searchWaitRotateTimer)
			{
				return;
			}
		}
	}

	// �o�H�X�V
	if ((VectorXY(courses[0] - GetActorLocation())).Size() <= searchManager->GetRadius())
	{
		if (0 < courses.Num())
		{
			lastSearch = courses[0];
			courses.RemoveAt(0);

			if ((1 == courses.Num()) && (moveType == EMoveType::PlayerChase))
			{
				FHitResult hit;
				FCollisionQueryParams params;

				params.AddIgnoredActors(enemys);
				if (player != nullptr)
				{
					params.AddIgnoredActor(player);
				}
				if (IsInLocker() && (Cast<APlayerCharacter>(player)->GetCurrentInLocker() != nullptr))
				{
					params.AddIgnoredActor(Cast<APlayerCharacter>(player)->GetCurrentInLocker());
				}

				auto start = courses[0];
				auto end = player->GetActorLocation();
				start.Z = Height();
				end.Z = Height();

				if (!GetWorld()->LineTraceSingleByChannel(hit, start, end,
				        ECollisionChannel::ECC_Pawn, params))
				{
					courses.RemoveAll([](FVector) { return true; });
					courses = searchManager->Course(start, end);
				}
			}

			if ((0 <= courses.Num()) && (FMath::FRandRange(0.0f, 100.0f) <= FMath::Clamp(searchWaitPercent, 0.0f, 100.0f)))
			{
				searchWaitRotateTimer = FMath::Max(1.0f, searchWaitRotateTime);

				rotateType = (FMath::FRandRange(0.0f, 100.0f) <= 50.0f) ?
				    ERotateType::Right :
				    ERotateType::Left;
			}
		}
	}
	else
	{
		HitMoved();

		// �����l�ݒ�
		auto pos = (GetActorLocation());
		auto vector = VectorXY(courses[0] - pos);
		auto nor = vector.GetSafeNormal();

		//	�ړ��l�ݒ�
		auto speed = ((moveType == EMoveType::Move) || (moveType == EMoveType::SE_Move)) ? walkSpeed : runSpeed;
		auto length = (speed < vector.Size()) ? speed : vector.Size();
		auto mov = nor * speed * DeltaTime;

		// �ړ�
		SetActorLocation(pos + mov);

		// ��]
		auto r = GetActorForwardVector() + nor * DeltaTime * rotateSpeed;
		SetActorRotation(r.Rotation());
	}

	if (courses.Num() <= 0)
	{
		if (moveType == EMoveType::PlayerChase)
		{
			if (IsInLocker())
			{
				auto p = Cast<APlayerCharacter>(player);
				auto locker = p->GetCurrentInLocker();
				auto pos = VectorXY(locker->GetActorLocation() + locker->GetActorForwardVector() * searchManager->GetRadius());

				courses.RemoveAll([](FVector) { return true; });
				courses = searchManager->Course(GetActorLocation(), pos);
			}
			else
			{
				FHitResult hit;
				FCollisionQueryParams params;

				params.AddIgnoredActors(enemys);
				if (player != nullptr)
				{
					params.AddIgnoredActor(player);
				}

				auto start = GetActorLocation();
				auto end = player->GetActorLocation();
				start.Z = Height();
				end.Z = Height();

				if (!GetWorld()->LineTraceSingleByChannel(hit, start, end,
				        ECollisionChannel::ECC_Pawn, params))
				{
					courses.Add(player->GetActorLocation());
					return;
				}

				UMyGameInstance::GetInstance()->getSoundSystem()->StopBGM();
			}
		}
		SetWait();
	}
}

void AEnemy::HitMoved()
{
	if (searchManager == nullptr)
	{
		return;
	}
	if (courses.Num() <= 0)
	{
		return;
	}

	FHitResult hit;
	FCollisionQueryParams params;

	params.AddIgnoredActors(enemys);
	if (player != nullptr)
	{
		params.AddIgnoredActor(player);
	}
	if (IsInLocker() && (Cast<APlayerCharacter>(player)->GetCurrentInLocker() != nullptr))
	{
		params.AddIgnoredActor(Cast<APlayerCharacter>(player)->GetCurrentInLocker());
	}

	auto start = GetActorLocation();
	auto end = courses[0];
	start.Z = (player == nullptr) ? 100 : player->GetActorLocation().Z;
	end.Z = (player == nullptr) ? 100 : player->GetActorLocation().Z;

	if (GetWorld()->LineTraceSingleByChannel(hit, start, end,
	        ECollisionChannel::ECC_Pawn, params))
	{
		if (hit.GetActor() == nullptr)
		{
			return;
		}

		auto point = VectorXY(hit.ImpactPoint);
		auto normal = VectorXY(hit.Normal).GetSafeNormal();
		auto vector = VectorXY(start - point);
		auto near = VectorXY(point + normal * searchManager->GetRadius() / 2.0f);

		courses.Insert(near, 0);
	}
}

// �ҋ@���Ԑݒ�
void AEnemy::SetWait()
{
	if (moveType == EMoveType::None)
	{
		return;
	}

	if (IsInLocker())
	{
		return;
	}

	waitTimer = waitTime * FMath::FRandRange(0.0f, 1.0f);
	moveType = EMoveType::None; //	moveType => None
}

// �o�H�T��
void AEnemy::SearchCourse(float DeltaTime)
{
	chasePlayer();

	if (moveType == EMoveType::None)
	{
		waitTimer -= DeltaTime;
		if (0 < waitTimer)
		{
			courses.RemoveAll([](FVector) { return true; });
			return;
		}
		waitTimer = 0;
	}

	if (searchManager == nullptr)
	{
		return;
	}
	if (0 < courses.Num())
	{
		return;
	}
	if (moveType != EMoveType::None)
	{
		return;
	}

	courses = searchManager->Course(this);
	if (courses.Contains(lastSearch))
	{
		courses.Remove(lastSearch);
	}
	moveType = EMoveType::Move; //	moveType => Move
}

// �v���C���[�T��
void AEnemy::searchPlayer(AActor* OtherActor)
{
	if (searchManager == nullptr)
	{
		return;
	}
	if (moveType == EMoveType::PlayerChase)
	{
		return;
	}

	waitTimer = 0;
	searchWaitRotateTimer = 0;

	moveType = EMoveType::SE_Move; //	moveType => SE_Move
	courses.RemoveAll([](FVector) { return true; });
	courses = searchManager->Course(this, OtherActor);
}

// �v���C���[�ǐ�
void AEnemy::chasePlayer()
{
	if (player == nullptr)
	{
		return;
	}
	if (IsEyeArea())
	{
		if (moveType != EMoveType::PlayerChase)
		{
			UMyGameInstance::GetInstance()->getSoundSystem()->PlayBGM(ESoundType::Chase_BGM);
		}
		waitTimer = 0;
		searchWaitRotateTimer = 0;

		moveType = EMoveType::PlayerChase; //	moveType => PlayerChase
		courses.RemoveAll([](FVector) { return true; });
		auto vector = (VectorXY(player->GetActorLocation() - GetActorLocation())).GetSafeNormal();
		auto pos = player->GetActorLocation() + vector * searchManager->GetRadius();
		if (IsInLocker())
		{
			auto p = Cast<APlayerCharacter>(player);
			auto locker = p->GetCurrentInLocker();
			pos = VectorXY(locker->GetActorLocation() + locker->GetActorForwardVector() * searchManager->GetRadius());
		}

		courses.Add(pos);
	}
	else if (moveType == EMoveType::PlayerChase)
	{
		if (player != nullptr)
		{
			if (courses.Num() <= 0)
			{
				FHitResult hit;
				FCollisionQueryParams params;

				params.AddIgnoredActors(enemys);
				if (player != nullptr)
				{
					params.AddIgnoredActor(player);
				}

				auto start = GetActorLocation();
				auto end = player->GetActorLocation();
				start.Z = Height();
				end.Z = Height();

				if (!GetWorld()->LineTraceSingleByChannel(hit, start, end,
				        ECollisionChannel::ECC_Pawn, params))
				{
					courses.RemoveAll([](FVector) { return true; });
					courses = searchManager->Course(this, player);
				}
				else if (IsInLocker())
				{
					auto p = Cast<APlayerCharacter>(player);
					auto locker = p->GetCurrentInLocker();
					auto pos = VectorXY(locker->GetActorLocation() + locker->GetActorForwardVector() * searchManager->GetRadius());
					courses.Add(pos);
				}
			}
		}
	}
}

// �}�e���A��
void AEnemy::SetMaterial(float DeltaTime)
{
	overBathing();

	float thirst = (thirstSpeed <= 1.0f) ? DeltaTime : DeltaTime / thirstSpeed;
	if (moveType == EMoveType::Kill)
	{
		reflection += DeltaTime;
	}
	else
	{
		reflection -= thirst;
	}

	reflection = (reflection < 0) ? 0 : (1 < reflection) ? 1 : reflection;
	skeltal->SetScalarParameterValueOnMaterials("reflection", reflection);
}

// �������ݒ�
void AEnemy::AddReflection(float add)
{
	reflection += add;
	reflection = (reflection < 0) ? 0 : (1 < reflection) ? 1 : reflection;
}

void AEnemy::DebugDraw()
{
	if (debugDraw == 0)
	{
		return;
	}

	// ----- �f�o�b�O�����`�� -----------------------------------------------------------------------------------------
	auto mov = TMap<EMoveType, FString>{
	    {EMoveType::None, "None"},
	    {EMoveType::Move, "Move"},
	    {EMoveType::SE_Move, "SE_Move"},
	    {EMoveType::PlayerChase, "PlayerChase"},
	    {EMoveType::Kill, "Kill"},
	};
	auto m = mov[moveType];
	auto s = "[ " + std::to_string(courses.Num()) + " ]";
	auto str = FString::FString(s.c_str()) + m;

	str += FString::FString(("\n" + std::to_string(GetDeg_XY(GetActorForwardVector()))).c_str());

	switch (Cast<APlayerCharacter>(player)->GetCurrentActionMode())
	{
	case EPlayerActionMode::IsInLocker:
		str += FString::FString("\nIsInLocker >> ");
		break;
	case EPlayerActionMode::GetOutOfLocker:
		str += FString::FString("\nGetOutOfLocker >> ");
		break;
	case EPlayerActionMode::GoingIntoLocker:
		str += FString::FString("\nGoingIntoLocker >> ");
		break;
	default:
		str += FString::FString("\nDefault >> ");
		break;
	}
	switch (playerActiveType)
	{
	case EPlayerActionMode::IsInLocker:
		str += FString::FString("IsInLocker\n");
		break;
	case EPlayerActionMode::GetOutOfLocker:
		str += FString::FString("GetOutOfLocker\n");
		break;
	case EPlayerActionMode::GoingIntoLocker:
		str += FString::FString("GoingIntoLocker\n");
		break;
	default:
		str += FString::FString("Default\n");
		break;
	}
	str += FString::FString(IsEyeArea() ? ">>>>>  IsEyeArea_IN  <<<<<\n" : ">>>>>  IsEyeArea_OUT  <<<<<\n");
	str += FString::FString(IsInLocker() ? ">>>>>  IsInLocker_IN  <<<<<\n" : ">>>>>  IsInLocker_OUT  <<<<<\n");

	for (int i = 0; i < courses.Num(); i++)
	{
		auto num = "[ " + std::to_string(i) + " ]";
		auto pos = "( " + std::to_string(courses[i].X) + ", ";
		pos += std::to_string(courses[i].Y) + ", ";
		pos += std::to_string(courses[i].Z) + ") ";

		auto c = ("\n" + FString::FString((num + pos).c_str()));
		str += c;
	}
	UKismetSystemLibrary::DrawDebugString(GetWorld(), GetActorLocation(), str, nullptr, FLinearColor::Blue, 0);
	// ----------------------------------------------------------------------------------------------------------------
}

// ���b�J�[����
void AEnemy::InLocker()
{
	auto start = GetActorLocation();
	auto end = player->GetActorLocation();
	start.Z = Height();
	end.Z = Height();

	if (eyeLength < (end - start).Size())
	{
		return;
	}

	FHitResult hit;
	FCollisionQueryParams params;

	params.AddIgnoredActors(enemys);
	if (player != nullptr)
	{
		params.AddIgnoredActor(player);
		if (Cast<APlayerCharacter>(player))
		{
			auto p = Cast<APlayerCharacter>(player);
			switch (p->GetCurrentActionMode())
			{
			case EPlayerActionMode::IsInLocker:
			case EPlayerActionMode::GetOutOfLocker:
			case EPlayerActionMode::GoingIntoLocker:

				params.AddIgnoredActor(p->GetCurrentInLocker());
			}
		}
	}

	if (GetWorld()->LineTraceSingleByChannel(hit, start, end,
	        ECollisionChannel::ECC_Pawn, params))
	{
		return;
	}

	// ���b�J�[IN
	if (Cast<APlayerCharacter>(player))
	{
		auto p = Cast<APlayerCharacter>(player);

		switch (p->GetCurrentActionMode())
		{
		case EPlayerActionMode::GetOutOfLocker:
		case EPlayerActionMode::GoingIntoLocker:

			if (playerActiveType != p->GetCurrentActionMode())
			{
				courses = searchManager->ChaseCourse(GetActorLocation(), player->GetActorLocation());
			}
			playerActiveType = p->GetCurrentActionMode();
			break;
		}
	}
}

//	���E�ɓ����Ă��邩�ǂ���
bool AEnemy::IsEyeArea()
{
	if (player == nullptr)
	{
		playerActiveType = EPlayerActionMode::Default;
		return false;
	}

	// �x�N�g���Ɗp�x�̑��
	auto vector = VectorXY(player->GetActorLocation() - GetActorLocation());
	auto e_forward_deg = GetDeg_XY(GetActorForwardVector());
	auto ep_vector_deg = GetDeg_XY(vector);

	// ���싗���ɂ��邩����
	auto length = vector.Size();
	if (eyeLength < length)
	{
		playerActiveType = EPlayerActionMode::Default;
		return false;
	}
	if (length < 500)
	{
		return true;
	}

	// -360���`0���ȉ���0���`360���ɕύX
	e_forward_deg = (e_forward_deg < 0) ? (e_forward_deg + 360.0f) : (e_forward_deg);
	ep_vector_deg = (ep_vector_deg < 0) ? (ep_vector_deg + 360.0f) : (ep_vector_deg);

	auto deg = FMath::Abs(ep_vector_deg - e_forward_deg);
	deg = (180.0f < deg) ? (FMath::Abs(deg - 360.0f)) : (deg);

	if (deg <= FMath::Abs(eyeDeg / 2.0f))
	{
		FHitResult hit;
		FCollisionQueryParams params;

		params.AddIgnoredActors(enemys);
		if (player != nullptr)
		{
			params.AddIgnoredActor(player);
			if (IsInLocker())
			{
				if (Cast<APlayerCharacter>(player))
				{
					auto p = Cast<APlayerCharacter>(player);
					switch (p->GetCurrentActionMode())
					{
					case EPlayerActionMode::IsInLocker:
					case EPlayerActionMode::GetOutOfLocker:
					case EPlayerActionMode::GoingIntoLocker:

						params.AddIgnoredActor(p->GetCurrentInLocker());

						break;
					}
				}
			}
		}

		// �v���C���[�A�G�̓�_�Ԃɏ�Q�������邩����
		auto start = GetActorLocation();
		auto end = player->GetActorLocation();
		start.Z = Height();
		end.Z = Height();

		if (GetWorld()->LineTraceSingleByChannel(hit, start, end,
		        ECollisionChannel::ECC_Pawn, params))
		{
			if (Cast<ALocker>(hit.GetActor()))
			{
				if ((Cast<APlayerCharacter>(player)->GetCurrentActionMode() == EPlayerActionMode::IsInLocker) && (Cast<ALocker>(hit.GetActor()) == Cast<APlayerCharacter>(player)->GetCurrentInLocker()))
				{
					return IsInLocker();
				}
			}

			return false;
		}

		return true;
	}

	switch (Cast<APlayerCharacter>(player)->GetCurrentActionMode())
	{
	case EPlayerActionMode::IsInLocker:
	case EPlayerActionMode::GetOutOfLocker:
	case EPlayerActionMode::GoingIntoLocker:
		return IsInLocker();
		break;
	default:
		playerActiveType = EPlayerActionMode::Default;
		break;
	}
	return false;
}

// �ՓˊJ�n���ɌĂ΂��
void AEnemy::onComponentBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//���I�u�W�F�N�g�Ȃ特����������͈͓��ɓ��������Ƃ�\��
	if (Cast<ASoundObject>(OtherActor))
	{
		heardSound(Cast<ASoundObject>(OtherActor));
		return;
	}
}

// �v���C���[�|������
void AEnemy::PlayerKill()
{
	if (moveType == EMoveType::Kill)
	{
		return;
	}
	if (UMyGameInstance::GetInstance()->getClear())
	{
		return;
	}

	auto p = Cast<APlayerCharacter>(player);
	p->ToDie(this);
	moveType = EMoveType::Kill;

	UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(ESoundType::Enemy_Shout, GetActorLocation(), this);
}

bool AEnemy::IsMove() const
{
	return ((moveType == EMoveType::Move) || (moveType == EMoveType::SE_Move) || (moveType == EMoveType::PlayerChase));
}
bool AEnemy::IsKill() const
{
	return (moveType == EMoveType::Kill);
}

bool AEnemy::IsInLocker()
{
	switch (playerActiveType)
	{
	//case EPlayerActionMode::IsInLocker:
	case EPlayerActionMode::GetOutOfLocker:
	case EPlayerActionMode::GoingIntoLocker:

		if (Cast<APlayerCharacter>(player))
		{
			auto p = Cast<APlayerCharacter>(player);
			switch (p->GetCurrentActionMode())
			{
			case EPlayerActionMode::IsInLocker:
			case EPlayerActionMode::GetOutOfLocker:
			case EPlayerActionMode::GoingIntoLocker:
				return (p->GetCurrentInLocker() != nullptr);
			}
		}
	}
	return false;
}

//// �ՓˊJ�n���ɌĂ΂��
//void AEnemy::onComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
//    UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& SweepResult)
//{
//	bathing(OtherActor);
//}

//������������͈͓��ɓ�����
void AEnemy::heardSound(ASoundObject* soundObject)
{
	switch (soundObject->getSoundType())
	{
		//�o���u�̉�����������
	case ESoundType::Valve:
		searchPlayer(soundObject);
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("heard valve sound"));
		break;
	case ESoundType::Player_Walk:
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("heard Player_Walk sound"));
		break;
	default:
		break;
	}
}

void AEnemy::playWalkSound(float deltaTime)
{
	//�����Ă���Ƃ��Ɉ�莞�Ԃ��Ƃɕ��s���Đ�
	if (0 < courses.Num())
	{
		walkingSecond += deltaTime;

		//�����Ă��鎞�Ԃ����ʂ𒴂�����Đ�����
		if (walkingSecond > WALKING_SOUND_PLAY_INTERVAL)
		{
			walkingSecond -= WALKING_SOUND_PLAY_INTERVAL;

			FHitResult hit;
			FCollisionQueryParams params;
			params.AddIgnoredActor(this);
			if (!GetWorld()->LineTraceSingleByChannel(hit, GetActorLocation() + FVector(0, 0, 100), GetActorLocation() + FVector::DownVector * 1000.0f,
			        ECollisionChannel::ECC_Visibility, params))
				return;
			const ESoundType sound = [&hit]() {
				//TODO:GamePlayTag�ŏ�������̂��]�܂���
				//TODO:���Ɛe�N���X����v�����Ȃ��Ɠ��
				if (hit.Actor->ActorHasTag(TEXT("Puddle")))
				{
					return ESoundType::Enemy_Walk_On_Puddle;
				}
				return ESoundType::Enemy_Walk;
			}();

			FVector seLocation = GetActorLocation();
			seLocation.Z = hit.Location.Z;
			UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(sound, seLocation, this);
		}
	}
	else
	{
		walkingSecond = 0.0f;
	}
}

// �����я���
void AEnemy::overBathing()
{
	TArray<AActor*> actors;
	skeltal->GetOverlappingActors(actors);
	actors.RemoveAllSwap([](AActor* a) { return !a->ActorHasTag(TEXT("Sprinkler")); });

	for (int i = 0; i < actors.Num(); i++)
	{
		if (actors[i]->ActorHasTag(TEXT("Sprinkler")))
		{
			extern ENGINE_API float GAverageFPS;
			AddReflection(1.0f / GAverageFPS);
			ChangeStencilValueWhenPutOnWater();
		}
	}
}

//�������Ԃ������̃X�e���V���l�̕ύX
void AEnemy::ChangeStencilValueWhenPutOnWater()
{
	//�X�e���V���l�𐅂����Ԃ������p�̒l�Řa���Ƃ�
	USkeletalMeshComponent* SilhouetteSkeltal = GetSilhouetteSkeltal();
	const int32 Value = SilhouetteSkeltal->CustomDepthStencilValue | static_cast<int32>(EStencilBitValue::SilhouetteWhenEnemyPutOnWater);
	SilhouetteSkeltal->SetCustomDepthStencilValue(Value);

	//�Ō�ɓ�������������L���ɂ������̂ŌÂ��^�C�}�[�͔j������
	FTimerManager& TimerManager = GetWorldTimerManager();
	TimerManager.ClearTimer(ReturnStencilValueWhenPutOnWaterHandle);
	TimerManager.SetTimer(ReturnStencilValueWhenPutOnWaterHandle, [SilhouetteSkeltal]() {
		//�Q�[�����I������Ȃǂ��ăX�P���^�����Q�Ƃł��Ȃ��ꍇ�ɔ����ă`�F�b�N����
		if (!SilhouetteSkeltal)
			return;
		const int32 Value = SilhouetteSkeltal->CustomDepthStencilValue & ~static_cast<int32>(EStencilBitValue::SilhouetteWhenEnemyPutOnWater);
		SilhouetteSkeltal->SetCustomDepthStencilValue(Value);
	},
	    VisibleTimeWhenEnemyPutOnWater, false);
}
