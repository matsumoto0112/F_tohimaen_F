// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Invisible/Enemy/Enemy.h"

#include "EnemyDetectArea.generated.h"

/**
* 敵の情報を格納する構造体
*/
USTRUCT()
struct INVISIBLE_API FEnemyDetect
{
	GENERATED_USTRUCT_BODY()

	//!< 敵アクター
	AEnemy* Enemy;
	//!< この敵に対しての警戒用振動をしたかどうか
	bool bWarned;
};

/**
 * 敵検知範囲管理
 */
UCLASS()
class INVISIBLE_API UEnemyDetectArea : public USphereComponent
{
	GENERATED_BODY()

public:
	UEnemyDetectArea();
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	/**
    * 敵を検知し、警告を出す
    */
	void DetectAndWarn();

private:
	/**
    * コンポーネントが何かとオーバーラップした時のイベント
    */
	UFUNCTION()
	void BeginOverlapEvent(UPrimitiveComponent* HitComp,
	    AActor* OtherActor, UPrimitiveComponent* OtherComp,
	    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	/**
    * コンポーネントが何かとオーバーラップを解除した時のイベント
    */
	UFUNCTION()
	void EndOverlapEvent(UPrimitiveComponent* OverlappedComponent,
	    AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	/**
    * オーバーラップしたアクターが敵かどうか判定する
    */
	bool CheckOverlappingsActorIsEnemy(AActor* OtherActor, UPrimitiveComponent* OtherComp);
	/**
    * 敵とオーバーラップした
    */
	void BeginOverlapEnemy(class AEnemy* Enemy);
	/**
    * 敵とオーバーラップ解除した
    */
	void EndOverlapEnemy(class AEnemy* Enemy);

protected:
	//!< 振動する時間
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Duration = 1.5f;

private:
	//!< コントローラの振動ハンドル
	FDynamicForceFeedbackHandle DynamicForceFeedbackHandle;
	//!< 敵情報
	TArray<FEnemyDetect> Enemies;
};
