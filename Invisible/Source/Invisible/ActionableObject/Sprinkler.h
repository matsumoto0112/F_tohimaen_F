// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"
#include "Invisible/System/SoundSystem.h"
#include "Particles/ParticleSystemComponent.h"

#include "Sprinkler.generated.h"

/**
* スプリンクラーオブジェクト
*/
UCLASS()
class INVISIBLE_API ASprinkler : public AActor, public IActionable
{
	GENERATED_BODY()

public:
	/**
    * コンストラクタ
    */
	ASprinkler();

protected:
	/**
    * ゲーム開始時に呼ばれる
    */
	virtual void BeginPlay() override;
	/**
    * ゲーム終了時に呼ばれる
    */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	/**
    * スプリンクラーを動作させる
    */
	virtual void action_Implementation() override;

	virtual EActionType GetActionType_Implementation() const override { return EActionType::None; }

public:
	/**
    * 毎フレーム呼ばれる
    */
	virtual void Tick(float DeltaTime) override;

public:
	/**
    * スプリンクラーIDを取得する
    */
	inline int32 GetSprinklerID() const
	{
		return sprinklerID;
	}

protected:
	//!< 連携するバルブID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	int32 sprinklerID;
	//!< スプリンクラーの稼働時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	float activeTime = 5.0f;

	//!< 水たまりの設置場所
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	TArray<ATargetPoint*> puddlePoints;
	//!< 再生する音の種類
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	ESoundType SoundType = ESoundType::Sprinkler_Ver0;

public:
	//!< スプリンクラーのメッシュ
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMeshComponent* meshComponent;

	//!< スプリンクラーの水のパーティクル
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UParticleSystemComponent* particleComponent;

	//!< 水がかかる範囲
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UBoxComponent* wetArea;

private:
	//!< パーティクルのエミッタ名
	const FName particleEmitterName = TEXT("Main");

private:
	//!< スプリンクラーの稼働タイマーハンドル
	FTimerHandle timerHandle;
	//!< 水たまりがすでに生成されたかどうか
	bool puddleSpawned;
};
