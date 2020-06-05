// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"

#include "Locker.generated.h"

UENUM(BlueprintType)
enum class EDoorMode : uint8
{
	Default,
	Open,
	Close,
};

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

	virtual EActionType GetActionType_Implementation() const override { return EActionType::Locker; }

	/**
    * �v���C���[���o��
    */
	void GetOutPlayer();
	/**
    * �h�A���J����
    */
	UFUNCTION(BlueprintCallable, Category = "Locker")
	void OpenDoor(float OpenSecond = 0.5f);

	/**
    * �h�A��߂�
    */
	UFUNCTION(BlueprintCallable, Category = "Locker")
	void CloseDoor(float CloseSecond = 0.5f);
	/**
    * ���b�J�[�̃h�A���J���Ă��邩
    */
	UFUNCTION(BlueprintCallable, Category = "Locker")
	bool IsOpenedDoor() const;

private:
	/**
    * �h�A����]������
    */
	UFUNCTION()
	void RotateDoor(float Value);

protected:
	UPROPERTY(EditAnywhere)
	float DoorOpenAngle = 90.0f;

public:
	//!< ���b�J�[�̃{�f�B���b�V��
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMeshComponent* BodyMeshComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	USceneComponent* DummyDoor;
	//!< ���b�J�[�̃h�A���b�V��
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMeshComponent* DoorMeshComponent;

	//!< �v���C���[�̗��ꏊ
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UArrowComponent* PlayerStandPoint;

private:
	//!< ���s�^�X�N���X�g
	DECLARE_DELEGATE_RetVal(bool, FTask);
	TQueue<FTask> Tasks;
};
