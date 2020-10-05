// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Invisible/Player/EnemyDetectArea.h"
#include "Invisible/Player/PlayerActionArea.h"
#include "Invisible/Player/PlayerActionMode.h"

#include "PlayerCharacter.generated.h"

class ASoundObject;
class ALocker;

UENUM(BlueprintType)
enum class EPlayerMoveState : uint8
{
	NO_MOVE,
	WALKING,
	RUNNING,
};

UENUM(BlueprintType)
enum class ECameraMode : uint8
{
	FRONT,
	FRONT_TO_BACK,
	BACK,
	BACK_TO_FRONT,
};

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
	/**
    * �Q�[���J�n���ɌĂ΂��
    */
	virtual void BeginPlay() override;
	/**
    * �Q�[���I�����ɌĂ΂��
    */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	/**
    * �Q�[���X�V����
    */
	virtual void Tick(float DeltaTime) override;
	/**
    * ���̓o�C���h����
    */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
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
	/**
    * �A�N�V�������[�h��ݒ肷��
    * @details ���݂̏�Ԃ�IsDying�Ȃ�ω������Ȃ��i�o�O�΍�j
    */
	void SetCurrentActionMode(EPlayerActionMode Next);
	/**
    * ���b�J�[�ɓ��鏀��������
    */
	void IntoLockerReady(ALocker* Locker);
	/**
    * ���b�J�[�̒��ɓ���
    */
	void IntoLocker(const FVector& Location, const FRotator& FrontRotator);
	/**
    * ���b�J�[����o��Ƃ��Ƀ��b�J�[�̃h�A���J�������Ƃ�m�点��C�x���g
    */
	void LockerDoorOpenedEvent();
	/**
    * ���S����
    */
	UFUNCTION(BlueprintCallable, Category = "Player")
	void ToDie(AActor* Killer);
	/**
	* �v���C���[�̈ړ���Ԃ��擾����
	*/
	UFUNCTION(BlueprintCallable, Category = "Player")
	EPlayerMoveState GetPlayerMoveState() const { return MoveState; }
	/**
    * �������Ă��郍�b�J�[���擾����
    */
	UFUNCTION(BlueprintCallable, Category = "Player")
	ALocker* GetCurrentInLocker() const
	{
		return IsInLocker;
	};

	/**
    * �N���A�t���O�𗧂Ă�
    */
	UFUNCTION(BlueprintCallable, Category = "Player")
	void SetClearFlag() { CurrentActionMode = EPlayerActionMode::IsClear; }

private:
	/**
    * �O�����ւ̈ړ�����
    */
	UFUNCTION()
	void MoveForward(float Value);
	/**
    * �E�����ւ̈ړ�����
    */
	UFUNCTION()
	void MoveRight(float Value);
	/**
    * �J�����̉������̉�]����
    */
	UFUNCTION()
	void Turn(float Amount);
	/**
    * �J�����̏㉺�����̉�]����
    */
	UFUNCTION()
	void Lookup(float Amount);

	UFUNCTION()
	void Sprint();

	UFUNCTION()
	void ReleaseSprint();

	UFUNCTION()
	void Flip();
	UFUNCTION()
	void ReleaseFlip();

	/**
    * �����ɏՓ˂������ɌĂ΂��
    */
	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor,
	    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	/**
    * ������������
    */
	void HeardSound(ASoundObject* soundObject);
	/**
    * ���s���̍Đ�����
    */
	void PlayWalkSound(float DeltaTime);
	/**
    * �v���C���[�J�����̏㉺�����ɉ�]������������
    */
	void ClampPlayerCameraPitchRotation();
	/**
    * �v���C���[�J�����̍��E�����ɉ�]������������
    */
	void ClampPlayerCameraYawRotation();

	/**
    * �A�N�V�����R�}���h���󂯎�������̏���
    */
	UFUNCTION()
	void InputedActionCommand();
	/**
    * �߂��̃I�u�W�F�N�g���쓮������
    */
	void DoActionNearObject();
	/**
    * ���b�J�[�ɓ����Ă���Ƃ��ɍ��W���Œ肷��
    */
	void FixedLocationIfInLocker();
	/**
	* ���̃X�v�����g�̏�Ԃ��Z�b�g����
	*/
	void SetSprintState(bool NextState);

private:
	//!< ���b�J�[����o��Ƃ��̍��W�̃I�t�Z�b�g�l
	UPROPERTY(EditDefaultsOnly, Category = "Locker")
	float OffsetLockerGetOutLength = 100.0f;
	//! ���s���̈ړ����x
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	float WalkingMoveSpeed = 250.0f;
	//! �_�b�V�����̈ړ����x
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	float RunningMoveSpeed = 500.0f;
	//! ���]�J�����̉�]���x
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	float FlipCameraRotateSpeed = 360.0f * 8.0f;

protected:
	//!< �J�����̏㉺�����̉�]����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	FFloatRange NormalCameraPitch = FFloatRange(-45.0f, 45.0f);

	//!< �����Ă���Ɣ��f�����ړ���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float WalkingThreshold = 0.5f;
	//!< ���s���̍Đ��Ԋu
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float WalkingSoundPlayInterval = 0.5f;
	//!< ���s���̍Đ��Ԋu
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float RunningSoundPlayInterval = 0.25f;
	//!< �G�������܂�𓥂񂾎��Ɍ����Ă��鎞��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float EnemyVisibleTimeWhenEnemyWalkOnPuddle = 1.0f;

	//���b�J�[�ɂ���Ƃ��̃J�����̏㉺�����̉�]����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locker")
	FFloatRange CameraPitchWhenIsInLocker;
	//���b�J�[�ɂ���Ƃ��̃J�����̍��E�����̉�]����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locker")
	FFloatRange CameraYawWhenIsInLocker;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FFloatRange Rag = FFloatRange(3.0f, 4.0f);

public:
	//!< �v���C���[�J����
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UCameraComponent* CameraComponent;
	//!< �G���m�G���A
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UEnemyDetectArea* EnemyDetectArea;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UPlayerActionArea* ActionArea;

private:
	//! ���݂̃v���C���[�̈ړ����
	EPlayerMoveState MoveState;
	float CurrentFlipRotate;
	bool bInputtedSprint;
	//!< �����Ă��鎞��(�b)
	float WalkingSecond;
	//!< ���C�g���[�X�p�N�G���p�����[�^
	FCollisionQueryParams DetectFootObjectLinetraceQueryParams;
	//!< �v���C���[�̌��݂̏��
	EPlayerActionMode CurrentActionMode;
	//!< �������Ă��郍�b�J�[
	ALocker* IsInLocker;
	//!< ���b�J�[�ɓ��������̉�]��(Yaw)
	float LockerYawRotation;
	//!< �Œ肷����W
	FVector FixedLocation;
	ECameraMode CameraMode;
};
