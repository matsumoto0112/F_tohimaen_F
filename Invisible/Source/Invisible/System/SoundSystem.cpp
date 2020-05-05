// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundSystem.h"

#include "Engine.h"
#include "Invisible/System/SoundObject.h"

namespace
{
	static const FString PATH = "/Game/System/SoundObject_BP.SoundObject_BP_C";
	constexpr int32 SOUND_OBJECT_NUM = 50;
}

//コンストラクタ
USoundSystem::USoundSystem()
{
}

//初期化
void USoundSystem::init(UDataTable* soundData)
{
	soundObjects = TArray<ASoundObject*>();
	this->dataTable = soundData;

	//音オブジェクトの元をアセットから探す
	soundObjectOrigin = TSoftClassPtr<AActor>(FSoftObjectPath(*PATH)).LoadSynchronous();
}

//3D音源で再生する
void USoundSystem::play3DSound(ESoundType sound, const FVector& location, AActor* soundGenerateSource)
{
	//音が有効かどうか調べる
	if (!isValid(sound))
		return;

	//再生する音データを取得する
	FSoundData* data = findSoundData(sound);

	if (!soundObjectOrigin)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SoundObject_BP can't find"));
		return;
	}

	//使えるサウンドオブジェクトを探す
	for (int32 i = 0; i < soundObjects.Num(); i++)
	{
		if (soundObjects[i]->unused())
		{
			soundObjects[i]->playSound(data, location, soundGenerateSource);
			return;
		}
	}
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Sound Object not available"));
	}
}

void USoundSystem::createSoundObjects(int32 num)
{
	//見つからなかったらメッセージを表示する
	if (soundObjectOrigin == nullptr)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SoundObject_BP can't find"));
		return;
	}

	for (int32 i = 0; i < num; i++)
	{
		ASoundObject* spawned = GetWorld()->SpawnActor<ASoundObject>(soundObjectOrigin);
		soundObjects.Emplace(spawned);
	}
}

void USoundSystem::destroySoundObjects()
{
	for (auto& obj : soundObjects)
	{
		obj->Destroy();
	}
	soundObjects.Empty();
}

//音データを取得する
FSoundData* USoundSystem::findSoundData(ESoundType sound) const
{
	FString contextString;
	//全データから対応する音を取得する
	for (auto& name : dataTable->GetRowNames())
	{
		FSoundData* data = dataTable->FindRow<FSoundData>(name, contextString);
		if (data->soundType == sound)
		{
			return data;
		}
	}
	return nullptr;
}

//音が有効かどうか調べる
bool USoundSystem::isValid(ESoundType sound) const
{
	if (!dataTable)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("DataTable not found"));
		return false;
	}

	if (!soundObjectOrigin)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SoundObjectOrigin not found"));
		return false;
	}
	if (!findSoundData(sound))
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Data not found"));
		return false;
	}
	return true;
}
