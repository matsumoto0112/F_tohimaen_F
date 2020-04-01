// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"

#include "Sprinkler.generated.h"

class ATargetPoint;
class UParticleSystemComponent;
class UParticleSystem;

UCLASS()
class INVISIBLE_API ASprinkler : public AActor, public IActionable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASprinkler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	/**
    * スプリンクラーを動作させる
    */
	virtual void action_Implementation() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	/**
    * @brief スプリンクラーIDを取得する
    */
	inline int32 GetSprinklerID() const
	{
		return sprinklerID;
	}

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* meshComponent; //!< スプリンクラーのメッシュコンポーネント
	UStaticMesh* mesh; //!< スプリンクラーのメッシュ

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* particleComponent; //!< スプリンクラーの水のパーティクル
	const FName particleEmitterName = TEXT("Main"); //!< パーティクルのエミッタ名

	UPROPERTY(EditDefaultsOnly, Category = Parameter)
	float activeTime = 5.0f; //!< スプリンクラーの稼働時間
	FTimerHandle timerHandle; //!< スプリンクラーの稼働タイマーハンドル
	UPROPERTY(EditAnywhere, Category = Parameter)
	int32 sprinklerID; //!< 連携するバルブID

	UPROPERTY(EditAnywhere)
	TArray<ATargetPoint*> puddlePoints;
	bool puddleSpawned;
};
