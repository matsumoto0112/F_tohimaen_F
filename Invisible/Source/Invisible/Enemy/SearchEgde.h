// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "SearchEgde.generated.h"

UCLASS()
class INVISIBLE_API ASearchEgde : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASearchEgde();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual bool ShouldTickIfViewportsOnly() const override;

	TArray<ASearchEgde*> GetBranch() const;
	void SetBranch();
	float GetRadius() const;
	void SetRadius(float r);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float radius = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ASearchEgde*> branch;
};
