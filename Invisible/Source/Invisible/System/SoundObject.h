// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "SoundObject.generated.h"

struct FSoundData;
enum class ESoundType : uint8;

UCLASS()
class INVISIBLE_API ASoundObject : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASoundObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void playSound(FSoundData* sound, USoundAttenuation* attenuation);

    ESoundType getSoundType() const { return soundType; }
private:
	UPROPERTY(VisibleAnywhere)
	USphereComponent* soundHeardArea;

private:
	UAudioComponent* audio;
    ESoundType soundType;
};
