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
* プレイヤーキャラクター
*/
UCLASS()
class INVISIBLE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	/**
    * コンストラクタ
    */
	APlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/**
    * 敵から発せられる音を聞いた
    */
	UFUNCTION(BlueprintNativeEvent, Category = "Sound")
	void heardEnemySound(AActor* enemy);
	virtual void heardEnemySound_Implementation(AActor* enemy) {}

private:
	/**
    * 前方向への移動処理
    */
	UFUNCTION()
	void moveForward(float value);
	/**
    * 右方向への移動処理
    */
	UFUNCTION()
	void moveRight(float value);
	/**
    * カメラの横方向の回転処理
    */
	UFUNCTION()
	void turn(float amount);
	/**
    * カメラの上下方向の回転処理
    */
	UFUNCTION()
	void lookup(float amount);
	/**
    * プレイヤーのアクションを実行する
    */
	UFUNCTION()
	void playerAction();
	/**
    * 何かに衝突した時に呼ばれる
    */
	UFUNCTION()
	void onComponentBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor,
	    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	/**
    * 音が聞こえた
    */
	void heardSound(ASoundObject* soundObject);
	/**
    * 歩行音の再生処理
    */
	void playWalkSound(float deltaTime);
	/**
    * プレイヤーカメラの上下方向に回転制限をかける
    */
	void clampPlayerCameraPitchRotation();

private:
	//!< 最大移動速度
	UPROPERTY(EditDefaultsOnly, Category = "Parameter")
	float maxMoveSpeed = 500.0f;

protected:
	//!< マウス感度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	float mouseSensitivity = 100.0f;
	//!< カメラの上下方向の回転制限（下限）
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	float minCameraPitch = -45.0f;
	//!< カメラの上下方向の回転制限（上限）
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	float maxCameraPitch = 45.0f;
	//!< 歩いていると判断される移動量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	float walkingThreshold = 0.5f;
	//!< 歩行音の再生間隔
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	float walkingSoundPlayInterval = 0.5f;

public:
	//!< プレイヤーカメラ
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UCameraComponent* CameraComponent;
	//!< アクション実行可能エリア
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UBoxComponent* ActionArea;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UEnemyDetectArea* EnemyDetectArea;

private:
	//!< 今歩いているか
	bool isWalking;
	//!< 歩いている時間(秒)
	float walkingSecond;
	FCollisionQueryParams param;
};
