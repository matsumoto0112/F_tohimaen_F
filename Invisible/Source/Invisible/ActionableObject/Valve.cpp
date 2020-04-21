// Fill out your copyright notice in the Description page of Project Settings.

#include "Valve.h"

#include "Engine.h"
#include "Invisible/System/MyGameInstance.h"
#include "Invisible/System/SoundSystem.h"
#include "Sprinkler.h"

// Sets default values
AValve::AValve()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = meshComponent;

	actionableArea = CreateDefaultSubobject<USphereComponent>(TEXT("ActionableArea"));
	actionableArea->InitSphereRadius(50.0f);
	actionableArea->SetCollisionProfileName("OverlapOnlyPawn");
	actionableArea->SetSimulatePhysics(false);
	actionableArea->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AValve::BeginPlay()
{
	Super::BeginPlay();

	//連携しているスプリンクラーを探す
	TArray<AActor*> sprinklers;
	UGameplayStatics::GetAllActorsOfClass(this->GetWorld(), ASprinkler::StaticClass(), sprinklers);
	for (auto&& aSprinker : sprinklers)
	{
		ASprinkler* sprinkler = Cast<ASprinkler>(aSprinker);
		if (sprinkler->GetSprinklerID() == sprinklerID)
		{
			chainSprinklers.Add(sprinkler);
		}
	}
}

// Called every frame
void AValve::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//スプリンクラーを動作させる
void AValve::action_Implementation()
{
	   //対応するすべてのスプリンクラーを作動させる
	for (auto&& sp : chainSprinklers)
	{
		IActionable::Execute_action(sp);
	}

	//バルブ音再生
	UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(ESoundType::Valve, GetActorLocation());
}
