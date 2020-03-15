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
 * ����\�ȃI�u�W�F�N�g�C���^�[�t�F�[�X
 */
class INVISIBLE_API IActionable
{
	GENERATED_IINTERFACE_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/**
    * ������J�n����
    */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void action();
};
