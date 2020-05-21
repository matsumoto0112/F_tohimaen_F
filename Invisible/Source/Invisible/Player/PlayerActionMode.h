// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * �v���C���[�̃A�N�V�������[�h�ꗗ
 */
UENUM(BlueprintType)
enum class EPlayerActionMode : uint8
{
    Default, //!< �f�t�H���g
    Move, //!< �ړ���
    IsInLocker, //!< ���b�J�[�̒��ɂ���
    GoingIntoLocker, //!< ���b�J�[�̒��ɓ����Ă���
    GetOutOfLocker, //!< ���b�J�[�̒�����o�Ă���
    IsDying, //!< ���S��
};
ENUM_CLASS_FLAGS(EPlayerActionMode)
