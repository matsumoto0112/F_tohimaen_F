// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Invisible/Util/QueueTaskManager.h"

#include "PlayerDieEvent.generated.h"

class APlayerCharacter;
class AEnemy;
class ALocker;

/**
* �v���C���[���̎��S�C�x���g�Ǘ�
*/
//TODO: �C�x���g���ƂɌp�������Ĉ�̃C�x���g���Ǘ�������悤�ɂ����ق����ǂ�
//���܂莞�Ԃ��Ȃ��̂ƕ��G�ɂȂ�̂ō��͂��ׂẴC�x���g�������ŊǗ�������
UCLASS()
class INVISIBLE_API APlayerDieEvent : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlayerDieEvent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**
    * �ʏ펀�S�C�x���g�J�n
    */
	void StartNormalDieEvent(APlayerCharacter* Player, AEnemy* Enemy);
	/**
    * ���b�J�[�ł̎��S�C�x���g�J�n
    */
	void StartLockerDieEvent(APlayerCharacter* Player, AEnemy* Enemy, ALocker* Locker);
	/**
    * �V�[���ύX����
    * @details BP�̂ق��ŃV�[���ύX�������������Ă���̂�cpp����͌ĂׂȂ��̂ł��̎�����BP�ł��
    */
	UFUNCTION(BlueprintNativeEvent)
	void SceneChange(const FName& SceneName);
	virtual void SceneChange_Implementation(const FName& SceneName) {}

protected:
	//!< ���̃V�[����
	UPROPERTY(EditAnywhere, Category = "General")
	FName NextSceneName;
	//!< �ʏ펀�S���v���C���[���G�̂ق��������Ă���̑ҋ@����
	UPROPERTY(EditAnywhere, Category = "Normal")
	float WaitTime = 3.0f;
	//!< �l�K�|�W���]�|�X�g�v���Z�X�}�e���A��
	UPROPERTY(EditAnywhere, Category = "Normal")
	UMaterial* NegaPosiFlip;

private:
	//!< ���S�C�x���g���J�n���Ă��邩
	bool bIsStartedEvent;
	//!< �^�X�N�Ǘ�
	QueueTaskManager TaskManager;
};
