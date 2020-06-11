// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UObject/NoExportTypes.h"

#include "ControllerVibration.generated.h"

/**
 *
 */
UCLASS()
class INVISIBLE_API UControllerVibration : public UObject
{
	GENERATED_BODY()
public:
	void StartVibration(float Duration, float Power);

private:
	//!< コントローラの振動ハンドル
	FDynamicForceFeedbackHandle DynamicForceFeedbackHandle;
};
