// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"

#include "MyCheatManager.generated.h"

/**
 * �Q�[�����̃`�[�g�Ǘ�
 */
UCLASS()
class INVISIBLE_API UMyCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:
    /**
    * �G����������R�}���h
    */
	UFUNCTION(BlueprintNativeEvent, exec)
	void VisibleEnemy();

	virtual void VisibleEnemy_Implementation();

    /**
    * �G����������
    */
	UFUNCTION(BlueprintNativeEvent, exec)
	void InvisibleEnemy();

	virtual void InvisibleEnemy_Implementation();
};
