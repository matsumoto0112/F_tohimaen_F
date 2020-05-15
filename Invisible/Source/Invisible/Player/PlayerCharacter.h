// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Invisible/Player/EnemyDetectArea.h"

#include "PlayerCharacter.generated.h"

class ASoundObject;

/**
* �v���C���[�L�����N�^�[
*/
UCLASS()
class INVISIBLE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	/**
    * �R���X�g���N�^
    */
	APlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/**
    * �G���甭�����鉹�𕷂���
    */
	UFUNCTION(BlueprintNativeEvent, Category = "Sound")
	void heardEnemySound(AActor* enemy);
	virtual void heardEnemySound_Implementation(AActor* enemy) {}

private:
	/**
    * �O�����ւ̈ړ�����
    */
	UFUNCTION()
	void moveForward(float value);
	/**
    * �E�����ւ̈ړ�����
    */
	UFUNCTION()
	void moveRight(float value);
	/**
    * �J�����̉������̉�]����
    */
	UFUNCTION()
	void turn(float amount);
	/**
    * �J�����̏㉺�����̉�]����
    */
	UFUNCTION()
	void lookup(float amount);
	/**
    * �v���C���[�̃A�N�V���������s����
    */
	UFUNCTION()
	void playerAction();
	/**
    * �����ɏՓ˂������ɌĂ΂��
    */
	UFUNCTION()
	void onComponentBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor,
	    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	/**
    * ������������
    */
	void heardSound(ASoundObject* soundObject);
	/**
    * ���s���̍Đ�����
    */
	void playWalkSound(float deltaTime);
	/**
    * �v���C���[�J�����̏㉺�����ɉ�]������������
    */
	void clampPlayerCameraPitchRotation();

	/**
    * �Q�[���I�ȃC�x���g���n�܂���
    */
	UFUNCTION(BlueprintCallable, Category = "Player")
	void StartedGameEvent();

private:
	//!< �ő�ړ����x
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	float maxMoveSpeed = 500.0f;

protected:
	//!< ��]�W��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float RotateCoef = 100.0f;
	//!< �J�����̏㉺�����̉�]�����i�����j
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float MinCameraPitch = -45.0f;
	//!< �J�����̏㉺�����̉�]�����i����j
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float MaxCameraPitch = 45.0f;

	//!< �����Ă���Ɣ��f�����ړ���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float WalkingThreshold = 0.5f;
	//!< ���s���̍Đ��Ԋu
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float WalkingSoundPlayInterval = 0.5f;

public:
	//!< �v���C���[�J����
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UCameraComponent* CameraComponent;
	//!< �A�N�V�������s�\�G���A
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UBoxComponent* ActionArea;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UEnemyDetectArea* EnemyDetectArea;

private:
	//!< �������Ă��邩
	bool bIsWalking;
	//!< �����Ă��鎞��(�b)
	float WalkingSecond;
	//!< ���C�g���[�X�p�N�G���p�����[�^
	FCollisionQueryParams param;
};
