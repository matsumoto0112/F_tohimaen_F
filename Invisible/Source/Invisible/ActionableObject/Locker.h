// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"

#include "Locker.generated.h"

UCLASS()
class INVISIBLE_API ALocker : public AActor, public IActionable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALocker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	/**
    * スプリンクラーを動作させる
    */
	virtual void action_Implementation() override;

    void GetOutPlayer();
public:
    //!< ロッカーのボディメッシュ
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    UStaticMeshComponent* BodyMeshComponent;
    //!< ロッカーのドアメッシュ
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    UStaticMeshComponent* DoorMeshComponent;

	//!< プレイヤーの立つ場所
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UArrowComponent* PlayerStandPoint;
};
