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
	/**
    * ゲーム開始時に呼ばれる
    */
	virtual void BeginPlay() override;
	/**
    * ゲーム終了時に呼ばれる
    */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	/**
    * ゲーム更新処理
    */
	virtual void Tick(float DeltaTime) override;
	/**
    * 入力バインド処理
    */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
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
    /**
    * ロッカーに入る準備をする
    */
    void IntoLockerReady();
	/**
    * ロッカーの中に入る
    */
	void IntoLocker(ALocker* Locker, const FVector& Location, const FRotator& FrontRotator);
	/**
    * ロッカーから出るときにロッカーのドアが開いたことを知らせるイベント
    */
	void LockerDoorOpenedEvent();
	/**
    * 死亡する
    */
	UFUNCTION(BlueprintCallable, Category = "Player")
	void ToDie(AActor* Killer);
	/**
    * 歩行中か
    */
	UFUNCTION(BlueprintCallable, Category = "Player")
	bool IsWalking() const { return bIsWalking; }
    /**
    * 今入っているロッカーを取得する
    */
	UFUNCTION(BlueprintCallable, Category = "Player")
	ALocker* GetCurrentInLocker() const
	{
		return IsInLocker;
	};

private:
	/**
    * 前方向への移動処理
    */
	UFUNCTION()
	void MoveForward(float Value);
	/**
    * 右方向への移動処理
    */
	UFUNCTION()
	void MoveRight(float Value);
	/**
    * カメラの横方向の回転処理
    */
	UFUNCTION()
	void Turn(float Amount);
	/**
    * カメラの上下方向の回転処理
    */
	UFUNCTION()
	void Lookup(float Amount);
	/**
    * 何かに衝突した時に呼ばれる
    */
	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor,
	    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	/**
    * 音が聞こえた
    */
	void HeardSound(ASoundObject* soundObject);
	/**
    * 歩行音の再生処理
    */
	void PlayWalkSound(float DeltaTime);
	/**
    * プレイヤーカメラの上下方向に回転制限をかける
    */
	void ClampPlayerCameraPitchRotation();
	/**
    * プレイヤーカメラの左右方向に回転制限をかける
    */
	void ClampPlayerCameraYawRotation();

	/**
    * アクションコマンドを受け取った時の処理
    */
	UFUNCTION()
	void InputedActionCommand();
	/**
    * 近くのオブジェクトを作動させる
    */
	void DoActionNearObject();
	/**
    * ロッカーから出る
    */
	void GetOutLocker();
	/**
    * ロッカーに入っているときに座標を固定する
    */
	void FixedLocationIfInLocker();

private:
	//!< 最大移動速度
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	float MaxMoveSpeed = 500.0f;

protected:
	//!< カメラの上下方向の回転制限
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	FFloatRange NormalCameraPitch;

	//!< 歩いていると判断される移動量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float WalkingThreshold = 0.5f;
	//!< 歩行音の再生間隔
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float WalkingSoundPlayInterval = 0.5f;
	//!< 敵が水たまりを踏んだ時に見えている時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float EnemyVisibleTimeWhenEnemyWalkOnPuddle = 1.0f;

	//ロッカーにいるときのカメラの上下方向の回転制限
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locker")
	FFloatRange CameraPitchWhenIsInLocker;
	//ロッカーにいるときのカメラの左右方向の回転制限
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locker")
	FFloatRange CameraYawWhenIsInLocker;

public:
	//!< プレイヤーカメラ
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UCameraComponent* CameraComponent;
	//!< アクション実行可能エリア
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UBoxComponent* ActionArea;
	//!< 敵検知エリア
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UEnemyDetectArea* EnemyDetectArea;

private:
	//!< 今歩いているか
	bool bIsWalking;
	//!< 歩いている時間(秒)
	float WalkingSecond;
	//!< レイトレース用クエリパラメータ
	FCollisionQueryParams DetectFootObjectLinetraceQueryParams;
	//!< プレイヤーの現在の状態
	EPlayerActionMode CurrentActionMode;
	//!< 今入っているロッカー
	ALocker* IsInLocker;
	//!< ロッカーに入った時の回転量(Yaw)
	float LockerYawRotation;
	//!< 固定する座標
	FVector FixedLocation;
};
