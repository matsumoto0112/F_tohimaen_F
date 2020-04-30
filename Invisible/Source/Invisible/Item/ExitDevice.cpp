// Fill out your copyright notice in the Description page of Project Settings.


#include "ExitDevice.h"

// Sets default values
AExitDevice::AExitDevice()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//メッシュコンポーネントを作成する
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = meshComponent;
}

// Called when the game starts or when spawned
void AExitDevice::BeginPlay()
{
	Super::BeginPlay();
	
}

//// Called every frame
//void AExitDevice::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

//void AExitDevice::AddItem(AExitItem* item)
//{
//	if (!items.Contains(item))
//	{
//		items.Add(item);
//	}
//}

void AExitDevice::Action()
{
	if (IsGet())
	{
		DeviceAction();
	}
}

bool AExitDevice::IsGet()
{
	bool flag = true;
	//for (int i = 0;i < items.Num(); i++)
	//{
	//	if (!items[i]->IsGet())
	//	{
	//		flag = false;
	//	}
	//}
	return flag;
}

