// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"

#include "Sprinkler.generated.h"

class ATargetPoint;
class UParticleSystemComponent;
class UParticleSystem;

UCLASS()
class INVISIBLE_API ASprinkler : public AActor, public IActionable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASprinkler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	/**
    * �X�v�����N���[�𓮍삳����
    */
	virtual void action_Implementation() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	/**
    * @brief �X�v�����N���[ID���擾����
    */
	inline int32 GetSprinklerID() const
	{
		return sprinklerID;
	}

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* meshComponent; //!< �X�v�����N���[�̃��b�V���R���|�[�l���g
	UStaticMesh* mesh; //!< �X�v�����N���[�̃��b�V��

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* particleComponent; //!< �X�v�����N���[�̐��̃p�[�e�B�N��
	const FName particleEmitterName = TEXT("Main"); //!< �p�[�e�B�N���̃G�~�b�^��

	UPROPERTY(EditDefaultsOnly, Category = Parameter)
	float activeTime = 5.0f; //!< �X�v�����N���[�̉ғ�����
	FTimerHandle timerHandle; //!< �X�v�����N���[�̉ғ��^�C�}�[�n���h��
	UPROPERTY(EditAnywhere, Category = Parameter)
	int32 sprinklerID; //!< �A�g����o���uID

	UPROPERTY(EditAnywhere)
	TArray<ATargetPoint*> puddlePoints;
	bool puddleSpawned;
};
