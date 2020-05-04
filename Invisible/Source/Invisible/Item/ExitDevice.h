// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"
#include "Components/SphereComponent.h"

#include "ExitDevice.generated.h"

class AExitItem;

UCLASS()
class INVISIBLE_API AExitDevice : public AActor, public IActionable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AExitDevice();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void action_Implementation() override;

	void Action();

	UFUNCTION(BluePrintCallable, Category = "DeviceAction")
	virtual void DeviceAction(){};

	UFUNCTION(BluePrintCallable, Category = "Get")
	virtual bool IsGet();

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* meshComponent;

	//!< バルブを対象としたアクション実行可能エリア
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Collision")
	USphereComponent* actionableArea;

	UPROPERTY(EditAnywhere, Category = "Items")
	TArray<AExitItem*> items;
};