// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundObject.h"

#include "Engine.h"
#include "Invisible/System/SoundSystem.h"

namespace
{
	const FString PATH = "/Game/System/SoundAttenuation.SoundAttenuation_C";
}

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
	isPlaying = false;
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
void ASoundObject::playSound(FSoundData* sound, const FVector& location, AActor* soundGenerateSource)
{
	//音があるかどうかチェックする
	if (!sound)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Sound data is null!"));
		return;
	}
	this->soundType = sound->soundType;
	this->soundGenerateSourceActor = soundGenerateSource;

	SetActorLocation(location);
	//音をセットして再生する
	audio->SetSound(sound->sound);
	audio->AttenuationSettings = sound->soundAttenuation;
	audio->Play();

	//コリジョンの半径を音の聞こえる範囲と同じようにセットする
	const USoundAttenuation* attenuation = sound->soundAttenuation;
	float radius = (attenuation->Attenuation.FalloffDistance + attenuation->Attenuation.AttenuationShapeExtents.Size());
	soundHeardArea->SetSphereRadius(radius, false);
	soundHeardArea->SetGenerateOverlapEvents(true);

	isPlaying = true;
}

//音の再生が終了したときのイベント
void ASoundObject::onAudioFinished()
{
	isPlaying = false;
	soundHeardArea->SetGenerateOverlapEvents(false);
}
