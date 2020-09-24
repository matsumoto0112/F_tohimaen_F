// Fill out your copyright notice in the Description page of Project Settings.


#include "LimitTimer.h"

// Sets default values
ALimitTimer::ALimitTimer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALimitTimer::BeginPlay()
{
	Super::BeginPlay();
	limitTimer = limitTime;
	
}

// Called every frame
void ALimitTimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	limitTimer = FMath::Clamp(limitTimer - DeltaTime, 0.0f, limitTime);
}

