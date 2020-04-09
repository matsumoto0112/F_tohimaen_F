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

//�����Đ�����
void ASoundObject::playSound(FSoundData* sound)
{
	//�������邩�ǂ����`�F�b�N����
	if (!sound)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Sound data is null!"));
		return;
	}
	this->soundType = sound->soundType;

    //�����Đ�����
    UAudioComponent* audioComponent = UGameplayStatics::SpawnSoundAttached(sound->sound, this->RootComponent,
        NAME_None, FVector::ZeroVector, EAttachLocation::Type::KeepRelativeOffset, false, 1.0f, 1.0f, 0.0f, sound->soundAttenuation);
    //�Đ��I�����̃C�x���g���Z�b�g����
    audioComponent->OnAudioFinished.AddDynamic(this, &ASoundObject::onAudioFinished);

    //�R���W�����̔��a�����̕�������͈͂Ɠ����悤�ɃZ�b�g����
	const USoundAttenuation* attenuation = sound->soundAttenuation;
	float radius = (attenuation->Attenuation.FalloffDistance + attenuation->Attenuation.AttenuationShapeExtents.Size());
	soundHeardArea->SetSphereRadius(radius);
}

//���̍Đ����I�������Ƃ��̃C�x���g
void ASoundObject::onAudioFinished()
{
	this->Destroy();
}
