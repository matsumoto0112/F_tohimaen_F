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
	PrimaryActorTick.bCanEverTick = false;

	//メッシュコンポーネントを作成する
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
}

void ALocker::action_Implementation()
{
	APlayerCharacter* Player = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (!Player)
	{
		return;
	}

	OpenDoor(0.5f);
	const ESoundType Sound = ESoundType::Go_Into_Locker;
	const FVector Location = GetActorLocation();
	UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(Sound, Location, this);

	const FTransform& Transform = PlayerStandPoint->GetComponentToWorld();
	Player->IntoLocker(this, Transform.GetLocation(), Transform.Rotator());
}

void ALocker::GetOutPlayer()
{
    CloseDoor(0.5f);
	const ESoundType Sound = ESoundType::Get_Out_Locker;
	const FVector Location = GetActorLocation();
	UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(Sound, Location, this);
}

void ALocker::OpenDoor(float OpenSecond)
{
    RotateDoor(90.0f);
}

void ALocker::CloseDoor(float CloseSecond)
{
    RotateDoor(-90.0f);
}

void ALocker::RotateDoor(float Value)
{
	DummyDoor->AddRelativeRotation(FRotator::MakeFromEuler(FVector(0, 0, Value)));
}
