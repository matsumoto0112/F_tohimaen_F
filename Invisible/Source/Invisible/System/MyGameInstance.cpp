// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"

#include "Engine.h"
#include "Invisible/System/SoundSystem.h"

//コンストラクタ
UMyGameInstance::UMyGameInstance()
{
}

//インスタンスの取得
UMyGameInstance* UMyGameInstance::GetInstance()
{
	if (GEngine)
	{
		FWorldContext* context = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport);
		UMyGameInstance* instance = Cast<UMyGameInstance>(context->OwningGameInstance);
		return instance;
	}

	return nullptr;
}

//初期化
void UMyGameInstance::Init()
{
	if (soundSystem == nullptr)
	{
		soundSystem = NewObject<USoundSystem>();
		//サウンドシステムのワールドを再設定するのに必要
		soundSystem->Rename(nullptr, this);
	}
	soundSystem->init(soundData);
}
