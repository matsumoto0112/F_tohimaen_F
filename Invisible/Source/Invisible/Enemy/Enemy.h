// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"
#include "Invisible/Player/PlayerActionMode.h"
#include "SearchManager.h"
#include "Invisible/System/LimitTimer.h"

#include "Enemy.generated.h"

class ASoundObject;

enum class EMoveType : uint8
{
	None,
	Move,
	SE_Move,
	PlayerChase,
	Kill,
};
enum class ERotateType : uint8
{
	Right,
	Left,
};

UCLASS()
class INVISIBLE_API AEnemy : public AActor, public IActionable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/**
    * ゲーム終了時に呼ばれる
    */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// プレイヤー殺害中
	bool IsKill(float DeltaTime);
	// 衝突箇所に座標設定
	void HitMoved();
	// 移動処理
	void Moving(float DeltaTime);
	// 回転探索処理
	void RotateSearch(float DeltaTime);
	// 経路探索
	void SearchCourse(float DeltaTime);
	// プレイヤー探索
	void searchPlayer(AActor* OtherActor);
	// プレイヤー追跡
	void chasePlayer();
	// 待機時間設定
	void SetWait();
	// マテリアル
	void SetMaterial(float DeltaTime);
	// 透明化設定
	void AddReflection(float add);
	// ロッカー処理
	void InLocker();
	// 制限時間を過ぎてなければ指定したモードに移行、過ぎてればプレイヤーの行動に変更
	bool TimerCheck(EPlayerActionMode mode);

	bool IsInLocker();
	void DebugDraw();

	// 視覚内にいるか
	UFUNCTION(BluePrintCallable, Category = "EyeArea")
	virtual bool IsEyeArea();

	// 衝突開始時に呼ばれる
	UFUNCTION(BluePrintCallable, Category = "Collision")
	virtual void onComponentBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor,
	    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BluePrintCallable, Category = "Collision")
	virtual void PlayerKill();

	UFUNCTION(BluePrintCallable, Category = "MoveType")
	virtual bool IsMove() const;
	UFUNCTION(BluePrintCallable, Category = "MoveType")
	virtual bool IsKill() const;

	//// 衝突中に呼ばれる
	//UFUNCTION(BluePrintCallable, Category = "Collision")
	//virtual void onComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
	//    UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& SweepResult);

	// 音が聞こえた
	void heardSound(ASoundObject* soundObject);
	// 歩行音の再生処理
	void playWalkSound(float deltaTime);
	// 水浴び
	UFUNCTION(BluePrintCallable, Category = "Collision")
	void overBathing();

	/**
    * シルエットのスケルタルを取得
    */
	USkeletalMeshComponent* GetSilhouetteSkeltal() const
	{
		return silhouetteSkeltal;
	}

	void ChangeStencilValueWhenWalkOnPuddle();

private:
	//水をかぶった時のステンシル値の変更処理
	void ChangeStencilValueWhenPutOnWater();

protected:
	// 視野角度
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float eyeDeg = 60.0f;
	// 視野角度
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float eyeLength = 1000.0f;

	// 移動速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float walkSpeed = 150.0f;
	// 移動速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float runSpeed = 1500.0f;
	// 回転速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float rotateSpeed = 15.0f;
	// 待機時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float waitTime = 3.0f;
	float waitTimer = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float searchWaitPercent = 50.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float searchWaitRotateTime = 1.0f;
	float searchWaitRotateTimer = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float chaseTime = 5.0f;
	float chaseTimer = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float chaseSearchTime = 0.3f;

	// 濡れ判定
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float reflection = 1;
	// 渇き速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float thirstSpeed = 5.0f;
	//水がかかった時に見えているようになる時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float VisibleTimeWhenEnemyPutOnWater = 10.0f;
	//水たまりを踏んだ時に見えている時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float VisibleTimeWhenEnemyWalkOnPuddle = 20.0f;

	//!< 歩いている時間(秒)
	float walkingSecond;
	bool inLocker;

	// 経路管理クラス
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ASearchManager* searchManager;
	// 経路リスト
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> courses;

	FVector lastSearch;
	EMoveType moveType;

	AActor* player;
	TArray<AActor*> enemys;
	ALimitTimer* limitTimer;

	EPlayerActionMode playerActiveType = EPlayerActionMode::Default;
	ERotateType rotateType = ERotateType::Right;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int debugDraw = 0;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Collision")
	UCapsuleComponent* capsule;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Collision")
	USkeletalMeshComponent* skeltal;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ActionArea")
	USphereComponent* actionableArea;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Silhouette")
	USkeletalMeshComponent* silhouetteSkeltal;

private:
	//水をかぶった時にステンシル値を一定時間後に戻すためのタイマーハンドル
	FTimerHandle ReturnStencilValueWhenPutOnWaterHandle;
	//水たまりを踏んだ時にステンシル値を戻すためのタイマーハンドル
	FTimerHandle ReturnStencilValueWhenWalkOnPuddle;
};
