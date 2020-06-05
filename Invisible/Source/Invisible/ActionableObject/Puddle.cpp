// Fill out your copyright notice in the Description page of Project Settings.

#include "Puddle.h"

#include "Engine.h"

//コンストラクタ
APuddle::APuddle()
{
	PrimaryActorTick.bCanEverTick = false;

	//メッシュコンポーネントを作成する
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

void APuddle::BeginPlay()
{
	Super::BeginPlay();
}

void APuddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
