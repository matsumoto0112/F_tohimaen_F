// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerHUD.h"
#include "Engine/Canvas.h"

//HUD�̕`��
void APlayerHUD::DrawHUD()
{
	Super::DrawHUD();

	if (!crossHairTexture)
		return;

	//�L�����o�X�̒��S���W����N���X�w�A�摜�̔z�u���W�����肷��
	const FVector2D center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	const FVector2D crossHairPosition = center - FVector2D(crossHairTexture->GetSurfaceWidth() * 0.5f, crossHairTexture->GetSurfaceHeight() * 0.5f);

	FCanvasTileItem tileItem(crossHairPosition, crossHairTexture->Resource, FLinearColor::White);
	tileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(tileItem);
}
