// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"
#include "Invisible/Player/PlayerActionMode.h"
#include "SearchManager.h"
#include "Invisible/System/LimitTimer.h"

#include "Enemy.generated.h"

class ASoundObject;

enum class EMoveType : uint8
{
	None,
	Move,
	SE_Move,
	PlayerChase,
	Kill,
};
enum class ERotateType : uint8
{
	Right,
	Left,
};

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

	/**
    * �Q�[���I�����ɌĂ΂��
    */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// �v���C���[�E�Q��
	bool IsKill(float DeltaTime);
	// �Փˉӏ��ɍ��W�ݒ�
	void HitMoved();
	// �ړ�����
	void Moving(float DeltaTime);
	// ��]�T������
	void RotateSearch(float DeltaTime);
	// �o�H�T��
	void SearchCourse(float DeltaTime);
	// �v���C���[�T��
	void searchPlayer(AActor* OtherActor);
	// �v���C���[�ǐ�
	void chasePlayer();
	// �ҋ@���Ԑݒ�
	void SetWait();
	// �}�e���A��
	void SetMaterial(float DeltaTime);
	// �������ݒ�
	void AddReflection(float add);
	// ���b�J�[����
	void InLocker();
	// �������Ԃ��߂��ĂȂ���Ύw�肵�����[�h�Ɉڍs�A�߂��Ă�΃v���C���[�̍s���ɕύX
	bool TimerCheck(EPlayerActionMode mode);

	bool IsInLocker();
	void DebugDraw();

	// ���o���ɂ��邩
	UFUNCTION(BluePrintCallable, Category = "EyeArea")
	virtual bool IsEyeArea();

	// �ՓˊJ�n���ɌĂ΂��
	UFUNCTION(BluePrintCallable, Category = "Collision")
	virtual void onComponentBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor,
	    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BluePrintCallable, Category = "Collision")
	virtual void PlayerKill();

	UFUNCTION(BluePrintCallable, Category = "MoveType")
	virtual bool IsMove() const;
	UFUNCTION(BluePrintCallable, Category = "MoveType")
	virtual bool IsKill() const;

	//// �Փ˒��ɌĂ΂��
	//UFUNCTION(BluePrintCallable, Category = "Collision")
	//virtual void onComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
	//    UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& SweepResult);

	// ������������
	void heardSound(ASoundObject* soundObject);
	// ���s���̍Đ�����
	void playWalkSound(float deltaTime);
	// ������
	UFUNCTION(BluePrintCallable, Category = "Collision")
	void overBathing();

	/**
    * �V���G�b�g�̃X�P���^�����擾
    */
	USkeletalMeshComponent* GetSilhouetteSkeltal() const
	{
		return silhouetteSkeltal;
	}

	void ChangeStencilValueWhenWalkOnPuddle();

private:
	//�������Ԃ������̃X�e���V���l�̕ύX����
	void ChangeStencilValueWhenPutOnWater();

protected:
	// ����p�x
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float eyeDeg = 60.0f;
	// ����p�x
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float eyeLength = 1000.0f;

	// �ړ����x
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float walkSpeed = 150.0f;
	// �ړ����x
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float runSpeed = 1500.0f;
	// ��]���x
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float rotateSpeed = 15.0f;
	// �ҋ@����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float waitTime = 3.0f;
	float waitTimer = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float searchWaitPercent = 50.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float searchWaitRotateTime = 1.0f;
	float searchWaitRotateTimer = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float chaseTime = 5.0f;
	float chaseTimer = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float chaseSearchTime = 0.3f;

	// �G�ꔻ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float reflection = 1;
	// �������x
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float thirstSpeed = 5.0f;
	//���������������Ɍ����Ă���悤�ɂȂ鎞��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float VisibleTimeWhenEnemyPutOnWater = 10.0f;
	//�����܂�𓥂񂾎��Ɍ����Ă��鎞��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float VisibleTimeWhenEnemyWalkOnPuddle = 20.0f;

	//!< �����Ă��鎞��(�b)
	float walkingSecond;
	bool inLocker;

	// �o�H�Ǘ��N���X
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ASearchManager* searchManager;
	// �o�H���X�g
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> courses;

	FVector lastSearch;
	EMoveType moveType;

	AActor* player;
	TArray<AActor*> enemys;
	ALimitTimer* limitTimer;

	EPlayerActionMode playerActiveType = EPlayerActionMode::Default;
	ERotateType rotateType = ERotateType::Right;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int debugDraw = 0;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Collision")
	UCapsuleComponent* capsule;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Collision")
	USkeletalMeshComponent* skeltal;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ActionArea")
	USphereComponent* actionableArea;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Silhouette")
	USkeletalMeshComponent* silhouetteSkeltal;

private:
	//�������Ԃ������ɃX�e���V���l����莞�Ԍ�ɖ߂����߂̃^�C�}�[�n���h��
	FTimerHandle ReturnStencilValueWhenPutOnWaterHandle;
	//�����܂�𓥂񂾎��ɃX�e���V���l��߂����߂̃^�C�}�[�n���h��
	FTimerHandle ReturnStencilValueWhenWalkOnPuddle;
};
