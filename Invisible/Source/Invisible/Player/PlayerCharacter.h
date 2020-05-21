// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Invisible/Player/EnemyDetectArea.h"
#include "Invisible/Player/PlayerActionMode.h"

#include "PlayerCharacter.generated.h"

class ASoundObject;
class ALocker;

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
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/**
    * 敵から発せられる音を聞いた
    */
	UFUNCTION(Category = "Sound")
	void HeardEnemyWalkOnPuddleSound(AEnemy* enemy);
	/**
    * 現在のアクションモードを取得する
    */
	UFUNCTION(BlueprintCallable, Category = "Player")
	EPlayerActionMode GetCurrentActionMode() const { return CurrentActionMode; }

	void IntoLocker(ALocker* Locker, const FVector& Location, const FRotator& FrontRotator);

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
    void ClampPlayerCameraPitchRotation();
    /**
    * プレイヤーカメラの左右方向に回転制限をかける
    */
    void ClampPlayerCameraYawRotation();

	/**
    * 死亡する
    */
	UFUNCTION(BlueprintCallable, Category = "Player")
	void ToDie();

	UFUNCTION()
	void InputedActionCommand();
	void DoActionNearObject();
	void GetOutLocker();

private:
	//!< 最大移動速度
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	float maxMoveSpeed = 500.0f;

protected:
	//!< 回転係数
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float RotateCoef = 100.0f;
	//!< カメラの上下方向の回転制限（下限）
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float MinCameraPitch = -45.0f;
	//!< カメラの上下方向の回転制限（上限）
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float MaxCameraPitch = 45.0f;

	//!< 歩いていると判断される移動量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float WalkingThreshold = 0.5f;
	//!< 歩行音の再生間隔
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float WalkingSoundPlayInterval = 0.5f;
	//!< 敵が水たまりを踏んだ時に見えている時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float EnemyVisibleTimeWhenEnemyWalkOnPuddle = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locker")
	float WaitTimeToGoingIntoLocker = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locker")
	float WaitTimeToGetOutLocker = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locker")
	float MinCameraPitchWhenIsInLocker = -5.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locker")
	float MaxCameraPitchWhenIsInLocker = 5.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locker")
	float MinCameraYawWhenIsInLocker = -3.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locker")
	float MaxCameraYawWhenIsInLocker = 3.0f;

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
	bool bIsWalking;
	//!< 歩いている時間(秒)
	float WalkingSecond;
	//!< レイトレース用クエリパラメータ
	FCollisionQueryParams param;
	//!< プレイヤーの現在の状態
	EPlayerActionMode CurrentActionMode;
	//!< 今入っているロッカー
	ALocker* IsInLocker;
    float LockerYawRotation;
};
