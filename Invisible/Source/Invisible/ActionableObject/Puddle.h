// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Puddle.generated.h"

UCLASS()
class INVISIBLE_API APuddle : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APuddle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* meshComponent; //!< バルブのメッシュコンポーネント
	UStaticMesh* mesh; //!< バルブのメッシュ
};
