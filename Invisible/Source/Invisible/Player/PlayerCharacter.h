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
    * ���b�J�[�̒��ɓ���
    */
	void IntoLocker(ALocker* Locker, const FVector& Location, const FRotator& FrontRotator);

	/**
    * ���S����
    */
	UFUNCTION(BlueprintCallable, Category = "Player")
	void ToDie(AActor* Killer);
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
    * ���b�J�[����o��
    */
	void GetOutLocker();

private:
	//!< �ő�ړ����x
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	float MaxMoveSpeed = 500.0f;

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
	FCollisionQueryParams DetectFootObjectLinetraceQueryParams;
	//!< �v���C���[�̌��݂̏��
	EPlayerActionMode CurrentActionMode;
	//!< �������Ă��郍�b�J�[
	ALocker* IsInLocker;
	//!< ���b�J�[�ɓ��������̉�]��(Yaw)
	float LockerYawRotation;
};
