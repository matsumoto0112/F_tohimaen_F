// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/AudioComponent.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"

#include "SoundSystem.generated.h"

class ASoundObject;

/**
* 使用する音の種類
* @details 音を再生する時に指定する列挙型
*/
UENUM(BlueprintType)
enum class ESoundType : uint8
{
	Valve,
	Sprinkler,
	Player_Walk,
	Enemy_Walk,
	Player_Walk_On_Puddle,
	Enemy_Walk_On_Puddle,
};

/**
* 音データ管理用構造体
*/
USTRUCT(BlueprintType)
struct INVISIBLE_API FSoundData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	//!< 使用する音の種類
	UPROPERTY(EditDefaultsOnly)
	ESoundType soundType;

	//!< 使用する音源
	UPROPERTY(EditDefaultsOnly)
	USoundBase* sound;

	//!< 音の減衰パラメータ
	UPROPERTY(EditAnywhere)
	USoundAttenuation* soundAttenuation;
};

/**
 * 音の管理システム
 */
UCLASS()
class INVISIBLE_API USoundSystem : public UObject
{
	GENERATED_BODY()

public:
	/**
    *  コンストラクタ
    */
	USoundSystem();
	/**
    * 初期化
    */
	void init(UDataTable* soundData, TSubclassOf<AActor> soundObjectOrigin);

	/**
    * 3D音源を再生する
    * @param sound 音の種類
    * @param location 音の発生場所
    * @param soundGenerateSource 音の発生源のアクター
    */
	UFUNCTION()
	void play3DSound(ESoundType sound, const FVector& location, AActor* soundGenerateSource);

	UFUNCTION(BlueprintCallable, Category = "SoundSystem")
	void createSoundObjects(int32 num);
	UFUNCTION(BlueprintCallable, Category = "SoundSystem")
	void destroySoundObjects();

private:
	/**
    * 音データを探す
    */
	FSoundData* findSoundData(ESoundType sound) const;
	/**
    * 音が有効かどうか調べる
    */
	bool isValid(ESoundType sound) const;

private:
	//!< 元となる音オブジェクト
	TSubclassOf<AActor> soundObjectOrigin;
	//!< 音データのテーブル
	UDataTable* dataTable;

	//!< 使用しているサウンドオブジェクトリスト
	TArray<ASoundObject*> soundObjects;
};
