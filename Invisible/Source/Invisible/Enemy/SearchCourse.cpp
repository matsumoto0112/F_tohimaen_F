// Fill out your copyright notice in the Description page of Project Settings.

#include "SearchCourse.h"

#include "Kismet/GameplayStatics.h"

#include <Engine.h>

// コンストラクタ
SearchCourse::SearchCourse(ASearchEgde* baseSearch)
    : baseSearch(baseSearch), parentSearch(nullptr)
{
}

// コンストラクタ
SearchCourse::SearchCourse(ASearchEgde* baseSearch, SearchCourse* parentSearch)
    : baseSearch(baseSearch), parentSearch(parentSearch)
{
}

// 現在地
ASearchEgde* SearchCourse::GetBaseSearch() const
{
	return baseSearch;
}

// 移動先設定
TArray<SearchCourse*> SearchCourse::SetChild(const TArray<SearchCourse*> remove, FCollisionQueryParams params)
{
	if (baseSearch == nullptr)
	{
		return childSearch;
	}
	TArray<ASearchEgde*> branch = baseSearch->GetBranch();
	TArray<SearchCourse*> childs;

	for (int index = 0; index < branch.Num(); index++)
	{
		bool isrem = false;
		for (int r = 0; r < remove.Num(); r++)
		{
			if (remove[r]->baseSearch == branch[index])
			{
				isrem = true;
			}
		}
		if (isrem)
		{
			continue;
		}

		FHitResult hit;
		auto world = baseSearch->GetWorld();
		auto start = GetBaseSearch()->GetActorLocation();
		auto end = branch[index]->GetActorLocation();
		start.Z = 50;
		end.Z = 50;

		if (world->LineTraceSingleByChannel(hit, start, end,
		        ECollisionChannel::ECC_Pawn, params))
		{
			continue;
		}

		SearchCourse* course = new SearchCourse(branch[index], this);
		childs.Add(course);
	}

	childSearch = childs;
	return childSearch;
}

// 経路取得
TArray<SearchCourse*> SearchCourse::GetParents()
{
	TArray<SearchCourse*> parents;
	return GetParents(parents);
}

// 原点取得
SearchCourse* SearchCourse::MostParent()
{
	if (parentSearch == nullptr)
	{
		return this;
	}
	else
	{
		return parentSearch->MostParent();
	}
}

// 原点から現在地までの距離
double SearchCourse::Length()
{
	auto parents = GetParents();
	double length = 0;
	for (int i = 0; i < parents.Num() - 1; i++)
	{
		auto child = parents[i]->baseSearch->GetActorLocation();
		auto parent = parents[i + 1]->baseSearch->GetActorLocation();
		length += (parent - child).Size();
	}
	return length;
}

// 経路取得
TArray<SearchCourse*> SearchCourse::GetParents(TArray<SearchCourse*> parents)
{
	parents.Add(this);

	if (parentSearch == nullptr)
	{
		//parents.IndexOfByKey(this);
		auto result = TArray<SearchCourse*>();
		for (int i = 0; i < parents.Num(); i++)
		{
			result.Add(parents[parents.Num() - i - 1]);
		}
		return result;
	}
	return parentSearch->GetParents(parents);
}
