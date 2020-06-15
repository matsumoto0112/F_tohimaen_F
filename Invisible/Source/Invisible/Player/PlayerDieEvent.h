// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Invisible/Util/QueueTaskManager.h"

#include "PlayerDieEvent.generated.h"

class APlayerCharacter;
class AEnemy;
class ALocker;

USTRUCT(BlueprintType)
struct FMaterialParameter
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	float DelayTime;
	UPROPERTY(EditAnywhere)
	float Value;
};

/**
* プレイヤー側の死亡イベント管理
*/
//TODO: イベントごとに継承させて一つのイベントを管理させるようにしたほうが良い
//あまり時間がないのと複雑になるので今はすべてのイベントをここで管理させる
UCLASS()
class INVISIBLE_API APlayerDieEvent : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlayerDieEvent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	/**
* @brief ポストプロセスの初期設定
*/
	void InitPostProcess();
	/**
    * @brief マテリアルのパラメータを時間に合わせて変更
    */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "PlayerDieEvent")
	void SetPostProcessParametersWithDelay();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**
    * 通常死亡イベント開始
    */
	void StartNormalDieEvent(APlayerCharacter* Player, AEnemy* Enemy);
	/**
    * ロッカーでの死亡イベント開始
    */
	void StartLockerDieEvent(APlayerCharacter* Player, AEnemy* Enemy, ALocker* Locker);
	/**
    * シーン変更処理
    * @details BPのほうでシーン変更処理を実装しているのでcppからは呼べないのでこの実装もBPでやる
    */
	UFUNCTION(BlueprintNativeEvent)
	void SceneChange(const FName& SceneName);
	virtual void SceneChange_Implementation(const FName& SceneName) {}

protected:
	//!< 次のシーン名
	UPROPERTY(EditAnywhere, Category = "General")
	FName NextSceneName;
	//!< 通常死亡時プレイヤーが敵のほうを向いてからの待機時間
	UPROPERTY(EditAnywhere, Category = "Normal")
	float WaitTime = 3.0f;

private:
	//!< 死亡イベントが開始しているか
	bool bIsStartedEvent;
	//!< タスク管理
	QueueTaskManager TaskManager;
};
