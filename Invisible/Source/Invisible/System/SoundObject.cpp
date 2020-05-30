// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundObject.h"

#include "Engine.h"
#include "Invisible/System/SoundSystem.h"

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
void ASoundObject::PlaySound(FSoundData* SoundData, const FVector& Location, AActor* SoundGenerateSource, EPlayerHearingMode HearingMode)
{
	//�������邩�ǂ����`�F�b�N����
	if (!SoundData)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Sound data is null!"));
		return;
	}
	this->soundType = SoundData->SoundType;
	this->soundGenerateSourceActor = SoundGenerateSource;

    //�������͏�Ԃł���p�̌������ݒ肳��Ă���Ȃ炻����g�p����
	USoundAttenuation* SoundAttenuation = [](FSoundData* Data, EPlayerHearingMode Mode) {
		if (Mode == EPlayerHearingMode::High && Data->HighSoundAttenuation)
		{
			return Data->HighSoundAttenuation;
		}
		return Data->NormalSoundAttenuation;
	}(SoundData, HearingMode);

	SetActorLocation(Location);
	//�����Z�b�g���čĐ�����
	audio->SetSound(SoundData->SoundData);
	audio->AttenuationSettings = SoundAttenuation;
	audio->Play();

	//�R���W�����̔��a�����̕�������͈͂Ɠ����悤�ɃZ�b�g����
	float radius = (SoundAttenuation->Attenuation.FalloffDistance + SoundAttenuation->Attenuation.AttenuationShapeExtents.Size());
	soundHeardArea->SetSphereRadius(radius, false);
	soundHeardArea->SetGenerateOverlapEvents(true);
}

//�T�E���h���~����
void ASoundObject::Stop()
{
	this->audio->Stop();
}

//���̍Đ����I�������Ƃ��̃C�x���g
void ASoundObject::onAudioFinished()
{
	soundHeardArea->SetGenerateOverlapEvents(false);
}
