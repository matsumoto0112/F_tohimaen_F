// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SearchEgde.h"

#include "SearchManager.generated.h"

UCLASS()
class INVISIBLE_API ASearchManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASearchManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray<FVector> Course(AActor* actor) const;
	float GetRadius() const;

private:
	ASearchEgde* NearSearch(AActor* actor) const;
	ASearchEgde* GetRandomSearch(ASearchEgde* remove) const;

private:
	UPROPERTY(EditAnywhere)
	TArray<ASearchEgde*> search;
	UPROPERTY(EditAnywhere)
	float radius=100.0f;
};
