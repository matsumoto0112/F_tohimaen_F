// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "Invisible/System/ConfigParams.h"
#include "Invisible/System/ControllerVibration.h"

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
    * シャットダウン時に呼ばれる
    */
	virtual void Shutdown() override;

	/**
    * 実行中のBlueprintのコールスタックをログ出力する
    */
	UFUNCTION(BlueprintCallable, Category = "Debug")
	static void PrintLogBlueprintCallstack();
	/**
    * インスタンスの取得
    */
	UFUNCTION()
	static UMyGameInstance* GetInstance();
	/**
    * サウンドシステムを取得する
    */
	UFUNCTION(BlueprintCallable, Category = "Singleton")
	USoundSystem* getSoundSystem() const { return SoundSystem; }

	UFUNCTION(BlueprintCallable, Category = "Singleton")
	UConfigParams* GetConfigParams() const { return ConfigParams; }
	UFUNCTION(BlueprintCallable, Category = "Singleton")
	UControllerVibration* GetControllerVibration() const { return ControllerVibration; }

	UFUNCTION(BluePrintCallable, Category = "Clear")
	void setClear(bool clear) { isClear = clear; }
	UFUNCTION(BluePrintCallable, Category = "Clear")
	bool getClear() { return isClear; }

private:
	//!< OnHandleSystemError デリゲート登録時のハンドル
	FDelegateHandle OnSystemErrorDelegateHandle;

	bool isClear = false;

	/**
    * システムエラー時に呼ばれる関数
    */
	void OnSystemError();

private:
	//!< サウンドデータテーブル
	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	UDataTable* SoundDataTable;
	//!< 元となる音オブジェクト
	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	TSubclassOf<AActor> SoundObjectOrigin;

protected:
	//!< サウンドシステム
	UPROPERTY(VisibleAnywhere)
	USoundSystem* SoundSystem;
	UPROPERTY(VisibleAnywhere)
	UConfigParams* ConfigParams;
	UPROPERTY(VisibleAnywhere)
	UControllerVibration* ControllerVibration;
};
