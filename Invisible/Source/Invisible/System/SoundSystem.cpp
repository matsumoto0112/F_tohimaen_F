// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundSystem.h"

#include "Engine.h"
#include "Invisible/System/SoundObject.h"

namespace
{
	const FString PATH = "/Game/System/SoundObject_BP.SoundObject_BP_C";
}

//�R���X�g���N�^
USoundSystem::USoundSystem()
{
}

//������
void USoundSystem::init(UDataTable* soundData)
{
	this->dataTable = soundData;

	//���I�u�W�F�N�g�̌����A�Z�b�g����T��
	soundObjectOrigin = TSoftClassPtr<AActor>(FSoftObjectPath(*PATH)).LoadSynchronous();

	//������Ȃ������烁�b�Z�[�W��\������
	if (soundObjectOrigin == nullptr)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SoundObject_BP can't find"));
		return;
	}
	//��X�̌����p�Ƀe�[�u���̍s�����擾����
	soundTableRowNames = dataTable->GetRowNames();
}

//3D�����ōĐ�����
void USoundSystem::play3DSound(ESoundType sound, const FVector& location)
{
	//�����L�����ǂ������ׂ�
	if (!isValid(sound))
		return;

	//�Đ����鉹�f�[�^���擾����
	FSoundData* data = findSoundData(sound);

	AActor* spawned = GetWorld()->SpawnActor(soundObjectOrigin, &location);
	if (spawned == nullptr)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SoundObject_BP spawn failed"));
		return;
	}

	ASoundObject* soundObject = Cast<ASoundObject>(spawned);
	if (soundObject == nullptr)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Cast SoundObject component failed"));
		return;
	}

	soundObject->playSound(data);
}

//���f�[�^���擾����
FSoundData* USoundSystem::findSoundData(ESoundType sound) const
{
	//�S�f�[�^����Ή����鉹���擾����
	for (auto name : soundTableRowNames)
	{
		FSoundData* data = dataTable->FindRow<FSoundData>(name, FString());
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
