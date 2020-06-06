// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Invisible/Util/QueueTaskManager.h"

#include "PlayerDieEvent.generated.h"

class APlayerCharacter;
class AEnemy;
class ALocker;

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
	//!< ネガポジ反転ポストプロセスマテリアル
	UPROPERTY(EditAnywhere, Category = "Normal")
	UMaterial* NegaPosiFlip;

private:
	//!< 死亡イベントが開始しているか
	bool bIsStartedEvent;
	//!< タスク管理
	QueueTaskManager TaskManager;
};
