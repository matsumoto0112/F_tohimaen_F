// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundObject.h"

#include "Components/AudioComponent.h"
#include "Engine.h"

namespace
{
	const FString PATH = "/Game/System/SoundAttenuation.SoundAttenuation_C";
}

// Sets default values
ASoundObject::ASoundObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASoundObject::BeginPlay()
{
	Super::BeginPlay();
}

void ASoundObject::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (audio != nullptr)
	{
		audio->Stop();
	}
}

// Called every frame
void ASoundObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASoundObject::playSound(USoundBase* sound, USoundAttenuation* attenuation)
{
	if (sound == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Sound wave/cue is null!"));
		return;
	}

	UGameplayStatics::PlaySoundAtLocation(GetWorld(), sound, GetActorLocation(), 1.0f, 1.0f, 0.0f, attenuation);
}
