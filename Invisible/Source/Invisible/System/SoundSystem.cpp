// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundSystem.h"

#include "Engine.h"
#include "Invisible/System/SoundObject.h"

namespace
{
	const FString PATH = "/Game/System/SoundObject_BP.SoundObject_BP_C";
}

// Sets default values
ASoundSystem::ASoundSystem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASoundSystem::BeginPlay()
{
	Super::BeginPlay();
	soundObjectOrigin = TSoftClassPtr<AActor>(FSoftObjectPath(*PATH)).LoadSynchronous();
	if (soundObjectOrigin == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SoundObject_BP can't find"));
		return;
	}

	auto dt = dataTable->FindRow<FSoundData>(TEXT("0"), FString());
	if (dt != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("find"));
	}
}

// Called every frame
void ASoundSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	static int Counter = 0;
	Counter++;
	if (Counter % 300 == 0)
	{
		if (soundObjectOrigin == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SoundObject_BP can't find"));
			return;
		}
		FRandomStream rnd;
		FVector locate = FVector(rnd.FRandRange(-4000.0f, 4000.0f), rnd.FRandRange(-4000.0f, 4000.0f), 0.0f);
		AActor* spawned = GetWorld()->SpawnActor(soundObjectOrigin, &locate);
		if (spawned == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SoundObject_BP spawn failed"));
			return;
		}
		ASoundObject* soundObject = Cast<ASoundObject>(spawned);
		if (soundObject == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Cast SoundObject component is failed"));
			return;
		}
		//soundObject->playSound(doorOpen, soundAttenuation);

		const TArray<FName> names = dataTable->GetRowNames();
		for (auto name : names)
		{
			FSoundData* data = dataTable->FindRow<FSoundData>(name, FString());
			if (data->soundType == ESoundType::Valve)
			{
				soundObject->playSound(data->sound, soundAttenuation);
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Spawn SoundObject is completed"));
			}
		}
	}
}
