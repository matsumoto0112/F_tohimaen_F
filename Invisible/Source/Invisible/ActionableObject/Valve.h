// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"

#include "Valve.generated.h"

class USphereComponent;

UCLASS()
class INVISIBLE_API AValve : public AActor, public IActionable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AValve(const FObjectInitializer& ObjectInitializer);

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

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* meshComponent;
	UStaticMesh* mesh;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* actionableArea;
};
