// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"

#include "Engine.h"

#include <string>

// Sets default values
AEnemy::AEnemy()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//mesh = CreateDefaultSubobject<UStaticMesh>(TEXT("Mesh"));
	//meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	//if (meshComponent)
	//{
	//	RootComponent = meshComponent;
	//	meshComponent->SetStaticMesh(mesh);
	//}
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Moving(DeltaTime);
	SearchCourse();

	//meshComponent->SetScalarParameterValueOnMaterials("reflection", reflection);
}

void AEnemy::Moving(float DeltaTime)
{
	//FVector location = GetActorLocation();
	//location.X += 10.0f;
	//SetActorLocation(location);
	if (courses.Num() <= 0)
	{
		return;
	}

	auto pos = GetActorLocation();
	auto vector = (courses[0] - pos);
	auto length = (speed < vector.Size()) ? speed : vector.Size();
	//vector.Normalize();
	auto nor = vector.GetSafeNormal();

	auto mov = nor * length * DeltaTime;
	mov = (mov.Size() < vector.Size()) ? mov : vector;

	SetActorLocation(pos + mov);
	auto right = GetActorRightVector();
	right.Normalize();
	auto r = nor + (nor - right) * DeltaTime;
	SetActorRotation(r.Rotation());

	if (vector.Size() <= searchManager->GetRadius())
	{
		courses.RemoveAt(0);
	}
}

void AEnemy::SearchCourse()
{
	auto s = std::to_string(courses.Num());
	auto str = FString::FString(s.c_str());
	UKismetSystemLibrary::DrawDebugString(GetWorld(), GetActorLocation(), str, nullptr, FLinearColor::Black, 0);
	if (0 < courses.Num())
	{
		return;
	}
	if (searchManager == nullptr)
	{
		return;
	}

	courses = searchManager->Course(this);
}