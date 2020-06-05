// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerHUD.h"

#include "Engine/Canvas.h"

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();
	CurrentType = EActionType::None;

	check(crossHairTexture);
}

//HUD�̕`��
void APlayerHUD::DrawHUD()
{
	Super::DrawHUD();

	//�L�����o�X�̒��S���W����N���X�w�A�摜�̔z�u���W�����肷��
	const FVector2D center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	const FVector2D crossHairPosition = center - FVector2D(crossHairTexture->GetSurfaceWidth() * 0.5f, crossHairTexture->GetSurfaceHeight() * 0.5f);

	FCanvasTileItem tileItem(crossHairPosition, crossHairTexture->Resource, FLinearColor::White);
	tileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(tileItem);

	if (CurrentType == EActionType::None)
		return;

	UTexture2D* Texture = ActionTextures[CurrentType];
	const FVector2D TestTexturePosition = center - FVector2D(Texture->GetSurfaceWidth() * 0.5f, Texture->GetSurfaceHeight() * 0.5f) + TestTextureOffset;
	FCanvasTileItem Item(TestTexturePosition, Texture->Resource, FLinearColor::White);
	Canvas->DrawItem(Item);
}

void APlayerHUD::SetCurrentNearlyObject(EActionType Type)
{
	CurrentType = Type;
}
