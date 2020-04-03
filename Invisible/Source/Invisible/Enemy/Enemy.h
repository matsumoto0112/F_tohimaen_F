// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

class UBoxComponent;

UCLASS()
class INVISIBLE_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*
	*	�ړ��O��
	*/
	UFUNCTION()
	void moveForward(float value);
	// Handles input for moving right and left. (���E�̈ړ��̓��͂�����)
	/*
	*	�ړ����E
	*/
	UFUNCTION()
	void moveRight(float value);
	/*
	*	��]
	*/
	UFUNCTION()
	void turn(float amount);
	/**
    * �G�l�~�[�̃A�N�V���������s����
    */
	UFUNCTION()
	void enemyAction();

private:
	UPROPERTY(EditAnywhere)
	float maxMoveSpeed = 500.0f; //!< �ő�ړ����x
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* actionArea; //!< �A�N�V�������s�\�G���A
};
