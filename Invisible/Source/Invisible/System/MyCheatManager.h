// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"

#include "MyCheatManager.generated.h"

/**
 * ゲーム中のチート管理
 */
UCLASS()
class INVISIBLE_API UMyCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:
    /**
    * 敵を可視化するコマンド
    */
	UFUNCTION(BlueprintNativeEvent, exec)
	void VisibleEnemy();

	virtual void VisibleEnemy_Implementation();

    /**
    * 敵を非可視化する
    */
	UFUNCTION(BlueprintNativeEvent, exec)
	void InvisibleEnemy();

	virtual void InvisibleEnemy_Implementation();
};
