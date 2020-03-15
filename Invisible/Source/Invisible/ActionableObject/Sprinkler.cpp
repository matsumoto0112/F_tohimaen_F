// Fill out your copyright notice in the Description page of Project Settings.

#include "Sprinkler.h"

#include "Engine.h"

// Sets default values
ASprinkler::ASprinkler()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASprinkler::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASprinkler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//スプリンクラーを動作させる
void ASprinkler::action_Implementation()
{
	//とりあえずメッセージを出す
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "run sprinkler");
	}
}
