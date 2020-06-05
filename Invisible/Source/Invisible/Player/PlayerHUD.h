// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Invisible/ActionableObject/Actionable.h"

#include "PlayerHUD.generated.h"

/**
 * プレイヤーのHUD
 */
UCLASS()
class INVISIBLE_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	/**
    * HUDの描画
    */
	virtual void DrawHUD() override;

	void SetCurrentNearlyObject(EActionType Type);

private:
	//!< クロスヘアの画像
	UPROPERTY(EditDefaultsOnly, Category = "Texture")
	UTexture2D* crossHairTexture;
	UPROPERTY(EditDefaultsOnly, Category = "Texture")
	TMap<EActionType, UTexture2D*> ActionTextures;
	UPROPERTY(EditDefaultsOnly, Category = "Texture")
	FVector2D TestTextureOffset;
	UPROPERTY()
	EActionType CurrentType;
};
