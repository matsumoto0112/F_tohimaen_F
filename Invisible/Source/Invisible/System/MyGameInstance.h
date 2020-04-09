// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"

#include "MyGameInstance.generated.h"

class USoundSystem;

/**
 * ゲームインスタンス
 */
UCLASS()
class INVISIBLE_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	UMyGameInstance();

public:
    /**
    * 初期化
    */
	virtual void Init() override;
    /**
    * インスタンスの取得
    */
	UFUNCTION()
	static UMyGameInstance* GetInstance();
    /**
    * サウンドシステムを取得する
    */
	UFUNCTION()
	USoundSystem* getSoundSystem() const { return soundSystem; }

private:
    //!< サウンドデータテーブル
	UPROPERTY(EditDefaultsOnly, Category = "Params")
	UDataTable* soundData;

private:
    //!< サウンドシステム
	USoundSystem* soundSystem;
};
