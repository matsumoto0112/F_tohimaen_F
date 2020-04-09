// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"

#include "MyGameInstance.generated.h"

class USoundSystem;

/**
 * �Q�[���C���X�^���X
 */
UCLASS()
class INVISIBLE_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	UMyGameInstance();

public:
    /**
    * ������
    */
	virtual void Init() override;
    /**
    * �C���X�^���X�̎擾
    */
	UFUNCTION()
	static UMyGameInstance* GetInstance();
    /**
    * �T�E���h�V�X�e�����擾����
    */
	UFUNCTION()
	USoundSystem* getSoundSystem() const { return soundSystem; }

private:
    //!< �T�E���h�f�[�^�e�[�u��
	UPROPERTY(EditDefaultsOnly, Category = "Params")
	UDataTable* soundData;

private:
    //!< �T�E���h�V�X�e��
	USoundSystem* soundSystem;
};
