// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * ステンシル値用ビット
 */
UENUM(BlueprintType, meta = (Bitflags))
enum class EStencilBitValue : uint8
{
    Default = 0x00 UMETA(DisplayName = "Default"),
    SilhouetteWhenEnemyWalkOnPuddle = 0x01 UMETA(DisplayName = "SilhouetteWhenEnemyWalkOnPuddle"),
    SilhouetteWhenEnemyPutOnWater = 0x02 UMETA(DisplayName = "SilhouetteWhenEnemyPutOnWater"),
    DebugEnemyVisible = 0x80 UMETA(DisplayName = "DebugEnemyVisible"),
};

ENUM_CLASS_FLAGS(EStencilBitValue)
