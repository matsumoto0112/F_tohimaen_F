// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

/**
 *
 */
UCLASS()
class INVISIBLE_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:
	/**
    * HUD‚Ì•`‰æ
    */
	virtual void DrawHUD() override;

private:
	UPROPERTY(EditDefaultsOnly)
	UTexture2D* crossHairTexture; //!< ƒNƒƒXƒwƒA‚Ì‰æ‘œ
};
