// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"

#include "ExitItem.generated.h"

UCLASS()
class INVISIBLE_API AExitItem : public AActor, public IActionable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AExitItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void action_Implementation() override;

	void Action();

	UFUNCTION(BluePrintCallable, Category = "ItemAction")
	virtual void ItemAction(){};

	virtual void Get();
	virtual void Use();

	virtual bool IsGet();
	virtual bool IsUse();

private:
	bool isGet, isUse;

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* meshComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ActionArea")
	USphereComponent* actionableArea;
};