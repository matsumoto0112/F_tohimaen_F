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
	// コンストラクタ
	SearchCourse(ASearchEgde* baseSearch);
	// コンストラクタ
	SearchCourse(ASearchEgde* baseSearch, SearchCourse* parentSearch);

	// 現在地
	ASearchEgde* GetBaseSearch() const;
	// 移動先設定
	TArray<SearchCourse*> SetChild(const TArray<SearchCourse*> remove);
	// 経路取得
	TArray<SearchCourse*> GetParents();
	// 原点取得
	SearchCourse* MostParent();
	// 原点から現在地までの距離
	double Length();

private:
	// 経路取得
	TArray<SearchCourse*> GetParents(TArray<SearchCourse*> parents);

private:
	// 現在地
	ASearchEgde* baseSearch;
	// 移動元
	SearchCourse* parentSearch;
	// 移動先
	TArray<SearchCourse*> childSearch;
};
