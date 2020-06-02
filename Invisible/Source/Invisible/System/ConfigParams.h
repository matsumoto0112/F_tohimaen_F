// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "UObject/NoExportTypes.h"

#include "ConfigParams.generated.h"

/**
 *
 */
UCLASS()
class INVISIBLE_API UConfigParams : public USaveGame
{
	GENERATED_BODY()

public:
	/**
* コンストラクタ
*/
	UConfigParams();
	/**
    * デフォルトに設定する
    */
	void SetDefault();

	UFUNCTION(BlueprintSetter)
	void SetSensitivity(float Value) { Sensitivity = Value; }
	UFUNCTION(BlueprintGetter)
	float GetSensitivity() const { return Sensitivity; }

	UFUNCTION(BlueprintCallable, Category = "Config")
	void SetConfigData();

public:
	UPROPERTY(VisibleAnywhere, BlueprintSetter = SetSensitivity, BlueprintGetter = GetSensitivity, Category = "Basics")
	float Sensitivity;

	UPROPERTY(VisibleAnywhere, Category = "Basics")
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = "Basics")
	uint32 UserIndex;
};
