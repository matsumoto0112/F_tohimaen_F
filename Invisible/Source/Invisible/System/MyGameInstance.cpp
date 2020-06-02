// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"

#include "Engine.h"
#include "Invisible/System/ConfigParams.h"
#include "Invisible/System/SoundSystem.h"

//コンストラクタ
UMyGameInstance::UMyGameInstance()
{
	SoundSystem = CreateDefaultSubobject<USoundSystem>(TEXT("Sound"));
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

	SoundSystem->init(SoundDataTable, SoundObjectOrigin);

	ConfigParams = Cast<UConfigParams>(UGameplayStatics::CreateSaveGameObject(UConfigParams::StaticClass()));
	UConfigParams* Load = Cast<UConfigParams>(UGameplayStatics::LoadGameFromSlot(ConfigParams->SaveSlotName, ConfigParams->UserIndex));

	if (Load)
	{
		ConfigParams = Load;
	}
	else
	{
		ConfigParams->SetDefault();
	}
}

void UMyGameInstance::Shutdown()
{
	FCoreDelegates::OnHandleSystemError.Remove(OnSystemErrorDelegateHandle);
	Super::Shutdown();
}
