// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"

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
    virtual EActionType GetActionType_Implementation() const override;

	UFUNCTION(BluePrintCallable, BlueprintNativeEvent, Category = "DeviceAction")
	void DeviceAction();
	virtual void DeviceAction_Implementation();

	UFUNCTION(BluePrintCallable, BlueprintNativeEvent, Category = "DeviceAction")
	void DeviceActionUpdate();
	virtual void DeviceActionUpdate_Implementation();

	UFUNCTION(BluePrintCallable, Category = "Get")
	virtual bool IsGet() const;

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* meshComponent;

	//!< バルブを対象としたアクション実行可能エリア
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Collision")
	USphereComponent* actionableArea;

	UPROPERTY(EditAnywhere, Category = "Items")
	TArray<AExitItem*> items;

	UPROPERTY(EditAnywhere, Category = "radius")
	float radius=100.0f;
};
