// Fill out your copyright notice in the Description page of Project Settings.

#include "PuddleFactory.h"

#include "Engine.h"
#include "Math/RandomStream.h"

// Sets default values
APuddleFactory::APuddleFactory()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APuddleFactory::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APuddleFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//ランダムに水たまりをスポーンさせる
void APuddleFactory::spawnRandomPuddle(const FVector& location)
{
	const int32 index = random.RandRange(0, originPuddles.Num() - 1);
	AActor* a = GetWorld()->SpawnActor<AActor>(originPuddles[index]);
	a->SetActorLocation(location);
}
