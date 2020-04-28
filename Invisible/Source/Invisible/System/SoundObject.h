// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Invisible/System/SoundSystem.h"

#include "SoundObject.generated.h"

/**
* 音のオブジェクト
*/
UCLASS()
class INVISIBLE_API ASoundObject : public AActor
{
	GENERATED_BODY()

public:
	/**
    * コンストラクタ
    */
	ASoundObject();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	/**
    * 音を再生する
    */
	void playSound(FSoundData* sound, const FVector& location, AActor* soundGenerateSource);
	/**
    * 音の種類を取得する
    */
	ESoundType getSoundType() const { return soundType; }
    /**
    * 音の発生源のアクターを取得する
    */
	AActor* getSoundGenerateSource() const
	{
		return soundGenerateSourceActor;
	}

    /**
    * 現在この音源オブジェクトが使われていないか
    */
	bool unused() const { return !isPlaying; }

private:
	/**
    * 音の再生終了時のイベント
    */
	UFUNCTION()
	void onAudioFinished();

private:
	//!< 音の聞こえる範囲用コリジョン
	UPROPERTY(VisibleAnywhere)
	USphereComponent* soundHeardArea;
    //!< 音源
	UPROPERTY(VisibleAnywhere)
	UAudioComponent* audio;


private:
    //!< 音の発生源のアクター
	UPROPERTY()
	AActor* soundGenerateSourceActor;
	//!< 再生している音の種類
	ESoundType soundType;
    //!< 音を再生しているか
	bool isPlaying;
};
