// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"

#include "Engine.h"
#include "Invisible/Player/PlayerCharacter.h"
#include "Invisible/System/MyGameInstance.h"
#include "Invisible/System/SoundObject.h"
#include "Invisible/System/SoundSystem.h"
#include "Kismet/GameplayStatics.h"

#include <string>

namespace
{
	constexpr float WALKING_THRESHOLD = 0.5f; //!< �����Ă���Ƃ݂Ȃ�臒l
	constexpr float WALKING_SOUND_PLAY_INTERVAL = 0.66f; //!< ���s���̍Đ��Ԋu
}

float GetDeg_XY(FVector forward)
{
	auto vector = forward;
	forward.Z = 0;
	auto normal = forward.GetSafeNormal();
	auto rad = FMath::Atan2(normal.Y, normal.X);
	return FMath::RadiansToDegrees(rad);
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
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SearchCourse(DeltaTime);
	SetMaterial(DeltaTime);

	Moving(DeltaTime);
	playWalkSound(DeltaTime);
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
	params.AddIgnoredActor(this);
	if (player != nullptr)
	{
		params.AddIgnoredActor(player);
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
		auto near = searchManager->NearSearchPosition(hit.ImpactPoint);
		courses[0] = near;
	}
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

	HitMoved();

	// �����l�ݒ�
	auto pos = GetActorLocation();
	auto vector = (courses[0] - pos);
	vector.Z = 0;
	auto speed = ((moveType == EMoveType::Move) || (moveType == EMoveType::SE_Move)) ? walkSpeed : runSpeed;
	auto length = (speed < vector.Size()) ? speed : vector.Size();
	auto nor = vector.GetSafeNormal();
	auto mov = nor * speed * DeltaTime;

	// �ړ�
	//mov = (mov.Size() < vector.Size()) ? mov : vector;
	SetActorLocation(pos + mov);

	// ��]
	auto r = GetActorForwardVector() + nor * DeltaTime * rotateSpeed;
	SetActorRotation(r.Rotation());

	// �o�H�X�V
	if (vector.Size() <= searchManager->GetRadius())
	{
		lastSearch = courses[0];
		courses.RemoveAt(0);
	}
	//if (moveType == EMoveType::PlayerChase)
	//{
	//	if (player != nullptr)
	//	{
	//		if (courses.Num() <= 0)
	//		{
	//			FHitResult hit;
	//			FCollisionQueryParams params;
	//			params.AddIgnoredActor(this);
	//			if (player != nullptr)
	//			{
	//				params.AddIgnoredActor(player);
	//			}

	//			auto start = GetActorLocation();
	//			auto end = player->GetActorLocation();
	//			start.Z = player->GetActorLocation().Z;
	//			if (GetWorld()->LineTraceSingleByChannel(hit, start, end,
	//			        ECollisionChannel::ECC_Pawn, params))
	//			{
	//				if (hit.GetActor() != nullptr)
	//				{
	//					auto near = searchManager->NearSearchPosition(hit.ImpactPoint);
	//					courses.Add(player->GetActorLocation());
	//				}
	//			}
	//		}
	//	}
	//}
	if (courses.Num() <= 0)
	{
		if (moveType == EMoveType::PlayerChase)
		{
			if (searchManager->DirectionSearch(player, lastSearch))
			{
				courses.Add(player->GetActorLocation());
				return;
			}
		}
		SetWait();
	}
	//for (int i = 0; i < courses.Num() - 1; i++)
	//{
	//	auto start = courses[i];
	//	auto end = courses[i + 1];
	//	start.Z = player->GetActorLocation().Z;
	//	end.Z = player->GetActorLocation().Z;
	//	UKismetSystemLibrary::DrawDebugLine(GetWorld(), start, end, FLinearColor::Red, 10);
	//	UKismetSystemLibrary::DrawDebugSphere(GetWorld(), end, 50, 12, FLinearColor::Red, 0);
	//}
}

// �ҋ@���Ԑݒ�
void AEnemy::SetWait()
{
	if (moveType == EMoveType::None)
	{
		return;
	}
	waitTimer = waitTime * FMath::FRandRange(0.0f, 1.0f);
	moveType = EMoveType::None;
}

