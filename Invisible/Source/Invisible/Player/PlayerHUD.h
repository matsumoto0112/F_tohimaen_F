// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "PlayerHUD.generated.h"

/**
 * プレイヤーのHUD
 */
UCLASS()
class INVISIBLE_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:
	/**
    * HUDの描画
    */
	virtual void DrawHUD() override;

private:
	//!< クロスヘアの画像
	UPROPERTY(EditDefaultsOnly, Category = "Texture")
	UTexture2D* crossHairTexture;
};
