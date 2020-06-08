// Fill out your copyright notice in the Description page of Project Settings.

#include "ExitDevice.h"

#include "Engine.h"
#include "ExitItem.h"
#include "Invisible/System/MyGameInstance.h"

// Sets default values
AExitDevice::AExitDevice()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//メッシュコンポーネントを作成する
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = meshComponent;

	actionableArea = CreateDefaultSubobject<USphereComponent>(TEXT("ActionableArea"));
	actionableArea->InitSphereRadius(FMath::Abs(radius));
	actionableArea->SetCollisionProfileName("OverlapOnlyPawn");
	actionableArea->SetSimulatePhysics(false);
	actionableArea->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AExitDevice::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AExitDevice::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DeviceActionUpdate();
	actionableArea->SetSphereRadius(FMath::Abs(radius));
}

void AExitDevice::action_Implementation()
{
	if (IsGet())
	{
		DeviceAction();
	}
}

EActionType AExitDevice::GetActionType_Implementation() const
{
	if (UMyGameInstance::GetInstance()->getClear())
	{
		return EActionType::None;
	}
	if (IsGet())
	{
		return EActionType::Door_Open;
	}

	return EActionType::Door_Close;
}

void AExitDevice::DeviceAction_Implementation()
{
}

void AExitDevice::DeviceActionUpdate_Implementation()
{
}

bool AExitDevice::IsGet() const
{
	bool flag = true;
	for (int i = 0; i < items.Num(); i++)
	{
		if (!items[i]->IsGet())
		{
			flag = false;
		}
	}
	return flag;
}
