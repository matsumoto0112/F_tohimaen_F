// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundObject.h"

#include "Engine.h"
#include "Invisible/System/SoundSystem.h"

namespace
{
	const FString PATH = "/Game/System/SoundAttenuation.SoundAttenuation_C";
}

// Sets default values
ASoundObject::ASoundObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	soundHeardArea = CreateDefaultSubobject<USphereComponent>(TEXT("SoundHeardArea"));
	soundHeardArea->InitSphereRadius(100.0f);
	soundHeardArea->SetupAttachment(this->RootComponent);
	soundHeardArea->SetSimulatePhysics(false);
	soundHeardArea->SetCollisionProfileName("OverlapOnlyPawn");
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

void ASoundObject::playSound(FSoundData* sound)
{
	if (!sound)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Sound data is null!"));
		return;
	}
	this->soundType = sound->soundType;

	UGameplayStatics::PlaySoundAtLocation(GetWorld(), sound->sound, GetActorLocation(), 1.0f, 1.0f, 0.0f, sound->soundAttenuation);
	const USoundAttenuation* atte = sound->soundAttenuation;
	float radius = (atte->Attenuation.FalloffDistance + atte->Attenuation.AttenuationShapeExtents.Size());
	soundHeardArea->SetSphereRadius(radius);
}
