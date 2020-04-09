// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/AudioComponent.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"

#include "SoundSystem.generated.h"

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
	Walk_On_Puddle,
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
	void init(UDataTable* soundData);

	UFUNCTION()
	void play3DSound(ESoundType sound, const FVector& location);

private:
	FSoundData* findSoundData(ESoundType sound) const;
	bool isValid(ESoundType sound) const;

private:
	TSubclassOf<AActor> soundObjectOrigin;
	UDataTable* dataTable;

	TArray<FName> soundTableRowNames;
};
