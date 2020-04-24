// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SearchManager.h"

#include "Enemy.generated.h"

UCLASS()
class INVISIBLE_API AEnemy : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Moving(float DeltaTime);
	void SearchCourse();

private:
	UPROPERTY(EditAnywhere)
	float speed = 15.0f;
	UPROPERTY(EditAnywhere)
	float reflection = 10;

	UPROPERTY(EditAnywhere)
	ASearchManager* searchManager;
	TArray<FVector> courses;

	//UPROPERTY(EditAnywhere)
	//UStaticMeshComponent* meshComponent; //!< メッシュコンポーネント
	//UStaticMesh* mesh; //!< メッシュ
};
