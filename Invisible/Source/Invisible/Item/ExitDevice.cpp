// Fill out your copyright notice in the Description page of Project Settings.


#include "ExitDevice.h"
#include "ExitItem.h"

// Sets default values
AExitDevice::AExitDevice()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//メッシュコンポーネントを作成する
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = meshComponent;

	actionableArea = CreateDefaultSubobject<USphereComponent>(TEXT("ActionableArea"));
	actionableArea->InitSphereRadius(50.0f);
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

}

void AExitDevice::Action()
{
	if (IsGet())
	{
		DeviceAction();
	}
}

void AExitDevice::action_Implementation()
{
	if (IsGet())
	{
		Action();
	}
}

bool AExitDevice::IsGet()
{
	bool flag = true;
	for (int i = 0;i < items.Num(); i++)
	{
		if (!items[i]->IsGet())
		{
			flag = false;
		}
	}
	return flag;
}

