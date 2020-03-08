// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerHUD.h"
#include "Engine/Canvas.h"

//HUD‚Ì•`‰æ
void APlayerHUD::DrawHUD()
{
	Super::DrawHUD();

	if (!crossHairTexture)
		return;

	const FVector2D center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
}
