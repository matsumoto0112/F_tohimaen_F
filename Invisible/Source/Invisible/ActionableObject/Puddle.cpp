// Fill out your copyright notice in the Description page of Project Settings.


#include "Puddle.h"
#include "Engine.h"

// Sets default values
APuddle::APuddle()
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

}

// Called when the game starts or when spawned
void APuddle::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APuddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

