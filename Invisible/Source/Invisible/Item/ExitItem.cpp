// Fill out your copyright notice in the Description page of Project Settings.

#include "ExitItem.h"

#include "Engine.h"
#include "Invisible/System/MyGameInstance.h"
#include "Invisible/System/SoundSystem.h"

// Sets default values
AExitItem::AExitItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//メッシュコンポーネントを作成する
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	meshComponent->SetGenerateOverlapEvents(true);
	RootComponent = meshComponent;
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
	UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(ESoundType::Item_Get, this->GetActorLocation(), this);
	isGet = true;
	meshComponent->SetVisibility(false, true);
    meshComponent->SetGenerateOverlapEvents(false);
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
