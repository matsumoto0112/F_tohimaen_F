// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ExitItem.generated.h"

UCLASS(BlueprintType)
class INVISIBLE_API AExitItem : public AActor
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
	//virtual void Tick(float DeltaTime) override;

	virtual void Get();
	virtual void Use();

	virtual bool IsGet();
	virtual bool IsUse();

private:
	bool isGet, isUse;

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* meshComponent;
};