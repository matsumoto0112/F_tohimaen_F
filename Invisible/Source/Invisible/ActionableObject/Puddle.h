// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Puddle.generated.h"

/**
* 水たまりオブジェクト
*/
UCLASS()
class INVISIBLE_API APuddle : public AActor
{
	GENERATED_BODY()

public:
	/**
    * コンストラクタ
    */
	APuddle();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	//!< 水たまりのメッシュ
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMeshComponent* meshComponent;
};
