// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SearchEgde.h"

#include "SearchManager.generated.h"

class SearchCourse;

UCLASS()
class INVISIBLE_API ASearchManager : public AActor
{
	GENERATED_BODY()

public:
	// コンストラクタ
	ASearchManager();

protected:
	// 初期更新
	virtual void BeginPlay() override;

public:
	// 更新
	virtual void Tick(float DeltaTime) override;

	// 経路設定
	TArray<FVector> Course(AActor* actor) const;
	//経路設定
	TArray<FVector> Course(AActor* start, AActor* end) const;
	//経路設定
	TArray<FVector> Course(FVector start, FVector end) const;
	//追跡経路設定
	TArray<FVector> ChaseCourse(AActor* start, AActor* end) const;
	//追跡経路設定
	TArray<FVector> ChaseCourse(FVector start, FVector end) const;
	//　エリア半径取得
	float GetRadius() const;

	// 近辺の分岐箇所取得
	FVector NearSearchPosition(AActor* actor) const;
	// 近辺の分岐箇所取得
	FVector NearSearchPosition(FVector point) const;

	// 移動箇所との間に障害物があるか判定
	bool DirectionSearch(AActor* actor, FVector near) const;
	// 移動箇所との間に障害物があるか判定
	bool DirectionSearch(AActor* actor, ASearchEgde* near) const;

private:
	// 近辺の分岐箇所取得
	ASearchEgde* NearSearch(AActor* actor) const;
	// 近辺の分岐箇所取得
	ASearchEgde* NearSearch(FVector point) const;
	// ランダムに分岐箇所取得
	ASearchEgde* GetRandomSearch(ASearchEgde* remove) const;
	// 「start >> end」に向かう経路設定
	TArray<FVector> Course(SearchCourse* start, ASearchEgde* end) const;


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// 探索箇所
	TArray<ASearchEgde*> search;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// エリア半径
	float radius = 100.0f;

	// プレイヤー
	AActor* player;
	// 敵
	TArray<AActor*> enemys;
};
