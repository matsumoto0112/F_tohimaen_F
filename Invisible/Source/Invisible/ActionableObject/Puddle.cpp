// Fill out your copyright notice in the Description page of Project Settings.

#include "Puddle.h"

#include "Engine.h"

//コンストラクタ
APuddle::APuddle()
{
	PrimaryActorTick.bCanEverTick = true;

	//メッシュコンポーネントを作成する
	mesh = CreateDefaultSubobject<UStaticMesh>(TEXT("Mesh"));
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	if (meshComponent)
	{
		RootComponent = meshComponent;
		meshComponent->SetStaticMesh(mesh);
	}
}

void APuddle::BeginPlay()
{
	Super::BeginPlay();
}

void APuddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
