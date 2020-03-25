// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"

#include "Valve.generated.h"

class ASprinkler;
class USphereComponent;

UCLASS()
class INVISIBLE_API AValve : public AActor, public IActionable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AValve(const FObjectInitializer& ObjectInitializer);

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

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* meshComponent; //!< �o���u�̃��b�V���R���|�[�l���g
	UStaticMesh* mesh; //!< �o���u�̃��b�V��

	UPROPERTY(VisibleAnywhere)
	USphereComponent* actionableArea; //!< �o���u��ΏۂƂ����A�N�V�������s�\�G���A
	TArray<ASprinkler*> chainSprinklers; //!< �A�g���Ă���X�v�����N���[

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameter)
	int32 sprinklerID; //!< �A�g����X�v�����N���[ID
};
