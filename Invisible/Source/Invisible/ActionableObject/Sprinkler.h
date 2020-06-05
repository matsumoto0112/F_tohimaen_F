// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"
#include "Invisible/System/SoundSystem.h"
#include "Particles/ParticleSystemComponent.h"

#include "Sprinkler.generated.h"

/**
* �X�v�����N���[�I�u�W�F�N�g
*/
UCLASS()
class INVISIBLE_API ASprinkler : public AActor, public IActionable
{
	GENERATED_BODY()

public:
	/**
    * �R���X�g���N�^
    */
	ASprinkler();

protected:
	/**
    * �Q�[���J�n���ɌĂ΂��
    */
	virtual void BeginPlay() override;
	/**
    * �Q�[���I�����ɌĂ΂��
    */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	/**
    * �X�v�����N���[�𓮍삳����
    */
	virtual void action_Implementation() override;

	virtual EActionType GetActionType_Implementation() const override { return EActionType::None; }

public:
	/**
    * ���t���[���Ă΂��
    */
	virtual void Tick(float DeltaTime) override;

public:
	/**
    * �X�v�����N���[ID���擾����
    */
	inline int32 GetSprinklerID() const
	{
		return sprinklerID;
	}

protected:
	//!< �A�g����o���uID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	int32 sprinklerID;
	//!< �X�v�����N���[�̉ғ�����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	float activeTime = 5.0f;

	//!< �����܂�̐ݒu�ꏊ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	TArray<ATargetPoint*> puddlePoints;
	//!< �Đ����鉹�̎��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	ESoundType SoundType = ESoundType::Sprinkler_Ver0;

public:
	//!< �X�v�����N���[�̃��b�V��
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMeshComponent* meshComponent;

	//!< �X�v�����N���[�̐��̃p�[�e�B�N��
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UParticleSystemComponent* particleComponent;

	//!< ����������͈�
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UBoxComponent* wetArea;

private:
	//!< �p�[�e�B�N���̃G�~�b�^��
	const FName particleEmitterName = TEXT("Main");

private:
	//!< �X�v�����N���[�̉ғ��^�C�}�[�n���h��
	FTimerHandle timerHandle;
	//!< �����܂肪���łɐ������ꂽ���ǂ���
	bool puddleSpawned;
};
