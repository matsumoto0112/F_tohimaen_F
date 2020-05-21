// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemManager.h"

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
}

// Called every frame
void AItemManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int32 AItemManager::GetItemCount() const
{
	int count = 0;
	for (int32 i = 0; i < items.Num(); i++)
	{
		if (items[i]->IsGet() && !items[i]->IsUse())
		{
			count++;
		}
	}

	return count;
}

int32 AItemManager::AllItemCount() const
{
	return items.Num();
}

FString AItemManager::ItemCountView() const
{
	auto count = std::to_string(GetItemCount());
	auto allCount = std::to_string(AllItemCount());
	auto result = count +" / "+ allCount;
	return FString::FString(result.c_str());
}
