// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundObject.h"

#include "Engine.h"
#include "Invisible/System/SoundSystem.h"

ASoundObject::ASoundObject()
{
	PrimaryActorTick.bCanEverTick = true;

	//音の聞こえる範囲用のコリジョンを作成する
	soundHeardArea = CreateDefaultSubobject<USphereComponent>(TEXT("SoundHeardArea"));
	RootComponent = soundHeardArea;
	soundHeardArea->InitSphereRadius(100.0f);
	soundHeardArea->SetSimulatePhysics(false);
	soundHeardArea->SetCollisionProfileName("OverlapAllDynamic");
	soundHeardArea->SetGenerateOverlapEvents(false);

	audio = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	audio->SetupAttachment(this->RootComponent);
	audio->OnAudioFinished.AddDynamic(this, &ASoundObject::onAudioFinished);
}

void ASoundObject::BeginPlay()
{
	Super::BeginPlay();
}

void ASoundObject::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ASoundObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//音を再生する
void ASoundObject::PlaySound(FSoundData* SoundData, const FVector& Location, AActor* SoundGenerateSource, EPlayerHearingMode HearingMode)
{
	//音があるかどうかチェックする
	if (!SoundData)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Sound data is null!"));
		return;
	}
	this->soundType = SoundData->SoundType;
	this->soundGenerateSourceActor = SoundGenerateSource;

    //高い聴力状態でそれ用の減衰が設定されているならそれを使用する
	USoundAttenuation* SoundAttenuation = [](FSoundData* Data, EPlayerHearingMode Mode) {
		if (Mode == EPlayerHearingMode::High && Data->HighSoundAttenuation)
		{
			return Data->HighSoundAttenuation;
		}
		return Data->NormalSoundAttenuation;
	}(SoundData, HearingMode);

	SetActorLocation(Location);
	//音をセットして再生する
	audio->SetSound(SoundData->SoundData);
	audio->AttenuationSettings = SoundAttenuation;
	audio->Play();

	//コリジョンの半径を音の聞こえる範囲と同じようにセットする
	float radius = (SoundAttenuation->Attenuation.FalloffDistance + SoundAttenuation->Attenuation.AttenuationShapeExtents.Size());
	soundHeardArea->SetSphereRadius(radius, false);
	soundHeardArea->SetGenerateOverlapEvents(true);
}

//サウンドを停止する
void ASoundObject::Stop()
{
	this->audio->Stop();
}

//音の再生が終了したときのイベント
void ASoundObject::onAudioFinished()
{
	soundHeardArea->SetGenerateOverlapEvents(false);
}
