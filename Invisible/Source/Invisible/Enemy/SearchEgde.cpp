// Fill out your copyright notice in the Description page of Project Settings.

#include "SearchEgde.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"

#include <algorithm>

// コンストラクタ
ASearchEgde::ASearchEgde()
{
	if (branch.Contains(this))
	{
		branch.Remove(this);
	}

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// 初期設定
void ASearchEgde::BeginPlay()
{
	Super::BeginPlay();
}

// 更新
void ASearchEgde::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UKismetSystemLibrary::DrawDebugString(GetWorld(), GetActorLocation(), TEXT("PLAYER[0]"), nullptr, FLinearColor::Green, 0);
	SetBranch();
}

// エリア半径設定
void ASearchEgde::SetRadius(float r)
{
	radius = r;
}

// エリア半径取得
float ASearchEgde::GetRadius() const
{
	return radius;
}

// 分岐設定
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

// 分岐先
TArray<ASearchEgde*> ASearchEgde::GetBranch() const
{
	return branch;
}