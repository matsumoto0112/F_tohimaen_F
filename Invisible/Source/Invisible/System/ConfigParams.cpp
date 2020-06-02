// Fill out your copyright notice in the Description page of Project Settings.

#include "ConfigParams.h"

#include "Engine.h"

UConfigParams::UConfigParams()
{
	this->SaveSlotName = TEXT("Config");
	this->UserIndex = 0;
}

void UConfigParams::SetDefault()
{
	BGMVolume = 100.0f;
	SEVolume = 100.0f;
	Sensitivity = 100.0f;
}

void UConfigParams::SetConfigData()
{
	UGameplayStatics::SaveGameToSlot(this, SaveSlotName, UserIndex);
}
