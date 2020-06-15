// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "PuddleFactory.generated.h"

/**
* 水たまり生成器
*/
UCLASS()
class INVISIBLE_API APuddleFactory : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APuddleFactory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**
    * ランダムに水たまりをスポーンさせる
    */
	UFUNCTION()
	AActor* spawnRandomPuddle(const FVector& location);

protected:
	//!< 水たまりの原器
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Puddle")
	TArray<TSubclassOf<AActor>> originPuddles;

	//!< ランダムストリーム
	UPROPERTY()
	FRandomStream random;
};