// �o�H�T��
void AEnemy::SearchCourse(float DeltaTime)
{
	auto mov = TMap<EMoveType, FString>{
	    {EMoveType::None, "None"},
	    {EMoveType::Move, "Move"},
	    {EMoveType::SE_Move, "SE_Move"},
	    {EMoveType::PlayerChase, "PlayerChase"},
	    {EMoveType::BranchRotate, "BranchRotate"},
	};
	auto m = mov[moveType];
	auto s = "[ " + std::to_string(courses.Num()) + " ]";
	auto str = FString::FString(s.c_str()) + m;

	str += FString::FString(("\n" + std::to_string(GetDeg_XY(GetActorForwardVector()))).c_str());
	for (int i = 0; i < courses.Num(); i++)
	{
		auto num = "[ " + std::to_string(i) + " ]";
		auto nor = "( " + std::to_string(GetDeg_XY(courses[i] - GetActorLocation())) + ") ";
		auto c = ("\n" + FString::FString((num + nor).c_str()));
		str += c;
	}
	UKismetSystemLibrary::DrawDebugString(GetWorld(), GetActorLocation(), str, nullptr, FLinearColor::Black, 0);
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
	moveType = EMoveType::Move;
}

// �v���C���[�T��
void AEnemy::searchPlayer(AActor* OtherActor)
{
	if (searchManager == nullptr)
	{
		return;
	}
	if (moveType == EMoveType::SE_Move)
	{
		return;
	}
	if (moveType == EMoveType::PlayerChase)
	{
		return;
	}
	if (IsEyeArea())
	{
		return;
	}

	moveType = EMoveType::SE_Move;
	courses.RemoveAll([](FVector) { return true; });
	courses = searchManager->Course(this, OtherActor);
	courses.Add(OtherActor->GetActorLocation());
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
		waitTimer = 0;
		moveType = EMoveType::PlayerChase;
		courses.RemoveAll([](FVector) { return true; });
		courses.Add(player->GetActorLocation());
	}
	else if (moveType == EMoveType::PlayerChase)
	{
		if (player != nullptr)
		{
			if (courses.Num() <= 0)
			{
				FHitResult hit;
				FCollisionQueryParams params;
				params.AddIgnoredActor(this);
				if (player != nullptr)
				{
					params.AddIgnoredActor(player);
				}

				auto start = GetActorLocation();
				auto end = player->GetActorLocation();
				start.Z = player->GetActorLocation().Z;
				if (GetWorld()->LineTraceSingleByChannel(hit, start, end,
				        ECollisionChannel::ECC_Pawn, params))
				{
					if (hit.GetActor() != nullptr)
					{
						//auto near = searchManager->NearSearchPosition(hit.ImpactPoint);
						courses.Add(player->GetActorLocation());
					}
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
	reflection -= thirst;
	reflection = (reflection < 0) ? 0 : (1 < reflection) ? 1 : reflection;
	skeltal->SetScalarParameterValueOnMaterials("reflection", reflection);
}

// �������ݒ�
void AEnemy::AddReflection(float add)
{
	reflection += add;
	reflection = (reflection < 0) ? 0 : (1 < reflection) ? 1 : reflection;
}

bool AEnemy::IsEyeArea()
{
	if (player == nullptr)
	{
		return false;
	}

	auto vector = (player->GetActorLocation() - GetActorLocation());
	auto e_forward_deg = GetDeg_XY(GetActorForwardVector());
	auto ep_vector_deg = GetDeg_XY(vector);

	vector.Z = 0;
	auto length = vector.Size();
	if (eyeLength < length)
	{
		return false;
	}

	e_forward_deg = (e_forward_deg < 0) ? (e_forward_deg + 360.0f) : (e_forward_deg);
	ep_vector_deg = (ep_vector_deg < 0) ? (ep_vector_deg + 360.0f) : (ep_vector_deg);

	auto deg = FMath::Abs(ep_vector_deg - e_forward_deg);
	deg = (180.0f < deg) ? (FMath::Abs(deg - 360.0f)) : (deg);

	if (deg <= FMath::Abs(eyeDeg / 2.0f))
	{
		FHitResult hit;
		FCollisionQueryParams params;
		params.AddIgnoredActor(this);
		if (player != nullptr)
		{
			params.AddIgnoredActor(player);
		}

		auto start = GetActorLocation();
		auto end = player->GetActorLocation();
		start.Z = player->GetActorLocation().Z;
		if (GetWorld()->LineTraceSingleByChannel(hit, start, end,
		        ECollisionChannel::ECC_Pawn, params))
		{
			return false;
		}
		return true;
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
		if (moveType == EMoveType::SE_Move)
		{
			return;
		}
		if (IsEyeArea())
		{
			return;
		}
		searchPlayer(soundObject);
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("heard valve sound"));
		break;
		//�X�v�����N���[�̉�����������
	case ESoundType::Sprinkler:
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("heard sprinkler sound"));
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
		}
	}
}
