// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Invisible/ActionableObject/Actionable.h"

#include "PlayerHUD.generated.h"

UENUM(BlueprintType)
enum class ETextType : uint8
{
	START_3M,
	START_4M,
	START_5M,
	LIMIT_240,
	LIMIT_180,
	LIMIT_120,
	LIMIT_60,
	GET_KEYITEM,
};

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

	void PrintActionTexture();
	void PrintTextUI();

	UFUNCTION(BlueprintCallable, Category = "PlayerHUD")
	void SpawnTextUI(ETextType TextType);

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

	UPROPERTY(EditDefaultsOnly, Category = "Texture")
	TMap<ETextType, UTexture2D*> TextTextures;
	UPROPERTY(EditDefaultsOnly, Category = "Texture")
	float PrintTextTime = 5.0f;
	UPROPERTY(EditDefaultsOnly, Category = "Texture")
	FVector2D TextOffset;

	struct TextTexture
	{
		UTexture2D* CurrentTexture;
		float CurrentPrintTime;
	};
	TextTexture CurrentText;
};
