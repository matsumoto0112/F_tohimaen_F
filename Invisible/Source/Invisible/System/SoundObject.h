// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "SoundObject.generated.h"

struct FSoundData;
enum class ESoundType : uint8;

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
	void playSound(FSoundData* sound);
    /**
    * ���̎�ނ��擾����
    */
	ESoundType getSoundType() const { return soundType; }

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

private:
    //!< �Đ����Ă��鉹�̎��
	ESoundType soundType;
};
