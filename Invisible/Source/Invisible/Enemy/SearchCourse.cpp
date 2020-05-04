// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchCourse.h"

SearchCourse::SearchCourse(ASearchEgde* baseSearch)
    : baseSearch(baseSearch), parentSearch(nullptr)
{
}

SearchCourse::SearchCourse(ASearchEgde* baseSearch, SearchCourse* parentSearch)
    : baseSearch(baseSearch), parentSearch(parentSearch)
{
}

ASearchEgde* SearchCourse::GetBaseSearch() const
{
	return baseSearch;
}

TArray<SearchCourse*> SearchCourse::SetChild(const TArray<SearchCourse*> remove)
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

		SearchCourse* course = new SearchCourse(branch[index],this);
		childs.Add(course);
	}

	childSearch = childs;
	return childSearch;
}

TArray<SearchCourse*> SearchCourse::GetParents()
{
	TArray<SearchCourse*> parents;
	return GetParents(parents);
}

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
