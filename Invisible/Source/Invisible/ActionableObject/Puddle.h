// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Puddle.generated.h"

/**
* �����܂�I�u�W�F�N�g
*/
UCLASS()
class INVISIBLE_API APuddle : public AActor
{
	GENERATED_BODY()

public:
	/**
    * �R���X�g���N�^
    */
	APuddle();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	//!< �����܂�̃��b�V��
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMeshComponent* meshComponent;
};
