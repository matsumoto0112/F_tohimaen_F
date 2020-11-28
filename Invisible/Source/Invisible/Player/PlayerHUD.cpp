// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerHUD.h"

#include "Engine/Canvas.h"

#include <Kismet/GameplayStatics.h>

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();
	CurrentType = EActionType::None;

	check(crossHairTexture);
}

//HUDの描画
void APlayerHUD::DrawHUD()
{
	Super::DrawHUD();

	//キャンバスの中心座標からクロスヘア画像の配置座標を決定する
	const FVector2D center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	const FVector2D crossHairPosition = center - FVector2D(crossHairTexture->GetSurfaceWidth() * 0.5f, crossHairTexture->GetSurfaceHeight() * 0.5f);

	FCanvasTileItem tileItem(crossHairPosition, crossHairTexture->Resource, FLinearColor::White);
	tileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(tileItem);

	PrintActionTexture();
	PrintTextUI();
}

void APlayerHUD::SetCurrentNearlyObject(EActionType Type)
{
	CurrentType = Type;
}

void APlayerHUD::PrintActionTexture()
{
	if (CurrentType == EActionType::None)
		return;

	UTexture2D* Texture = ActionTextures[CurrentType];
	const FVector2D center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	const FVector2D TestTexturePosition = center - FVector2D(Texture->GetSurfaceWidth() * 0.5f, Texture->GetSurfaceHeight() * 0.5f) + TestTextureOffset;
	FCanvasTileItem Item(TestTexturePosition, Texture->Resource, FLinearColor::White);
	Item.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(Item);
}

void APlayerHUD::PrintTextUI()
{
	if (CurrentText.CurrentPrintTime <= 0.0f)
	{
		return;
	}

	const FVector2D center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	const FVector2D TestTexturePosition = center - FVector2D(CurrentText.CurrentTexture->GetSurfaceWidth() * 0.5f, CurrentText.CurrentTexture->GetSurfaceHeight() * 0.5f) + TextOffset;
	FCanvasTileItem Item(TestTexturePosition, CurrentText.CurrentTexture->Resource, FLinearColor::White);
	Item.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(Item);

	CurrentText.CurrentPrintTime -= GetWorld()->DeltaTimeSeconds;
}

void APlayerHUD::SpawnTextUI(ETextType TextType)
{
	check(TextTextures.Contains(TextType));

	CurrentText.CurrentTexture = TextTextures[TextType];
	CurrentText.CurrentPrintTime = PrintTextTime;
}
