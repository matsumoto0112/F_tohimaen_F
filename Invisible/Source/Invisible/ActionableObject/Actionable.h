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
* ����\�ȃI�u�W�F�N�g�C���^�[�t�F�[�X
*/
UINTERFACE(Blueprintable)
class INVISIBLE_API UActionable : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

/**
 * ����\�ȃI�u�W�F�N�g�C���^�[�t�F�[�X
 */
class INVISIBLE_API IActionable
{
	GENERATED_IINTERFACE_BODY()

public:
	/**
    * ������J�n����
    */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void action();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    EActionType GetActionType() const;
};
