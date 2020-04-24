// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SearchEgde.h"

/**
 * 
 */
class INVISIBLE_API SearchCourse
{
public:
	SearchCourse(ASearchEgde* baseSearch);
	SearchCourse(ASearchEgde* baseSearch, SearchCourse* parentSearch);

	ASearchEgde* GetBaseSearch() const;

	TArray<SearchCourse*> SetChild(const TArray<SearchCourse*> remove);
	TArray<SearchCourse*> GetParents();
	SearchCourse* MostParent();
	double Length();

private:
	TArray<SearchCourse*> GetParents(TArray<SearchCourse*> parents);

private:
	ASearchEgde* baseSearch;
	SearchCourse* parentSearch;
	TArray<SearchCourse*> childSearch;
};
