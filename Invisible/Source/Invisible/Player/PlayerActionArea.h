// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "Invisible/ActionableObject/Actionable.h"
#include "Invisible/Player/PlayerHUD.h"

#include "PlayerActionArea.generated.h"

/**
 *
 */
UCLASS()
class INVISIBLE_API UPlayerActionArea : public UBoxComponent
{
	GENERATED_BODY()

public:
	UPlayerActionArea();

	virtual void BeginPlay() override;

	virtual void DoAction();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

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

private:
	void SortByDistance();

private:
	UPROPERTY()
	APlayerHUD* PlayerHUD;
	TArray<AActor*> NearlyObjects;
};
