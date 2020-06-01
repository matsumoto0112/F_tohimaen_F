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
* �v���C���[�̒��͂̏��
*/
UENUM(BlueprintType)
enum class EPlayerHearingMode : uint8
{
    Normal,
    High,
};

/**
* �g�p���鉹�̎��
* @details �����Đ����鎞�Ɏw�肷��񋓌^
*/
UENUM(BlueprintType)
enum class ESoundType : uint8
{
	Valve, //!< �o���u���񂷉�
	Player_Walk, //!< �v���C���[�̕��s��
	Enemy_Walk, //!< �G�̕��s��
	Player_Walk_On_Puddle, //!< �v���C���[�̕��s���i�����܂��j
	Enemy_Walk_On_Puddle, //!< �G�̕��s���i�����܂��j
	Door_Open, //!< �h�A�̊J����
	Go_Into_Locker, //!< ���b�J�[�ɓ��鉹
	Get_Out_Locker, //!< ���b�J�[����o�鉹
	Sprinkler_Ver0, //!< �X�v�����N���[�̓��쉹
	Sprinkler_Ver1, //!< �X�v�����N���[�̓��쉹
	Sprinkler_Ver2, //!< �X�v�����N���[�̓��쉹
	Chase_BGM, //!< �G�ɒǂ��Ă���Ƃ���BGM
    Item_Get, //!< �A�C�e���l����
    Enemy_Shout, //!< �G�̙��K��
    PlayerKill, //!< �v���C���[�E�Q��
	System_Decision, //!< �V�X�e�����艹
    System_CursorMove, //!< �V�X�e���J�[�\���ړ���
	System_Cansel, //!< �V�X�e���L�����Z����
    Title_FootSteps, //!< �^�C�g���̑���
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
	ESoundType SoundType;

	//!< �g�p���鉹��
	UPROPERTY(EditDefaultsOnly)
	USoundBase* SoundData;

	//!< ���̌����p�����[�^
	UPROPERTY(EditAnywhere)
	USoundAttenuation* NormalSoundAttenuation;
    //!< ���̌����p�����[�^�i�����Łj
    UPROPERTY(EditAnywhere)
    USoundAttenuation* HighSoundAttenuation;
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
	/**
    * ������
    */
	void init(UDataTable* soundData, TSubclassOf<AActor> soundObjectOrigin);

	/**
    * 3D�������Đ�����
    * @param sound ���̎��
    * @param location ���̔����ꏊ
    * @param soundGenerateSource ���̔������̃A�N�^�[
    */
	UFUNCTION(BlueprintCallable, Category = "Sound")
	void play3DSound(ESoundType sound, const FVector& location, AActor* soundGenerateSource);

	/**
    * BGM���Đ�����
    */
	UFUNCTION(BlueprintCallable, Category = "Sound")
	void PlayBGM(ESoundType SoundType);
	/**
    * BGM���~����
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
    * ���f�[�^��T��
    */
	FSoundData* findSoundData(ESoundType sound) const;
	/**
    * �����L�����ǂ������ׂ�
    */
	bool isValid(ESoundType sound) const;

private:
	//!< ���ƂȂ鉹�I�u�W�F�N�g
	TSubclassOf<AActor> soundObjectOrigin;
	//!< ���f�[�^�̃e�[�u��
	UDataTable* dataTable;

	//!< �g�p���Ă���T�E���h�I�u�W�F�N�g���X�g
	TArray<ASoundObject*> soundObjects;
	//!< BGM�p�I�u�W�F�N�g
	ASoundObject* BGMObject;
    //!< �v���C���[�̒��͂̏��
    EPlayerHearingMode PlayerHearingMode;
};
