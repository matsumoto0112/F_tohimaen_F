// Fill out your copyright notice in the Description page of Project Settings.

#include "SearchManager.h"

#include "Components/SphereComponent.h"
#include "Invisible/Player/PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "SearchCourse.h"

// コンストラクタ
ASearchManager::ASearchManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	for (int i = 0; i < search.Num(); i++)
	{
		search[i]->SetRadius(radius);
	}
}

// 初期更新
void ASearchManager::BeginPlay()
{
	Super::BeginPlay();

	auto actor = UGameplayStatics::GetActorOfClass(GetWorld(), APlayerCharacter::StaticClass());
	player = (actor == nullptr) ? nullptr : actor;
}

// 更新
void ASearchManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

	// 経路設定
TArray<FVector> ASearchManager::Course(AActor* actor) const
{
	auto near = NearSearch(actor);
	if (near == nullptr)
	{
		return TArray<FVector>();
	}
	auto start = new SearchCourse(near);
	auto end = GetRandomSearch(start->GetBaseSearch());

	return Course(start, end);
}

	// 経路設定
TArray<FVector> ASearchManager::Course(AActor* start, AActor* end) const
{
	auto nearStart = NearSearch(start);
	auto nearEnd = NearSearch(end);
	if ((nearStart == nullptr) || (nearEnd == nullptr))
	{
		return TArray<FVector>();
	}
	auto searchStart = new SearchCourse(nearStart);
	auto searchEnd = (new SearchCourse(nearEnd))->GetBaseSearch();

	return Course(searchStart, searchEnd);
}

	// 経路設定
TArray<FVector> ASearchManager::Course(SearchCourse* start, ASearchEgde* end) const
{
	auto searched = TArray<SearchCourse*>();
	searched.Add(start);

	for (int i = 0; i < searched.Num(); i++)
	{
		auto child = searched[i]->SetChild(searched);
		for (int c = 0; c < child.Num(); c++)
		{
			searched.Add(child[c]);
		}

		if (searched[i]->GetBaseSearch() == end)
		{
			auto result = TArray<FVector>();
			auto parents = searched[i]->GetParents();
			for (int p = 0; p < parents.Num(); p++)
			{
				auto baseSearch = parents[p]->GetBaseSearch();
				auto pos = baseSearch->GetActorLocation();
				result.Add(pos);
			}
			return result;
		}
	}
	return TArray<FVector>();
}

	//　エリア半径取得
float ASearchManager::GetRadius() const
{
	return radius;
}

	// 近辺の分岐箇所取得
FVector ASearchManager::NearSearchPosition(AActor* actor) const
{
	return NearSearchPosition(actor->GetActorLocation());
}
// 近辺の分岐箇所取得
FVector ASearchManager::NearSearchPosition(FVector point) const
{
	auto near = NearSearch(point);
	if (near == nullptr)
	{
		return point;
	}
	return near->GetActorLocation();
}

	// 移動箇所との間に障害物があるか判定
bool ASearchManager::DirectionSearch(AActor* actor, FVector near) const
{
	return DirectionSearch(actor, NearSearch(near));
}

	// 移動箇所との間に障害物があるか判定
bool ASearchManager::DirectionSearch(AActor* actor, ASearchEgde* near) const
{
	auto point = actor->GetActorLocation();
	auto forward = actor->GetActorForwardVector();

	forward = (FVector(forward.X, forward.Y, 0)).GetSafeNormal();
	auto vector = (point - near->GetActorLocation());
	vector = FVector(vector.X, vector.Y, 0).GetSafeNormal();

	FHitResult hit;
	FCollisionQueryParams params;
	params.AddIgnoredActor(this);
	params.AddIgnoredActor(actor);

	auto start = near->GetActorLocation();
	auto end = actor->GetActorLocation();
	start.Z = actor->GetActorLocation().Z;
	return !(GetWorld()->LineTraceSingleByChannel(hit, start, end,
	    ECollisionChannel::ECC_Pawn, params));
}

	// 近辺の分岐箇所取得
ASearchEgde* ASearchManager::NearSearch(AActor* actor) const
{
	int resultIndex = -1;
	for (int i = 0; i < search.Num(); i++)
	{
		auto aLoc = actor->GetActorLocation();
		auto sLoc = search[i]->GetActorLocation();
		auto length = (sLoc - aLoc).Size();

		if (resultIndex < 0)
		{
			resultIndex = 0;
		}
		auto rLoc = search[resultIndex]->GetActorLocation();
		auto rLength = (rLoc - aLoc).Size();
		auto flag = (length < rLength);
		if (length < rLength)
		{
			FHitResult hit;
			FCollisionQueryParams params;
			params.AddIgnoredActor(actor);
			if (player != nullptr)
			{
				params.AddIgnoredActor(player);
				aLoc.Z = player->GetActorLocation().Z;
				sLoc.Z = player->GetActorLocation().Z;
			}

			if (!GetWorld()->LineTraceSingleByChannel(hit, aLoc, sLoc,
			        ECollisionChannel::ECC_Pawn, params))
			{
				resultIndex = i;
			}
		}
	}
	return (resultIndex < 0) ? nullptr : search[resultIndex];
}
// 近辺の分岐箇所取得
ASearchEgde* ASearchManager::NearSearch(FVector point) const
{
	int resultIndex = -1;
	for (int i = 0; i < search.Num(); i++)
	{
		auto aLoc = point;
		auto sLoc = search[i]->GetActorLocation();
		auto length = (sLoc - aLoc).Size();

		if (resultIndex < 0)
		{
			resultIndex = 0;
		}
		auto rLoc = search[resultIndex]->GetActorLocation();
		auto rLength = (rLoc - aLoc).Size();
		auto flag = (length < rLength);
		if (length < rLength)
		{
			resultIndex = i;
		}
	}
	return (resultIndex < 0) ? nullptr : search[resultIndex];
}

	// ランダムに分岐箇所取得
ASearchEgde* ASearchManager::GetRandomSearch(ASearchEgde* remove) const
{
	auto s = TArray<ASearchEgde*>(search);
	if (s.Contains(remove))
	{
		s.Remove(remove);
	}

	switch (s.Num())
	{
	case 0:
		return nullptr;
	case 1:
		return s[0];
	default:
		return s[FMath::FRandRange(0, s.Num())];
	}
}
