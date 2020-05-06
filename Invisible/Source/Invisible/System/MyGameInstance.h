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
    * �V���b�g�_�E�����ɌĂ΂��
    */
	virtual void Shutdown() override;

	/**
    * ���s����Blueprint�̃R�[���X�^�b�N�����O�o�͂���
    */
	UFUNCTION(BlueprintCallable, Category = "Debug")
	static void PrintLogBlueprintCallstack();
	/**
    * �C���X�^���X�̎擾
    */
	UFUNCTION()
	static UMyGameInstance* GetInstance();
	/**
    * �T�E���h�V�X�e�����擾����
    */
	UFUNCTION(BlueprintCallable, Category = "Singleton")
	USoundSystem* getSoundSystem() const { return soundSystem; }

private:
	//!< OnHandleSystemError �f���Q�[�g�o�^���̃n���h��
	FDelegateHandle OnSystemErrorDelegateHandle;

	/**
    * �V�X�e���G���[���ɌĂ΂��֐�
    */
	void OnSystemError();

private:
	//!< �T�E���h�f�[�^�e�[�u��
	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	UDataTable* soundData;
    //!< ���ƂȂ鉹�I�u�W�F�N�g
	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	TSubclassOf<AActor> soundObjectOrigin;

private:
	//!< �T�E���h�V�X�e��
	UPROPERTY()
	USoundSystem* soundSystem;
};
