// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "Invisible/System/ConfigParams.h"
#include "Invisible/System/ControllerVibration.h"

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
	USoundSystem* getSoundSystem() const { return SoundSystem; }

	UFUNCTION(BlueprintCallable, Category = "Singleton")
	UConfigParams* GetConfigParams() const { return ConfigParams; }
	UFUNCTION(BlueprintCallable, Category = "Singleton")
	UControllerVibration* GetControllerVibration() const { return ControllerVibration; }

	UFUNCTION(BluePrintCallable, Category = "Clear")
	void setClear(bool clear) { isClear = clear; }
	UFUNCTION(BluePrintCallable, Category = "Clear")
	bool getClear() { return isClear; }

private:
	//!< OnHandleSystemError �f���Q�[�g�o�^���̃n���h��
	FDelegateHandle OnSystemErrorDelegateHandle;

	bool isClear = false;

	/**
    * �V�X�e���G���[���ɌĂ΂��֐�
    */
	void OnSystemError();

private:
	//!< �T�E���h�f�[�^�e�[�u��
	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	UDataTable* SoundDataTable;
	//!< ���ƂȂ鉹�I�u�W�F�N�g
	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	TSubclassOf<AActor> SoundObjectOrigin;

protected:
	//!< �T�E���h�V�X�e��
	UPROPERTY(VisibleAnywhere)
	USoundSystem* SoundSystem;
	UPROPERTY(VisibleAnywhere)
	UConfigParams* ConfigParams;
	UPROPERTY(VisibleAnywhere)
	UControllerVibration* ControllerVibration;
};
