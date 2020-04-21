// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"
#include "Components/SphereComponent.h"

#include "Valve.generated.h"

class ASprinkler;

UCLASS()
class INVISIBLE_API AValve : public AActor, public IActionable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AValve();

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

public:
	//!< バルブのメッシュ
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* meshComponent;

    //!< バルブを対象としたアクション実行可能エリア
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Collision")
	USphereComponent* actionableArea;
    //!< 連携するスプリンクラーID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	int32 sprinklerID;
private:
    //!< 連携しているスプリンクラー
	TArray<ASprinkler*> chainSprinklers;
};
