// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ExitItem.h"
#include "ExitDevice.h"

#include "ItemManager.generated.h"

UCLASS()
class INVISIBLE_API AItemManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//UPROPERTY(EditAnywhere)
	TMap<AExitDevice*, TArray<AExitItem*>> manager;

//	UPROPERTY(EditAnywhere)
//	TArray<AExitItem> items;
//	UPROPERTY(EditAnywhere)
//	TArray<AExitDevice> devices;

};
