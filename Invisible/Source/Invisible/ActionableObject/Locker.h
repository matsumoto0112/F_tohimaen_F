// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"

#include "Locker.generated.h"

UCLASS()
class INVISIBLE_API ALocker : public AActor, public IActionable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALocker();

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

    void GetOutPlayer();
public:
    //!< ���b�J�[�̃{�f�B���b�V��
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    UStaticMeshComponent* BodyMeshComponent;
    //!< ���b�J�[�̃h�A���b�V��
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    UStaticMeshComponent* DoorMeshComponent;

	//!< �v���C���[�̗��ꏊ
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UArrowComponent* PlayerStandPoint;
};
