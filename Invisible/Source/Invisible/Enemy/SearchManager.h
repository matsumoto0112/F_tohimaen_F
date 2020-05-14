// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SearchEgde.h"

#include "SearchManager.generated.h"

class SearchCourse;

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
	TArray<FVector> Course(AActor* start, AActor* end) const;
	float GetRadius() const;

	FVector NearSearchPosition(AActor* actor) const;
	FVector NearSearchPosition(FVector point) const;

private:
	ASearchEgde* NearSearch(AActor* actor) const;
	ASearchEgde* NearSearch(FVector point) const;
	ASearchEgde* GetRandomSearch(ASearchEgde* remove) const;
	TArray<FVector> Course(SearchCourse* start, ASearchEgde* end) const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ASearchEgde*> search;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float radius=100.0f;
};
