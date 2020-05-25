// Fill out your copyright notice in the Description page of Project Settings.

#include "Locker.h"

#include "Engine.h"
#include "Invisible/Player/PlayerCharacter.h"
#include "Invisible/System/MyGameInstance.h"
#include "Invisible/System/SoundSystem.h"

// Sets default values
ALocker::ALocker()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//���b�V���R���|�[�l���g���쐬����
	BodyMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	RootComponent = BodyMeshComponent;

	DummyDoor = CreateDefaultSubobject<USceneComponent>(TEXT("DummyDoor"));
	DummyDoor->SetupAttachment(RootComponent);
	DoorMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMeshComponent->SetupAttachment(DummyDoor);

	PlayerStandPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	PlayerStandPoint->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ALocker::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALocker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Tasks.IsEmpty())
		return;

	if (Tasks.Peek()->Execute())
	{
		Tasks.Pop();
	}
}

void ALocker::action_Implementation()
{
	const ESoundType Sound = ESoundType::Go_Into_Locker;
	const FVector Location = GetActorLocation();
	UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(Sound, Location, this);

	OpenDoor(0.25f);

	//�h�A���J������v���C���[�𒆂Ɉ��������
	{
		FTask Task;
		Task.BindLambda([&]() {
			APlayerCharacter* Player = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
			if (!Player)
				return false;
			const FTransform& Transform = PlayerStandPoint->GetComponentToWorld();
			Player->IntoLocker(this, Transform.GetLocation(), Transform.Rotator());
			return true;
		});
		Tasks.Enqueue(Task);
	}
    //����I�������h�A��߂�
	CloseDoor(0.25f);
}

void ALocker::GetOutPlayer()
{
			const ESoundType Sound = ESoundType::Get_Out_Locker;
			const FVector Location = GetActorLocation();
			UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(Sound, Location, this);
	OpenDoor(0.25f);

    //�h�A���J����������v���C���[���O�ɏo��
	{
		FTask Task;
		Task.BindLambda([&]() {
			APlayerCharacter* Player = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
			if (!Player)
				return false;
			Player->LockerDoorOpenedEvent();
			return true;
		});
		Tasks.Enqueue(Task);
	}
	CloseDoor(0.25f);
}

//�h�A���J��
void ALocker::OpenDoor(float OpenSecond)
{
	{
		FTask Task;
		Task.BindLambda([&, OpenSecond]() {
			RotateDoor(90.0f / OpenSecond * GetWorld()->GetDeltaSeconds());
			const bool NearlyEqual = FMath::Abs(90.0f - DummyDoor->GetRelativeRotation().Yaw) <= 0.1f;
			return NearlyEqual;
		});
		Tasks.Enqueue(Task);
	}
}

//�h�A��߂�
void ALocker::CloseDoor(float CloseSecond)
{
	{
		FTask Task;
		Task.BindLambda([&, CloseSecond]() {
			RotateDoor(-90.0f / CloseSecond * GetWorld()->GetDeltaSeconds());
			const bool NearlyEqual = FMath::Abs(DummyDoor->GetRelativeRotation().Yaw) <= 0.1f;
			return NearlyEqual;
		});
		Tasks.Enqueue(Task);
	}
}

//�h�A����]������
void ALocker::RotateDoor(float Value)
{
	DummyDoor->AddRelativeRotation(FRotator::MakeFromEuler(FVector(0, 0, Value)));
}
