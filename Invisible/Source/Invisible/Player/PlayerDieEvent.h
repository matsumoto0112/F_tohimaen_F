// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "PlayerDieEvent.generated.h"

class APlayerCharacter;
class AEnemy;
class ALocker;

/**
* 死亡イベントの種類
*/
enum class EDieEventType
{
	Normal,
	Locker,
};

/**
* 通常イベントの進行度
*/
enum class ENormalEventPhase
{
	ToLookEnemy,
	Wait,
	SceneChange,
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
    * 通常死亡イベント更新処理
    */
	void UpdateNormalDieEvent();
    /**
    * 徐々に敵のほうを向く処理
    */
	void LookAtEnemyGradually();
    /**
    * 待機処理
    */
	void Wait();
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
    //!< 死亡イベントの種類
	EDieEventType DieEventType;
    //!< 通常死亡イベントの進行度
	ENormalEventPhase CurrentNormalEventPhase;
    //!< シーン変更までの待機時間カウンター
	float CurrentWaitTime;
    //!< プレイヤーキャラクター
	APlayerCharacter* PlayerCharacter;
    //!< プレイヤーを殺した敵
	AEnemy* Killer;
};
