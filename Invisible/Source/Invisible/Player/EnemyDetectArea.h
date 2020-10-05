// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Invisible/Enemy/Enemy.h"

#include "EnemyDetectArea.generated.h"

/**
* �G�̏����i�[����\����
*/
USTRUCT()
struct INVISIBLE_API FEnemyDetect
{
	GENERATED_USTRUCT_BODY()

	//!< �G�A�N�^�[
	AEnemy* Enemy;
	//!< ���̓G�ɑ΂��Ă̌x���p�U�����������ǂ���
	bool bWarned;
};

/**
 * �G���m�͈͊Ǘ�
 */
UCLASS()
class INVISIBLE_API UEnemyDetectArea : public USphereComponent
{
	GENERATED_BODY()

public:
	UEnemyDetectArea();
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	/**
    * �G�����m���A�x�����o��
    */
	void DetectAndWarn();

private:
	/**
    * �R���|�[�l���g�������ƃI�[�o�[���b�v�������̃C�x���g
    */
	UFUNCTION()
	void BeginOverlapEvent(UPrimitiveComponent* HitComp,
	    AActor* OtherActor, UPrimitiveComponent* OtherComp,
	    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	/**
    * �R���|�[�l���g�������ƃI�[�o�[���b�v�������������̃C�x���g
    */
	UFUNCTION()
	void EndOverlapEvent(UPrimitiveComponent* OverlappedComponent,
	    AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	/**
    * �I�[�o�[���b�v�����A�N�^�[���G���ǂ������肷��
    */
	bool CheckOverlappingsActorIsEnemy(AActor* OtherActor, UPrimitiveComponent* OtherComp);
	/**
    * �G�ƃI�[�o�[���b�v����
    */
	void BeginOverlapEnemy(class AEnemy* Enemy);
	/**
    * �G�ƃI�[�o�[���b�v��������
    */
	void EndOverlapEnemy(class AEnemy* Enemy);

protected:
	//!< �U�����鎞��
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Duration = 1.5f;

private:
	//!< �R���g���[���̐U���n���h��
	FDynamicForceFeedbackHandle DynamicForceFeedbackHandle;
	//!< �G���
	TArray<FEnemyDetect> Enemies;
};
