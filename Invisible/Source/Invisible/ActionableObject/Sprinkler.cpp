// Fill out your copyright notice in the Description page of Project Settings.

#include "Sprinkler.h"

#include "Engine.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ASprinkler::ASprinkler()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMesh>(TEXT("Mesh"));
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	if (meshComponent)
	{
		RootComponent = meshComponent;
		meshComponent->SetStaticMesh(mesh);
	}

	particleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComponent"));
	if (particleComponent)
	{
		particleComponent->AttachToComponent(RootComponent,
		    FAttachmentTransformRules(
		        EAttachmentRule::KeepRelative,
		        EAttachmentRule::KeepRelative,
		        EAttachmentRule::KeepRelative,
		        false));
	}
}

// Called when the game starts or when spawned
void ASprinkler::BeginPlay()
{
	Super::BeginPlay();

	//パーティクルをゲーム開始時に停止させる
	if (particleComponent)
	{
		particleComponent->SetEmitterEnable(particleEmitterName, false);
	}
}

void ASprinkler::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorldTimerManager().ClearAllTimersForObject(this);
}

void ASprinkler::action_Implementation()
{
	if (GEngine)
	{
		particleComponent->SetEmitterEnable(particleEmitterName, true);

        //タイマーが稼働中なら上書きする
		if (timerHandle.IsValid())
		{
			GetWorldTimerManager().ClearTimer(timerHandle);
		}
        //一定時間後にパーティクルを無効にする
		GetWorldTimerManager().SetTimer(timerHandle, [&]() {
			particleComponent->SetEmitterEnable(particleEmitterName, false);
		},
		    activeTime, false);
	}
}

// Called every frame
void ASprinkler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
