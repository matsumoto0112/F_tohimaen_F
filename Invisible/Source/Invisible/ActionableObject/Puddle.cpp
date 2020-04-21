// Fill out your copyright notice in the Description page of Project Settings.

#include "Puddle.h"

#include "Engine.h"

//コンストラクタ
APuddle::APuddle()
{
	PrimaryActorTick.bCanEverTick = true;

	//メッシュコンポーネントを作成する
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = meshComponent;
}

void APuddle::BeginPlay()
{
	Super::BeginPlay();
}

void APuddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
