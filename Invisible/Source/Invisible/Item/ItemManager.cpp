// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemManager.h"

#include "Engine.h"
#include "ExitDevice.h"
#include "ExitItem.h"

#include <string>

// Sets default values
AItemManager::AItemManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AItemManager::BeginPlay()
{
	Super::BeginPlay();
	PopItem();
}

// Called every frame
void AItemManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AItemManager::PopItem()
{
	if ((items.Num() <= 0) || (popArray.Num() <= 0))
	{
		return;
	}

	auto indexArray = TArray<int>();
	for (int i = 0; i < popArray.Num(); i++)
	{
		indexArray.Add(i);
	}
	indexArray.Sort([](int a, int b) { return FMath::FRandRange(0.0f, 100.0f) <= FMath::FRandRange(0.0f, 100.0f); });

	for (int i = 0; i < items.Num(); i++)
	{
		if (indexArray.Num() <= i)
		{
			break;
		}
		auto s = std::to_string(i) + " >> " + std::to_string(indexArray[i]);
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::FString(s.c_str()));
		items[i]->SetActorLocation(popArray[indexArray[i]]);
	}
}

int32 AItemManager::GetItemCount() const
{
	int count = 0;
	for (int32 i = 0; i < items.Num(); i++)
	{
		if ((items[i]->IsGet()) && (!items[i]->IsUse()))
		{
			if (items[i]->IsItemAction())
			{
				count++;
			}
		}
	}

	return count;
}

int32 AItemManager::AllItemCount() const
{
	int count = 0;
	for (int32 i = 0; i < items.Num(); i++)
	{
		if (items[i]->IsItemAction())
		{
			count++;
		}
	}

	return count;
}

FString AItemManager::ItemCountView() const
{
	auto count = std::to_string(GetItemCount());
	auto allCount = std::to_string(AllItemCount());
	auto result = count + " / " + allCount;
	return FString::FString(result.c_str());
}
