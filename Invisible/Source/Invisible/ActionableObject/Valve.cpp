// Fill out your copyright notice in the Description page of Project Settings.

#include "Valve.h"

#include "Engine.h"
#include "Sprinkler.h"

// Sets default values
AValve::AValve(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
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
	if (GEngine)
	{
        for (auto&& sp : chainSprinklers)
        {
            IActionable::Execute_action(sp);
        }
	}
}
