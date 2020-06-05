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

	/**
    * �R���|�[�l���g�������ƃI�[�o�[���b�v�������̃C�x���g
    */
	UFUNCTION()
	void BeginOverlapEvent(UPrimitiveComponent* HitComp,
	    AActor* OtherActor, UPrimitiveComponent* OtherComp,
	    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	/**
        * �R���|�[�l���g�������ƃI�[�o�[���b�v�������������̃C�x���g
        */
	UFUNCTION()
	void EndOverlapEvent(UPrimitiveComponent* OverlappedComponent,
	    AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	UPROPERTY()
	APlayerHUD* PlayerHUD;
	TArray<AActor*> NearlyObjects;
};
