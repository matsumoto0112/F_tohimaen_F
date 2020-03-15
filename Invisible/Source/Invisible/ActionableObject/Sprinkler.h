// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"

#include "Sprinkler.generated.h"

/**
* �X�v�����N���[�I�u�W�F�N�g
*/
UCLASS()
class INVISIBLE_API ASprinkler : public AActor,public IActionable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASprinkler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    /**
    * �X�v�����N���[�𓮍삳����
    */
    virtual void action_Implementation() override;
};
