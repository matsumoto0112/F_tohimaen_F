// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"

#include "Engine.h"
#include "Invisible/System/SoundSystem.h"

//コンストラクタ
UMyGameInstance::UMyGameInstance()
{
}

void UMyGameInstance::PrintLogBlueprintCallstack()
{
    FString Callstack = FFrame::GetScriptCallstack();

    UE_LOG(LogTemp, Error, TEXT("--------------------------------------"));
    UE_LOG(LogTemp, Error, TEXT(" Blueprint Callstack:\n%s"), *Callstack);
    UE_LOG(LogTemp, Error, TEXT("--------------------------------------"));
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

void UMyGameInstance::OnSystemError()
{
    PrintLogBlueprintCallstack();
}

//初期化
void UMyGameInstance::Init()
{
	Super::Init();
	OnSystemErrorDelegateHandle = FCoreDelegates::OnHandleSystemError.AddUObject(this, &UMyGameInstance::OnSystemError);

	if (soundSystem == nullptr)
	{
		soundSystem = NewObject<USoundSystem>();
		//サウンドシステムのワールドを再設定するのに必要
		soundSystem->Rename(nullptr, this);
	}
	soundSystem->init(soundData);
}

void UMyGameInstance::Shutdown()
{
    FCoreDelegates::OnHandleSystemError.Remove(OnSystemErrorDelegateHandle);
    Super::Shutdown();
}
