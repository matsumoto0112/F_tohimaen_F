// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * プレイヤーのアクションモード一覧
 */
UENUM(BlueprintType)
enum class EPlayerActionMode : uint8
{
    Default, //!< デフォルト
    Move, //!< 移動中
    IsInLocker, //!< ロッカーの中にいる
    GoingIntoLocker, //!< ロッカーの中に入っていく
    GetOutOfLocker, //!< ロッカーの中から出てくる
    IsDying, //!< 死亡中
};
ENUM_CLASS_FLAGS(EPlayerActionMode)
