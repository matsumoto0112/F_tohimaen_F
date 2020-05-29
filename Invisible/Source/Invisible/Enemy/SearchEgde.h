// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "SearchEgde.generated.h"

UCLASS()
class INVISIBLE_API ASearchEgde : public AActor
{
	GENERATED_BODY()

public:
	// コンストラクタ
	ASearchEgde();

protected:
	// 初期設定
	virtual void BeginPlay() override;

public:
	// 更新
	virtual void Tick(float DeltaTime) override;
	// Tickの処理をエディタ上でも行うようにする
	virtual bool ShouldTickIfViewportsOnly() const override { return true; };

	// エリア半径設定
	void SetRadius(float r);
	// エリア半径取得
	float GetRadius() const;
	// 分岐設定
	void SetBranch();
	// 分岐先
	TArray<ASearchEgde*> GetBranch() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// 範囲半径
	float radius = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// 分岐
	TArray<ASearchEgde*> branch;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// デバッグ表示
	bool debugDraw;
};
