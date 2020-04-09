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
	soundHeardArea->InitSphereRadius(100.0f);
	soundHeardArea->SetupAttachment(this->RootComponent);
	soundHeardArea->SetSimulatePhysics(false);
	soundHeardArea->SetCollisionProfileName("OverlapOnlyPawn");
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
void ASoundObject::playSound(FSoundData* sound)
{
	//音があるかどうかチェックする
	if (!sound)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Sound data is null!"));
		return;
	}
	this->soundType = sound->soundType;

    //音を再生する
    UAudioComponent* audioComponent = UGameplayStatics::SpawnSoundAttached(sound->sound, this->RootComponent,
        NAME_None, FVector::ZeroVector, EAttachLocation::Type::KeepRelativeOffset, false, 1.0f, 1.0f, 0.0f, sound->soundAttenuation);
    //再生終了時のイベントをセットする
    audioComponent->OnAudioFinished.AddDynamic(this, &ASoundObject::onAudioFinished);

    //コリジョンの半径を音の聞こえる範囲と同じようにセットする
	const USoundAttenuation* attenuation = sound->soundAttenuation;
	float radius = (attenuation->Attenuation.FalloffDistance + attenuation->Attenuation.AttenuationShapeExtents.Size());
	soundHeardArea->SetSphereRadius(radius);
}

//音の再生が終了したときのイベント
void ASoundObject::onAudioFinished()
{
	this->Destroy();
}
