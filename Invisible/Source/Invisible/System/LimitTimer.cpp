// Fill out your copyright notice in the Description page of Project Settings.

#include "LimitTimer.h"

#include <Engine/Engine.h>
#include <GameFramework/PlayerController.h>

// Sets default values
ALimitTimer::ALimitTimer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALimitTimer::BeginPlay()
{
	Super::BeginPlay();

	//Init(limitTime);
}

// Called every frame
void ALimitTimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	limitTimer = FMath::Max(0.0f, limitTimer - DeltaTime);

	if (ChangeHUDList.Num() == 0)
		return;

	const ETextType Top = ChangeHUDList.Top();
	const TMap<ETextType, float> Times = {
	    {ETextType::LIMIT_240, 240.0f},
	    {ETextType::LIMIT_180, 180.0f},
	    {ETextType::LIMIT_120, 120.0f},
	    {ETextType::LIMIT_60, 60.0f},
	};
	if (limitTimer <= Times[Top])
	{
		PlayerHUD->SpawnTextUI(Top);
		ChangeHUDList.Pop();
	}
}

void ALimitTimer::Init(float LimitTime)
{
	this->limitTime = LimitTime;
	this->limitTimer = LimitTime;

	AHUD* HUD = GetWorld()->GetFirstPlayerController()->GetHUD();
	PlayerHUD = Cast<APlayerHUD>(HUD);
	ChangeHUDList.Push(ETextType::LIMIT_60);
	ChangeHUDList.Push(ETextType::LIMIT_120);
	if (LimitTime > 180.0f + 0.1f)
	{
		ChangeHUDList.Push(ETextType::LIMIT_180);
	}
	if (LimitTime > 240.0f + 0.1f)
	{
		ChangeHUDList.Push(ETextType::LIMIT_240);
	}

	InitializeHUDText();
}
