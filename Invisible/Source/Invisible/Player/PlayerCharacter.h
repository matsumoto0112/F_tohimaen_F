// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class UCameraComponent;

UCLASS()
class INVISIBLE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
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

private:
	UPROPERTY(EditAnywhere)
	float maxMoveSpeed = 500.0f; //!< �ő�ړ����x
	UPROPERTY(EditAnywhere)
	float mouseSensitivity = 100.0f; //!< �}�E�X���x
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* cameraComponent; //!< �v���C���[�J����
};
