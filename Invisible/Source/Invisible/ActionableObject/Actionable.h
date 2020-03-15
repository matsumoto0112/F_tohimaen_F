// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "Actionable.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable)
class INVISIBLE_API UActionable : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

/**
 * 動作可能なオブジェクトインターフェース
 */
class INVISIBLE_API IActionable
{
	GENERATED_IINTERFACE_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/**
    * 動作を開始する
    */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void action();
};
