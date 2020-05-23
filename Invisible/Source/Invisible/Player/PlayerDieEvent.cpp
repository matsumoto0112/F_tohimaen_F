// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerDieEvent.h"

#include "Engine.h"
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
		break;
	default:
		break;
	}
}

void APlayerDieEvent::StartNormalDieEvent(APlayerCharacter* Player, AEnemy* Enemy)
{
	this->bIsStartedEvent = true;
	DieEventType = EDieEventType::Normal;
	this->PlayerCharacter = Player;
	this->Killer = Enemy;
}

void APlayerDieEvent::StartLockerDieEvent(APlayerCharacter* Player, AEnemy* Enemy, ALocker* Locker)
{
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

void APlayerDieEvent::Wait()
{
	CurrentWaitTime += GetWorld()->GetDeltaSeconds();
	if (CurrentWaitTime >= WaitTime)
	{
		CurrentNormalEventPhase = ENormalEventPhase::SceneChange;
		SceneChange(NextSceneName);
	}
}
