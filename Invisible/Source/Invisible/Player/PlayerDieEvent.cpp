// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerDieEvent.h"

#include "Engine.h"
#include "Invisible/ActionableObject/Locker.h"
#include "Invisible/Enemy/Enemy.h"
#include "Invisible/Player/PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
APlayerDieEvent::APlayerDieEvent()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerDieEvent::BeginPlay()
{
	Super::BeginPlay();
	bIsStartedEvent = false;
	CurrentWaitTime = 0.0f;
}

// Called every frame
void APlayerDieEvent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!bIsStartedEvent)
		return;

	switch (DieEventType)
	{
	case EDieEventType::Normal:
		UpdateNormalDieEvent();
		break;
	case EDieEventType::Locker:
		UpdateLockerDieEvent();
		break;
	default:
		break;
	}
}

void APlayerDieEvent::StartNormalDieEvent(APlayerCharacter* Player, AEnemy* Enemy)
{
    if (bIsStartedEvent)return;
	this->bIsStartedEvent = true;
	DieEventType = EDieEventType::Normal;
	this->PlayerCharacter = Player;
	this->Killer = Enemy;
}

void APlayerDieEvent::StartLockerDieEvent(APlayerCharacter* Player, AEnemy* Enemy, ALocker* Locker)
{
    if (bIsStartedEvent)return;
    this->bIsStartedEvent = true;
	DieEventType = EDieEventType::Locker;
	this->PlayerCharacter = Player;
	this->Killer = Enemy;
}

void APlayerDieEvent::UpdateNormalDieEvent()
{
	switch (CurrentNormalEventPhase)
	{
	case ENormalEventPhase::ToLookEnemy:
		LookAtEnemyGradually();
		break;
	case ENormalEventPhase::Wait:
		Wait();
		break;
	default:
		break;
	}
}

void APlayerDieEvent::UpdateLockerDieEvent()
{
	switch (CurrentLockerEventPhase)
	{
	case ELockerEventPhase::LockerOpen:
		LockerOpen();
		break;
	case ELockerEventPhase::WaitLockerOpen:
		WaitLockerDoorOpen();
		break;
	case ELockerEventPhase::PlayerDie:
		Wait();
		break;
	default:
		break;
	}
}

void APlayerDieEvent::LookAtEnemyGradually()
{
	auto GetLocationIgnoreZ = [](AActor* Actor) {
		FVector Location = Actor->GetActorLocation();
		return FVector(Location.X, Location.Y, 0.0f);
	};

	const FVector PlayerLocation = GetLocationIgnoreZ(PlayerCharacter);
	const FVector EnemyLocation = GetLocationIgnoreZ(Killer);

	const FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(PlayerLocation, EnemyLocation);
	const float DeltaTime = GetWorld()->GetDeltaSeconds();
	const FRotator Rotation = FMath::RInterpTo(PlayerCharacter->GetControlRotation(), TargetRotation, DeltaTime, 3.0f);
	PlayerCharacter->Controller->SetControlRotation(Rotation);
	if (TargetRotation.Equals(PlayerCharacter->GetControlRotation(), 1.0f))
	{
		CurrentNormalEventPhase = ENormalEventPhase::Wait;
	}
}

void APlayerDieEvent::LockerOpen()
{
	ALocker* Locker = this->PlayerCharacter->GetCurrentInLocker();
	if (!Locker)
	{
		UE_LOG(LogTemp, Error, TEXT("Called LockerDirEvent When isn`t in the locker!!"));
		return;
	}
	Locker->OpenDoor(0.25f);
	CurrentLockerEventPhase = ELockerEventPhase::WaitLockerOpen;
}

void APlayerDieEvent::WaitLockerDoorOpen()
{

    ALocker* Locker = this->PlayerCharacter->GetCurrentInLocker();
    if (!Locker)
    {
        UE_LOG(LogTemp, Error, TEXT("Called LockerDirEvent When isn`t in the locker!!"));
        return;
    }
    if (Locker->IsOpenedDoor())
	{
		CurrentLockerEventPhase = ELockerEventPhase::PlayerDie;
	}
}

void APlayerDieEvent::Wait()
{
	CurrentWaitTime += GetWorld()->GetDeltaSeconds();
	if (CurrentWaitTime >= WaitTime)
	{
        CurrentNormalEventPhase = ENormalEventPhase::SceneChange;
        CurrentLockerEventPhase = ELockerEventPhase::SceneChange;
        SceneChange(NextSceneName);
	}
}
