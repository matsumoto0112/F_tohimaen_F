// Fill out your copyright notice in the Description page of Project Settings.

#include "ControllerVibration.h"

#include "Engine.h"

void UControllerVibration::StartVibration(float Duration, float Power)
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	DynamicForceFeedbackHandle = PlayerController->PlayDynamicForceFeedback(Power, Duration, true, true, true, true,
	    EDynamicForceFeedbackAction::Start, DynamicForceFeedbackHandle);
}
