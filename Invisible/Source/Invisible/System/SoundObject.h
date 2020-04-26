// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Invisible/System/SoundSystem.h"

#include "SoundObject.generated.h"

/**
* ���̃I�u�W�F�N�g
*/
UCLASS()
class INVISIBLE_API ASoundObject : public AActor
{
	GENERATED_BODY()

public:
	/**
    * �R���X�g���N�^
    */
	ASoundObject();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	/**
    * �����Đ�����
    */
	void playSound(FSoundData* sound,const FVector& location);
	/**
    * ���̎�ނ��擾����
    */
	ESoundType getSoundType() const { return soundType; }

    bool unused() const { return !isPlaying; }
private:
	/**
    * ���̍Đ��I�����̃C�x���g
    */
	UFUNCTION()
	void onAudioFinished();

private:
	//!< ���̕�������͈͗p�R���W����
	UPROPERTY(VisibleAnywhere)
	USphereComponent* soundHeardArea;

	UPROPERTY(VisibleAnywhere)
	UAudioComponent* audio;

private:
	//!< �Đ����Ă��鉹�̎��
	ESoundType soundType;
    bool isPlaying;
};
