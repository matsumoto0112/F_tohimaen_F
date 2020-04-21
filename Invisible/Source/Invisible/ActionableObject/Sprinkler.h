// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"
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

public:
	//!< �X�v�����N���[�̃��b�V��
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* meshComponent;

	//!< �X�v�����N���[�̐��̃p�[�e�B�N��
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Particle")
	UParticleSystemComponent* particleComponent;
	//!< �p�[�e�B�N���̃G�~�b�^��
	//NOTE: �p�[�e�B�N���̃G�~�b�^�����x�^�ł��Ȃ̂ŉ��P�Ώ�
	const FName particleEmitterName = TEXT("Main");

	//!< �X�v�����N���[�̉ғ�����
	UPROPERTY(EditDefaultsOnly, Category = "Parameter")
	float activeTime = 5.0f;

    //!< �A�g����o���uID
	UPROPERTY(EditAnywhere, Category = "Parameter")
	int32 sprinklerID;

	//!< �����܂�̐ݒu�ꏊ
	UPROPERTY(EditAnywhere, Category = "Parameter")
	TArray<ATargetPoint*> puddlePoints;
private:
	//!< �X�v�����N���[�̉ғ��^�C�}�[�n���h��
	FTimerHandle timerHandle;
	//!< �����܂肪���łɐ������ꂽ���ǂ���
	bool puddleSpawned;
};
