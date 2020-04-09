// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundSystem.h"

#include "Engine.h"
#include "Invisible/System/SoundObject.h"

namespace
{
	const FString PATH = "/Game/System/SoundObject_BP.SoundObject_BP_C";
}

//コンストラクタ
USoundSystem::USoundSystem()
{
}

//初期化
void USoundSystem::init(UDataTable* soundData)
{
	this->dataTable = soundData;

	//音オブジェクトの元をアセットから探す
	soundObjectOrigin = TSoftClassPtr<AActor>(FSoftObjectPath(*PATH)).LoadSynchronous();

	//見つからなかったらメッセージを表示する
	if (soundObjectOrigin == nullptr)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SoundObject_BP can't find"));
		return;
	}
	//後々の検索用にテーブルの行名を取得する
	soundTableRowNames = dataTable->GetRowNames();
}

//3D音源で再生する
void USoundSystem::play3DSound(ESoundType sound, const FVector& location)
{
	//音が有効かどうか調べる
	if (!isValid(sound))
		return;

	//再生する音データを取得する
	FSoundData* data = findSoundData(sound);

	AActor* spawned = GetWorld()->SpawnActor(soundObjectOrigin, &location);
	if (spawned == nullptr)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SoundObject_BP spawn failed"));
		return;
	}

	ASoundObject* soundObject = Cast<ASoundObject>(spawned);
	if (soundObject == nullptr)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Cast SoundObject component failed"));
		return;
	}

	soundObject->playSound(data);
}

//音データを取得する
FSoundData* USoundSystem::findSoundData(ESoundType sound) const
{
	//全データから対応する音を取得する
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
