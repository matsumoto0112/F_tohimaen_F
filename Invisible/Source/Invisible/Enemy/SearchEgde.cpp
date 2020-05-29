// Fill out your copyright notice in the Description page of Project Settings.

#include "SearchEgde.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"

#include <algorithm>

// �R���X�g���N�^
ASearchEgde::ASearchEgde()
{
	if (branch.Contains(this))
	{
		branch.Remove(this);
	}

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// �����ݒ�
void ASearchEgde::BeginPlay()
{
	Super::BeginPlay();
}

// �X�V
void ASearchEgde::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UKismetSystemLibrary::DrawDebugString(GetWorld(), GetActorLocation(), TEXT("PLAYER[0]"), nullptr, FLinearColor::Green, 0);
	SetBranch();
}

// �G���A���a�ݒ�
void ASearchEgde::SetRadius(float r)
{
	radius = r;
}

// �G���A���a�擾
float ASearchEgde::GetRadius() const
{
	return radius;
}

// ����ݒ�
void ASearchEgde::SetBranch()
{
	if (!debugDraw)
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
		UKismetSystemLibrary::DrawDebugSphere(GetWorld(), GetActorLocation(), radius, 12, FLinearColor::Blue, 0);
		//UKismetSystemLibrary::DrawDebugCapsule(GetWorld(),)
	}
}

// �����
TArray<ASearchEgde*> ASearchEgde::GetBranch() const
{
	return branch;
}