// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/AudioComponent.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"

#include "SoundSystem.generated.h"

/**
* �g�p���鉹�̎��
* @details �����Đ����鎞�Ɏw�肷��񋓌^
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
* ���f�[�^�Ǘ��p�\����
*/
USTRUCT(BlueprintType)
struct INVISIBLE_API FSoundData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	//!< �g�p���鉹�̎��
	UPROPERTY(EditDefaultsOnly)
	ESoundType soundType;

	//!< �g�p���鉹��
	UPROPERTY(EditDefaultsOnly)
	USoundBase* sound;

	//!< ���̌����p�����[�^
    UPROPERTY(EditAnywhere)
    USoundAttenuation* soundAttenuation;
};

/**
 * ���̊Ǘ��V�X�e��
 */
UCLASS()
class INVISIBLE_API USoundSystem : public UObject
{
	GENERATED_BODY()
public:
	/**
    *  �R���X�g���N�^
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
