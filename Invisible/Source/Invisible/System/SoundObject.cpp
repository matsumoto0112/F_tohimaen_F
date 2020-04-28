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

	//���̕�������͈͗p�̃R���W�������쐬����
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

//�����Đ�����
void ASoundObject::playSound(FSoundData* sound, const FVector& location, AActor* soundGenerateSource)
{
	//�������邩�ǂ����`�F�b�N����
	if (!sound)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Sound data is null!"));
		return;
	}
	this->soundType = sound->soundType;
	this->soundGenerateSourceActor = soundGenerateSource;

	SetActorLocation(location);
	//�����Z�b�g���čĐ�����
	audio->SetSound(sound->sound);
	audio->AttenuationSettings = sound->soundAttenuation;
	audio->Play();

	//�R���W�����̔��a�����̕�������͈͂Ɠ����悤�ɃZ�b�g����
	const USoundAttenuation* attenuation = sound->soundAttenuation;
	float radius = (attenuation->Attenuation.FalloffDistance + attenuation->Attenuation.AttenuationShapeExtents.Size());
	soundHeardArea->SetSphereRadius(radius, false);
	soundHeardArea->SetGenerateOverlapEvents(true);

	isPlaying = true;
}

//���̍Đ����I�������Ƃ��̃C�x���g
void ASoundObject::onAudioFinished()
{
	isPlaying = false;
	soundHeardArea->SetGenerateOverlapEvents(false);
}
