// Fill out your copyright notice in the Description page of Project Settings.

#include "SearchEgde.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"

#include <algorithm>

// Sets default values
ASearchEgde::ASearchEgde()
{
	if (branch.Contains(this))
	{
		branch.Remove(this);
	}

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASearchEgde::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASearchEgde::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UKismetSystemLibrary::DrawDebugString(GetWorld(), GetActorLocation(), TEXT("PLAYER[0]"), nullptr, FLinearColor::Green, 0);
	SetBranch();
}

bool ASearchEgde::ShouldTickIfViewportsOnly() const
{
	return true;
}

TArray<ASearchEgde*> ASearchEgde::GetBranch() const
{
	return branch;
}

float ASearchEgde::GetRadius() const
{
	return radius;
}

void ASearchEgde::SetRadius(float r) {
	radius = r;
}

void ASearchEgde::SetBranch()
{
	if (debugDraw==0)
	{
		return;
	}

	for (int32 index = 0; index < branch.Num(); index++)
	{
		if ((branch[index] == nullptr))
		{
			continue;
		}
		auto start = GetActorLocation() + FVector::UpVector * radius;
		auto end = branch[index]->GetActorLocation() + FVector::UpVector * radius;
		UKismetSystemLibrary::DrawDebugLine(GetWorld(), start, end, FLinearColor::Blue, 0);
		UKismetSystemLibrary::DrawDebugSphere(GetWorld(), GetActorLocation(), radius,12, FLinearColor::Blue, 0);
		//UKismetSystemLibrary::DrawDebugCapsule(GetWorld(),)
	}
}
