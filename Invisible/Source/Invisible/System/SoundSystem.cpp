// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundSystem.h"

#include "Engine.h"
#include "Invisible/System/SoundObject.h"

//�R���X�g���N�^
USoundSystem::USoundSystem()
{
}

//������
void USoundSystem::init(UDataTable* soundData, TSubclassOf<AActor> origin)
{
	soundObjects = TArray<ASoundObject*>();
	this->dataTable = soundData;
	this->soundObjectOrigin = origin;
}

//3D�����ōĐ�����
void USoundSystem::play3DSound(ESoundType sound, const FVector& location, AActor* soundGenerateSource)
{
	//�����L�����ǂ������ׂ�
	if (!isValid(sound))
		return;

	//�Đ����鉹�f�[�^���擾����
	FSoundData* data = findSoundData(sound);

	//�g����T�E���h�I�u�W�F�N�g��T��
	for (int32 i = 0; i < soundObjects.Num(); i++)
	{
		if (soundObjects[i]->unused())
		{
			soundObjects[i]->playSound(data, location, soundGenerateSource);
			return;
		}
	}

	//�g����I�u�W�F�N�g���Ȃ�����
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Sound Object not available"));
	}
}

//�T�E���h�I�u�W�F�N�g�𐶐�����
void USoundSystem::createSoundObjects(int32 num)
{
	//���ƂȂ�T�E���h�I�u�W�F�N�g��������Ȃ������烁�b�Z�[�W��\������
	if (!soundObjectOrigin)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SoundObject_BP can't find"));
		return;
	}

	for (int32 i = 0; i < num; i++)
	{
		ASoundObject* spawned = GetWorld()->SpawnActor<ASoundObject>(soundObjectOrigin);
		soundObjects.Emplace(spawned);
	}
}

//�T�E���h�I�u�W�F�N�g��j������
void USoundSystem::destroySoundObjects()
{
	for (auto& obj : soundObjects)
	{
		obj->Destroy();
	}
	soundObjects.Empty();
}

//���f�[�^���擾����
FSoundData* USoundSystem::findSoundData(ESoundType sound) const
{
	FString contextString;
	//�S�f�[�^����Ή����鉹���擾����
	for (auto& name : dataTable->GetRowNames())
	{
		FSoundData* data = dataTable->FindRow<FSoundData>(name, contextString);
		if (data->soundType == sound)
		{
			return data;
		}
	}
	return nullptr;
}

//�����L�����ǂ������ׂ�
bool USoundSystem::isValid(ESoundType sound) const
{
	if (!dataTable)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("DataTable not found"));
		return false;
	}

	if (!soundObjectOrigin)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SoundObjectOrigin not found"));
		return false;
	}
	if (!findSoundData(sound))
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Data not found"));
		return false;
	}
	return true;
}
