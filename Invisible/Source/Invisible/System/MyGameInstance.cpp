// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"

#include "Engine.h"
#include "Invisible/System/SoundSystem.h"

//�R���X�g���N�^
UMyGameInstance::UMyGameInstance()
{
}

//�C���X�^���X�̎擾
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

//������
void UMyGameInstance::Init()
{
	if (soundSystem == nullptr)
	{
		soundSystem = NewObject<USoundSystem>();
		//�T�E���h�V�X�e���̃��[���h���Đݒ肷��̂ɕK�v
		soundSystem->Rename(nullptr, this);
	}
	soundSystem->init(soundData);
}
