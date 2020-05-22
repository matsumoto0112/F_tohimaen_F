// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * ステンシル値用ビット
 */
UENUM(BlueprintType, meta = (Bitflags))
enum class EStencilBitValue : uint8
{
    Default = 0 UMETA(DisplayName = "Default"),
    SilhouetteWhenEnemyWalkOnPuddle = 1 << 0 UMETA(DisplayName = "SilhouetteWhenEnemyWalkOnPuddle"),
    SilhouetteWhenEnemyPutOnWater = 1 << 2 UMETA(DisplayName = "SilhouetteWhenEnemyPutOnWater"),
    DebugEnemyVisible = 1 << 7 UMETA(DisplayName = "DebugEnemyVisible"),
};

ENUM_CLASS_FLAGS(EStencilBitValue)
