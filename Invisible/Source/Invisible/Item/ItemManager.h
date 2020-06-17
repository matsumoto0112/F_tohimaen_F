// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ItemManager.generated.h"

class AExitItem;

UCLASS()
class INVISIBLE_API AItemManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemManager();

	UFUNCTION(BluePrintCallable, Category = "Items")
	virtual int32 GetItemCount() const;

	UFUNCTION(BluePrintCallable, Category = "Items")
	virtual int32 AllItemCount() const;

	UFUNCTION(BluePrintCallable, Category = "Items")
	virtual FString ItemCountView() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void PopItem();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	TArray<AExitItem*> items;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	TArray<FVector> popArray;
};
