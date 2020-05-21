// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Invisible/Player/EnemyDetectArea.h"
#include "Invisible/Player/PlayerActionMode.h"

#include "PlayerCharacter.generated.h"

class ASoundObject;
class ALocker;

/**
* �v���C���[�L�����N�^�[
*/
UCLASS()
class INVISIBLE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	/**
    * �R���X�g���N�^
    */
	APlayerCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/**
    * �G���甭�����鉹�𕷂���
    */
	UFUNCTION(Category = "Sound")
	void HeardEnemyWalkOnPuddleSound(AEnemy* enemy);
	/**
    * ���݂̃A�N�V�������[�h���擾����
    */
	UFUNCTION(BlueprintCallable, Category = "Player")
	EPlayerActionMode GetCurrentActionMode() const { return CurrentActionMode; }

	void IntoLocker(ALocker* Locker, const FVector& Location, const FRotator& FrontRotator);

private:
	/**
    * �O�����ւ̈ړ�����
    */
	UFUNCTION()
	void moveForward(float value);
	/**
    * �E�����ւ̈ړ�����
    */
	UFUNCTION()
	void moveRight(float value);
	/**
    * �J�����̉������̉�]����
    */
	UFUNCTION()
	void turn(float amount);
	/**
    * �J�����̏㉺�����̉�]����
    */
	UFUNCTION()
	void lookup(float amount);
	/**
    * �����ɏՓ˂������ɌĂ΂��
    */
	UFUNCTION()
	void onComponentBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor,
	    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	/**
    * ������������
    */
	void heardSound(ASoundObject* soundObject);
	/**
    * ���s���̍Đ�����
    */
	void playWalkSound(float deltaTime);
	/**
    * �v���C���[�J�����̏㉺�����ɉ�]������������
    */
	void ClampPlayerCameraPitchRotation();
	/**
    * �v���C���[�J�����̍��E�����ɉ�]������������
    */
	void ClampPlayerCameraYawRotation();

	/**
    * ���S����
    */
	UFUNCTION(BlueprintCallable, Category = "Player")
	void ToDie();

	UFUNCTION()
	void InputedActionCommand();
	void DoActionNearObject();
	void GetOutLocker();

private:
	//!< �ő�ړ����x
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	float maxMoveSpeed = 500.0f;

protected:
	//!< ��]�W��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float RotateCoef = 100.0f;
	//!< �J�����̏㉺�����̉�]����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	FFloatRange NormalCameraPitch;

	//!< �����Ă���Ɣ��f�����ړ���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float WalkingThreshold = 0.5f;
	//!< ���s���̍Đ��Ԋu
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float WalkingSoundPlayInterval = 0.5f;
	//!< �G�������܂�𓥂񂾎��Ɍ����Ă��鎞��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float EnemyVisibleTimeWhenEnemyWalkOnPuddle = 1.0f;

	//!< ���b�J�[�ɓ���܂ł̑ҋ@����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locker")
	float WaitTimeToGoingIntoLocker = 0.5f;
	//!< ���b�J�[����o��܂ł̑ҋ@����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locker")
	float WaitTimeToGetOutLocker = 0.5f;
	//���b�J�[�ɂ���Ƃ��̃J�����̏㉺�����̉�]����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locker")
	FFloatRange CameraPitchWhenIsInLocker;
	//���b�J�[�ɂ���Ƃ��̃J�����̍��E�����̉�]����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locker")
	FFloatRange CameraYawWhenIsInLocker;

public:
	//!< �v���C���[�J����
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UCameraComponent* CameraComponent;
	//!< �A�N�V�������s�\�G���A
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UBoxComponent* ActionArea;
	//!< �G���m�G���A
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UEnemyDetectArea* EnemyDetectArea;

private:
	//!< �������Ă��邩
	bool bIsWalking;
	//!< �����Ă��鎞��(�b)
	float WalkingSecond;
	//!< ���C�g���[�X�p�N�G���p�����[�^
	FCollisionQueryParams param;
	//!< �v���C���[�̌��݂̏��
	EPlayerActionMode CurrentActionMode;
	//!< �������Ă��郍�b�J�[
	ALocker* IsInLocker;
	//!< ���b�J�[�ɓ��������̉�]��(Yaw)
	float LockerYawRotation;
};
