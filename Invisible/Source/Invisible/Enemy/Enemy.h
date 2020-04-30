// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SearchManager.h"
#include "Invisible/ActionableObject/Actionable.h"
#include "Components/SphereComponent.h"

#include "Enemy.generated.h"

class ASoundObject;

UCLASS()
class INVISIBLE_API AEnemy : public AActor, public IActionable
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

	// �ړ�����
	void Moving(float DeltaTime);
	// �o�H�T��
	void SearchCourse(float DeltaTime);
	// �v���C���[�T��
	void searchPlayer(AActor* OtherActor);
	// �ҋ@���Ԑݒ�
	void SetWait();
	// �}�e���A��
	void SetMaterial(float DeltaTime);
	// �������ݒ�
	void AddReflection(float add);

	// �ՓˊJ�n���ɌĂ΂��
	UFUNCTION()
	void onComponentBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor,
	    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    // ������������
	void heardSound(ASoundObject* soundObject);
	// ���s���̍Đ�����
	void playWalkSound(float deltaTime);
	// ������
	void bathing(AActor* OtherActor);

private:

	// �ړ����x
	UPROPERTY(EditAnywhere)
	float moveSpeed = 150.0f;
	// ��]���x
	UPROPERTY(EditAnywhere)
	float rotateSpeed = 15.0f;
	// �ҋ@����
	UPROPERTY(EditAnywhere)
	float waitTime = 3.0f;
	float waitTimer = 0.0f;
	// �G�ꔻ��
	UPROPERTY(EditAnywhere)
	float reflection = 10;

	//!< �����Ă��鎞��(�b)
	float walkingSecond;

	// �o�H�Ǘ��N���X
	UPROPERTY(EditAnywhere)
	ASearchManager* searchManager;
	TArray<FVector> courses;

	public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Collision")
	USkeletalMeshComponent* skeltal;

	//UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Mesh")
	//UStaticMeshComponent* meshComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Collision")
	USphereComponent* actionableArea;
};
