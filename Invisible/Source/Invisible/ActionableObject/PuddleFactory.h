// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "PuddleFactory.generated.h"

/**
* �����܂萶����
*/
UCLASS()
class INVISIBLE_API APuddleFactory : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APuddleFactory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**
    * �����_���ɐ����܂���X�|�[��������
    */
	UFUNCTION()
	AActor* spawnRandomPuddle(const FVector& location);

protected:
	//!< �����܂�̌���
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Puddle")
	TArray<TSubclassOf<AActor>> originPuddles;

	//!< �����_���X�g���[��
	UPROPERTY()
	FRandomStream random;
};
