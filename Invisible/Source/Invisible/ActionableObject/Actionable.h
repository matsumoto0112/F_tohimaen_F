// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "Actionable.generated.h"

UENUM(BlueprintType)
enum class EActionType : uint8
{
    None,
	Valve,
	Locker,
	Item,
	Door_Close,
	Door_Open,
};

/**
* 動作可能なオブジェクトインターフェース
*/
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

public:
	/**
    * 動作を開始する
    */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void action();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    EActionType GetActionType() const;
};
