// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundSystem.h"

#include "Engine.h"
#include "Invisible/System/SoundObject.h"

namespace
{
	const FString PATH = "/Game/System/SoundObject_BP.SoundObject_BP_C";
}

USoundSystem::USoundSystem()
{
}

void USoundSystem::init(UDataTable* soundData, USoundAttenuation* soundAttenuation)
{
	this->dataTable = soundData;
	this->attenuation = soundAttenuation;

	soundObjectOrigin = TSoftClassPtr<AActor>(FSoftObjectPath(*PATH)).LoadSynchronous();
	if (soundObjectOrigin == nullptr)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SoundObject_BP can't find"));
		}
		return;
	}

	soundTableRowNames = dataTable->GetRowNames();
}

void USoundSystem::play3DSound(ESoundType sound, const FVector& location)
{
	if (!isValid(sound))
		return;

	FSoundData* data = findSoundData(sound);
	AActor* spawned = GetWorld()->SpawnActor(soundObjectOrigin, &location);
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

	soundObject->playSound(data->sound, attenuation);
}

FSoundData* USoundSystem::findSoundData(ESoundType sound) const
{
	for (auto name : soundTableRowNames)
	{
		FSoundData* data = dataTable->FindRow<FSoundData>(name, FString());
		if (data->soundType == sound)
		{
			return data;
		}
	}
	return nullptr;
}

bool USoundSystem::isValid(ESoundType sound) const
{
	if (!dataTable)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("DataTable not found"));
		return false;
	}
	if (!attenuation)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Attenuation not found"));
		return false;
	}
	if (!soundObjectOrigin)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SoundObjectOrigin not found"));
		return false;
	}
	if (!findSoundData(sound))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Data not found"));
		return false;
	}
	return true;
}
