// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "LimitTimer.generated.h"

UCLASS()
class INVISIBLE_API ALimitTimer : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALimitTimer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "LimitTimer")
	void Init(float LimitTime);

	UFUNCTION(BluePrintCallable, Category = "LimitTimer")
	virtual float GetLimitTimer() const { return limitTimer; };

	UFUNCTION(BluePrintCallable, Category = "TimerOver")
	virtual bool IsTimeOver() const { return (limitTimer <= 0.0f); };

protected:
	// §ŒÀŽžŠÔ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float limitTime = 120.0f;
	float limitTimer = 0.0f;
};
