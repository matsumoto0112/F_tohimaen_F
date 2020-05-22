// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"

#include "MyCheatManager.generated.h"

/**
 * ƒQ[ƒ€’†‚Ìƒ`[ƒgŠÇ—
 */
UCLASS()
class INVISIBLE_API UMyCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:
    /**
    * “G‚ğ‰Â‹‰»‚·‚éƒRƒ}ƒ“ƒh
    */
	UFUNCTION(BlueprintNativeEvent, exec)
	void VisibleEnemy();

	virtual void VisibleEnemy_Implementation();

    /**
    * “G‚ğ”ñ‰Â‹‰»‚·‚é
    */
	UFUNCTION(BlueprintNativeEvent, exec)
	void InvisibleEnemy();

	virtual void InvisibleEnemy_Implementation();

	/**
    * ’TõŒo˜H‚ğ‰Â‹‰»‚·‚é
    */
	UFUNCTION(BlueprintNativeEvent, exec)
	void VisibleSearch();

	virtual void VisibleSearch_Implementation();

	/**
    * ’TõŒo˜H‚ğ”ñ‰Â‹‰»‚·‚é
    */
	UFUNCTION(BlueprintNativeEvent, exec)
	void InvisibleSearch();

	virtual void InvisibleSearch_Implementation();
};
