// Fill out your copyright notice in the Description page of Project Settings.

#include "ExitItem.h"

#include "Engine.h"

// Sets default values
AExitItem::AExitItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//メッシュコンポーネントを作成する
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = meshComponent;

	actionableArea = CreateDefaultSubobject<USphereComponent>(TEXT("ActionableArea"));
	actionableArea->InitSphereRadius(FMath::Abs(radius));
	actionableArea->SetCollisionProfileName("OverlapOnlyPawn");
	actionableArea->SetSimulatePhysics(false);
	actionableArea->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AExitItem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AExitItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	actionableArea->InitSphereRadius(FMath::Abs(radius));
}

void AExitItem::action_Implementation()
{
	Get();
	ItemAction();
}

void AExitItem::ItemAction_Implementation()
{
}

void AExitItem::Get()
{
	isGet = true;
	meshComponent->SetStaticMesh(nullptr);
}
void AExitItem::Use()
{
	isUse = true;
}

bool AExitItem::IsGet()
{
	return isGet;
}
bool AExitItem::IsUse()
{
	return isUse;
}
