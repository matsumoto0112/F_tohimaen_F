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
	silhouetteSkeltal->bRenderCustomDepth = false;
	silhouetteSkeltal->CustomDepthStencilValue = 1;
	silhouetteSkeltal->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	reflection = 0;

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

// �ړ�����
void AEnemy::Moving(float DeltaTime)
{
	if (courses.Num() <= 0)
	{
		return;
	}

	// �����l�ݒ�
	auto pos = GetActorLocation();
	auto vector = (courses[0] - pos);
	vector.Z = 0;
	auto length = (moveSpeed < vector.Size()) ? moveSpeed : vector.Size();
	auto nor = vector.GetSafeNormal();
	auto mov = nor * length * DeltaTime;

	// �ړ�
	mov = (mov.Size() < vector.Size()) ? mov : vector;
	SetActorLocation(pos + mov);

	// ��]
	auto r = GetActorForwardVector() + nor * DeltaTime * rotateSpeed;
	SetActorRotation(r.Rotation());

	// �o�H�X�V
	if (vector.Size() <= searchManager->GetRadius())
	{
		courses.RemoveAt(0);
	}
	if (courses.Num() <= 0)
	{
		SetWait();
	}
}

// �ҋ@���Ԑݒ�
void AEnemy::SetWait()
{
	waitTimer = waitTime * FMath::FRandRange(0.0f, 1.0f);
}

// �o�H�T��
void AEnemy::SearchCourse(float DeltaTime)
{
	//auto s = std::to_string(courses.Num());
	//auto str = FString::FString(s.c_str());
	//for (int i = 0; i < courses.Num(); i++)
	//{
	//	auto num = "[ "+std::to_string(i)+" ]";
	//	auto pos = "( " + std::to_string(courses[i].X) + ", " + std::to_string(courses[i].Y) + ", " + std::to_string(courses[i].Z) + ") ";
	//	auto c = ("\n" + FString::FString((num+pos).c_str()));
	//	str += c;
	//}
	//UKismetSystemLibrary::DrawDebugString(GetWorld(), GetActorLocation(), str, nullptr, FLinearColor::Black, 0);
	if (IsEyeArea())
	{
		searchPlayer(player);
	}

	if (0 < waitTimer)
	{
		waitTimer -= DeltaTime;
		if (0 < waitTimer)
		{
			courses.RemoveAll([](FVector) { return true; });
			return;
		}
		waitTimer = 0;
	}

	if (0 < courses.Num())
	{
		return;
	}
	if (searchManager == nullptr)
	{
		return;
	}

	courses = searchManager->Course(this);
}

// �v���C���[�T��
void AEnemy::searchPlayer(AActor* OtherActor)
{
	if (searchManager == nullptr)
	{
		return;
	}

	courses.RemoveAll([](FVector) { return true; });
	courses = searchManager->Course(this, OtherActor);
	if (0 < courses.Num())
	{
		waitTimer = 0;
		auto actorLength = (OtherActor->GetActorLocation() - GetActorLocation()).Size();
		auto courseLength = (courses[0] - GetActorLocation()).Size();
		if (actorLength < courseLength)
		{
			courses.RemoveAll([](FVector) { return true; });
			courses.Add(OtherActor->GetActorLocation());
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

float GetDeg_XY(FVector forward)
{
	auto vector = forward;
	forward.Z = 0;
	auto normal = forward.GetSafeNormal();
	auto rad = FMath::Atan2(normal.Y, normal.X);
	return FMath::RadiansToDegrees(rad);
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

	return (deg <= FMath::Abs(eyeDeg / 2.0f));
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
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("heard valve sound"));
		break;
		//�X�v�����N���[�̉�����������
	case ESoundType::Sprinkler:
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("heard sprinkler sound"));
		break;
	case ESoundType::Player_Walk:
		if (IsEyeArea())
		{
			return;
		}
		searchPlayer(soundObject);
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
			if (!GetWorld()->LineTraceSingleByChannel(hit, GetActorLocation(), FVector::DownVector * 1000.0f,
			        ECollisionChannel::ECC_Visibility))
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
