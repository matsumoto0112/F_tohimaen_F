// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "ExitItem.h"
#include "GameFramework/Actor.h"

#include "ExitDevice.generated.h"

UCLASS(BlueprintType)
class INVISIBLE_API AExitDevice : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AExitDevice();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//// Called every frame
	//virtual void Tick(float DeltaTime) override;

	void Action();
	bool IsGet();

private:
	virtual void DeviceAction(){};

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* meshComponent;

//private:
//	TArray<AExitItem*> items;
};