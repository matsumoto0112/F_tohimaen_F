// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"

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

private:
	//!< �ő�ړ����x
	UPROPERTY(EditAnywhere)
	float maxMoveSpeed = 500.0f;
	//!< �}�E�X���x
	UPROPERTY(EditAnywhere)
	float mouseSensitivity = 100.0f;
	//!< �v���C���[�J����
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* cameraComponent;
	//!< �A�N�V�������s�\�G���A
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* actionArea;
};
