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
	*	移動前後
	*/
	UFUNCTION()
	void moveForward(float value);
	// Handles input for moving right and left. (左右の移動の入力を処理)
	/*
	*	移動左右
	*/
	UFUNCTION()
	void moveRight(float value);
	/*
	*	回転
	*/
	UFUNCTION()
	void turn(float amount);
	/**
    * エネミーのアクションを実行する
    */
	UFUNCTION()
	void enemyAction();

private:
	UPROPERTY(EditAnywhere)
	float maxMoveSpeed = 500.0f; //!< 最大移動速度
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* actionArea; //!< アクション実行可能エリア
};
