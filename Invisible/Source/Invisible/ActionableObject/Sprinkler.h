// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"
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

public:
	//!< スプリンクラーのメッシュ
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* meshComponent;

	//!< スプリンクラーの水のパーティクル
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Particle")
	UParticleSystemComponent* particleComponent;
	//!< パーティクルのエミッタ名
	//NOTE: パーティクルのエミッタ名をベタ打ちなので改善対象
	const FName particleEmitterName = TEXT("Main");

	//!< スプリンクラーの稼働時間
	UPROPERTY(EditDefaultsOnly, Category = "Parameter")
	float activeTime = 5.0f;

    //!< 連携するバルブID
	UPROPERTY(EditAnywhere, Category = "Parameter")
	int32 sprinklerID;

	//!< 水たまりの設置場所
	UPROPERTY(EditAnywhere, Category = "Parameter")
	TArray<ATargetPoint*> puddlePoints;
private:
	//!< スプリンクラーの稼働タイマーハンドル
	FTimerHandle timerHandle;
	//!< 水たまりがすでに生成されたかどうか
	bool puddleSpawned;
};
