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
* プレイヤーの聴力の状態
*/
UENUM(BlueprintType)
enum class EPlayerHearingMode : uint8
{
    Normal,
    High,
};

/**
* 使用する音の種類
* @details 音を再生する時に指定する列挙型
*/
UENUM(BlueprintType)
enum class ESoundType : uint8
{
	Valve, //!< バルブを回す音
	Player_Walk, //!< プレイヤーの歩行音
	Enemy_Walk, //!< 敵の歩行音
	Player_Walk_On_Puddle, //!< プレイヤーの歩行音（水たまり上）
	Enemy_Walk_On_Puddle, //!< 敵の歩行音（水たまり上）
	Door_Open, //!< ドアの開く音
	Go_Into_Locker, //!< ロッカーに入る音
	Get_Out_Locker, //!< ロッカーから出る音
	Sprinkler_Ver0, //!< スプリンクラーの動作音
	Sprinkler_Ver1, //!< スプリンクラーの動作音
	Sprinkler_Ver2, //!< スプリンクラーの動作音
	Chase_BGM, //!< 敵に追われているときのBGM
    Item_Get, //!< アイテム獲得音
    Enemy_Shout, //!< 敵の咆哮音
    PlayerKill, //!< プレイヤー殺害音
	System_Decision, //!< システム決定音
    System_CursorMove, //!< システムカーソル移動音
	System_Cansel, //!< システムキャンセル音
    Title_FootSteps, //!< タイトルの足音
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
	ESoundType SoundType;

	//!< 使用する音源
	UPROPERTY(EditDefaultsOnly)
	USoundBase* SoundData;

	//!< 音の減衰パラメータ
	UPROPERTY(EditAnywhere)
	USoundAttenuation* NormalSoundAttenuation;
    //!< 音の減衰パラメータ（強化版）
    UPROPERTY(EditAnywhere)
    USoundAttenuation* HighSoundAttenuation;
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
	UFUNCTION(BlueprintCallable, Category = "Sound")
	void play3DSound(ESoundType sound, const FVector& location, AActor* soundGenerateSource);

	/**
    * BGMを再生する
    */
	UFUNCTION(BlueprintCallable, Category = "Sound")
	void PlayBGM(ESoundType SoundType);
	/**
    * BGMを停止する
    */
	UFUNCTION(BlueprintCallable, Category = "Sound")
	void StopBGM();

	UFUNCTION(BlueprintCallable, Category = "SoundSystem")
	void createSoundObjects(int32 num);
	UFUNCTION(BlueprintCallable, Category = "SoundSystem")
	void destroySoundObjects();

    void SetHearingMode(EPlayerHearingMode HearingMode){PlayerHearingMode = HearingMode;};
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
	//!< BGM用オブジェクト
	ASoundObject* BGMObject;
    //!< プレイヤーの聴力の状態
    EPlayerHearingMode PlayerHearingMode;
};
