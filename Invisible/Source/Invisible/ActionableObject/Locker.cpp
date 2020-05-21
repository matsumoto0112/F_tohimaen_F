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
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComponent;

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

    const ESoundType Sound = ESoundType::Go_Into_Locker;
    const FVector Location = GetActorLocation();
    UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(Sound, Location, this);

	const FTransform& Transform = PlayerStandPoint->GetComponentToWorld();
	Player->IntoLocker(this, Transform.GetLocation(), Transform.Rotator());
}

void ALocker::GetOutPlayer()
{
	const ESoundType Sound = ESoundType::Get_Out_Locker;
	const FVector Location = GetActorLocation();
	UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(Sound, Location, this);
}
