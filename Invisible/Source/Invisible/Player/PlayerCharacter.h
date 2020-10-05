// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Invisible/Player/EnemyDetectArea.h"
#include "Invisible/Player/PlayerActionArea.h"
#include "Invisible/Player/PlayerActionMode.h"

#include "PlayerCharacter.generated.h"

class ASoundObject;
class ALocker;

UENUM(BlueprintType)
enum class EPlayerMoveState : uint8
{
	NO_MOVE,
	WALKING,
	RUNNING,
};

UENUM(BlueprintType)
enum class ECameraMode : uint8
{
	FRONT,
	FRONT_TO_BACK,
	BACK,
	BACK_TO_FRONT,
};

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
    * アクションモードを設定する
    * @details 現在の状態がIsDyingなら変化させない（バグ対策）
    */
	void SetCurrentActionMode(EPlayerActionMode Next);
	/**
    * ロッカーに入る準備をする
    */
	void IntoLockerReady(ALocker* Locker);
	/**
    * ロッカーの中に入る
    */
	void IntoLocker(const FVector& Location, const FRotator& FrontRotator);
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
	* プレイヤーの移動状態を取得する
	*/
	UFUNCTION(BlueprintCallable, Category = "Player")
	EPlayerMoveState GetPlayerMoveState() const { return MoveState; }
	/**
    * 今入っているロッカーを取得する
    */
	UFUNCTION(BlueprintCallable, Category = "Player")
	ALocker* GetCurrentInLocker() const
	{
		return IsInLocker;
	};

	/**
    * クリアフラグを立てる
    */
	UFUNCTION(BlueprintCallable, Category = "Player")
	void SetClearFlag() { CurrentActionMode = EPlayerActionMode::IsClear; }

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

	UFUNCTION()
	void Sprint();

	UFUNCTION()
	void ReleaseSprint();

	UFUNCTION()
	void Flip();
	UFUNCTION()
	void ReleaseFlip();

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
    * ロッカーに入っているときに座標を固定する
    */
	void FixedLocationIfInLocker();
	/**
	* 次のスプリントの状態をセットする
	*/
	void SetSprintState(bool NextState);

private:
	//!< ロッカーから出るときの座標のオフセット値
	UPROPERTY(EditDefaultsOnly, Category = "Locker")
	float OffsetLockerGetOutLength = 100.0f;
	//! 歩行時の移動速度
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	float WalkingMoveSpeed = 250.0f;
	//! ダッシュ時の移動速度
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	float RunningMoveSpeed = 500.0f;
	//! 反転カメラの回転速度
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	float FlipCameraRotateSpeed = 360.0f * 8.0f;

protected:
	//!< カメラの上下方向の回転制限
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	FFloatRange NormalCameraPitch = FFloatRange(-45.0f, 45.0f);

	//!< 歩いていると判断される移動量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float WalkingThreshold = 0.5f;
	//!< 歩行音の再生間隔
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float WalkingSoundPlayInterval = 0.5f;
	//!< 歩行音の再生間隔
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float RunningSoundPlayInterval = 0.25f;
	//!< 敵が水たまりを踏んだ時に見えている時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float EnemyVisibleTimeWhenEnemyWalkOnPuddle = 1.0f;

	//ロッカーにいるときのカメラの上下方向の回転制限
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locker")
	FFloatRange CameraPitchWhenIsInLocker;
	//ロッカーにいるときのカメラの左右方向の回転制限
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locker")
	FFloatRange CameraYawWhenIsInLocker;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FFloatRange Rag = FFloatRange(3.0f, 4.0f);

public:
	//!< プレイヤーカメラ
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UCameraComponent* CameraComponent;
	//!< 敵検知エリア
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UEnemyDetectArea* EnemyDetectArea;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UPlayerActionArea* ActionArea;

private:
	//! 現在のプレイヤーの移動状態
	EPlayerMoveState MoveState;
	float CurrentFlipRotate;
	bool bInputtedSprint;
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
	ECameraMode CameraMode;
};
