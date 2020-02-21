// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAtomSoundObject;
enum class EAtomComponentStatus : uint8;
class USoundAtomCue;
#ifdef CRIWARERUNTIME_AtomComponent_generated_h
#error "AtomComponent.generated.h already included, missing '#pragma once' in AtomComponent.h"
#endif
#define CRIWARERUNTIME_AtomComponent_generated_h

#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_96_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAtomSelectorParam_Statics; \
	CRIWARERUNTIME_API static class UScriptStruct* StaticStruct();


template<> CRIWARERUNTIME_API UScriptStruct* StaticStruct<struct FAtomSelectorParam>();

#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_79_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAtomAisacControlParam_Statics; \
	CRIWARERUNTIME_API static class UScriptStruct* StaticStruct();


template<> CRIWARERUNTIME_API UScriptStruct* StaticStruct<struct FAtomAisacControlParam>();

#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_118_DELEGATE \
static inline void FOnAudioFinished_DelegateWrapper(const FMulticastScriptDelegate& OnAudioFinished) \
{ \
	OnAudioFinished.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_SPARSE_DATA
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetDefaultAttenuationEnable) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UAtomComponent::GetDefaultAttenuationEnable(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetDefaultAttenuationEnable) \
	{ \
		P_GET_UBOOL(Z_Param_bEnable); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomComponent::SetDefaultAttenuationEnable(Z_Param_bEnable); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDestroyComponentByID) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_TargetID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomComponent::DestroyComponentByID(Z_Param_TargetID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCueName) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetCueName(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAtomComponentID) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAtomComponentID(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSequencePosition) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetSequencePosition(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTime) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetTime(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAsrRackIdArray) \
	{ \
		P_GET_TARRAY(int32,Z_Param_AsrRackIDs); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetAsrRackIdArray(Z_Param_AsrRackIDs); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAsrRackID) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_asr_rack_id); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetAsrRackID(Z_Param_asr_rack_id); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSelectorLabel) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Selector); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Label); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetSelectorLabel(Z_Param_Selector,Z_Param_Label); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetNextBlockIndex) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BlockIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetNextBlockIndex(Z_Param_BlockIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBusSendLevelOffsetByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_BusName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_LevelOffset); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBusSendLevelOffsetByName(Z_Param_BusName,Z_Param_LevelOffset); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBusSendLevelOffset) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BusId); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_LevelOffset); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBusSendLevelOffset(Z_Param_BusId,Z_Param_LevelOffset); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBusSendLevelByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_BusName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Level); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBusSendLevelByName(Z_Param_BusName,Z_Param_Level); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBusSendLevel) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BusId); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Level); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBusSendLevel(Z_Param_BusId,Z_Param_Level); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAisacByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_ControlName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ControlValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetAisacByName(Z_Param_ControlName,Z_Param_ControlValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetPitch) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Pitch); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetPitch(Z_Param_Pitch); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetPitchMultiplier) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewPitchMultiplier); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetPitchMultiplier(Z_Param_NewPitchMultiplier); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSoundObject) \
	{ \
		P_GET_OBJECT(UAtomSoundObject,Z_Param_SoundObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetSoundObject(Z_Param_SoundObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVolume) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsPlaying) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsPlaying(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsPaused) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsPaused(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPause) \
	{ \
		P_GET_UBOOL(Z_Param_bPause); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Pause(Z_Param_bPause); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetStatus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EAtomComponentStatus*)Z_Param__Result=P_THIS->GetStatus(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFadeOut) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_FadeOutDuration); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_FadeVolumeLevel); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->FadeOut(Z_Param_FadeOutDuration,Z_Param_FadeVolumeLevel); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFadeIn) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_FadeInDuration); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_FadeVolumeLevel); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->FadeIn(Z_Param_FadeInDuration,Z_Param_FadeVolumeLevel,Z_Param_StartTime); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStop) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Stop(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlay) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Play(Z_Param_StartTime); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumQueuedSounds) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetNumQueuedSounds(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnqueueSound) \
	{ \
		P_GET_OBJECT(USoundAtomCue,Z_Param_NewSound); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EnqueueSound(Z_Param_NewSound); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSound) \
	{ \
		P_GET_OBJECT(USoundAtomCue,Z_Param_NewSound); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetSound(Z_Param_NewSound); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetDefaultAttenuationEnable) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UAtomComponent::GetDefaultAttenuationEnable(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetDefaultAttenuationEnable) \
	{ \
		P_GET_UBOOL(Z_Param_bEnable); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomComponent::SetDefaultAttenuationEnable(Z_Param_bEnable); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDestroyComponentByID) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_TargetID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomComponent::DestroyComponentByID(Z_Param_TargetID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCueName) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetCueName(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAtomComponentID) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAtomComponentID(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSequencePosition) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetSequencePosition(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTime) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetTime(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAsrRackIdArray) \
	{ \
		P_GET_TARRAY(int32,Z_Param_AsrRackIDs); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetAsrRackIdArray(Z_Param_AsrRackIDs); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAsrRackID) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_asr_rack_id); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetAsrRackID(Z_Param_asr_rack_id); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSelectorLabel) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Selector); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Label); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetSelectorLabel(Z_Param_Selector,Z_Param_Label); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetNextBlockIndex) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BlockIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetNextBlockIndex(Z_Param_BlockIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBusSendLevelOffsetByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_BusName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_LevelOffset); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBusSendLevelOffsetByName(Z_Param_BusName,Z_Param_LevelOffset); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBusSendLevelOffset) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BusId); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_LevelOffset); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBusSendLevelOffset(Z_Param_BusId,Z_Param_LevelOffset); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBusSendLevelByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_BusName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Level); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBusSendLevelByName(Z_Param_BusName,Z_Param_Level); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBusSendLevel) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BusId); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Level); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBusSendLevel(Z_Param_BusId,Z_Param_Level); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAisacByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_ControlName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ControlValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetAisacByName(Z_Param_ControlName,Z_Param_ControlValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetPitch) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Pitch); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetPitch(Z_Param_Pitch); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetPitchMultiplier) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewPitchMultiplier); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetPitchMultiplier(Z_Param_NewPitchMultiplier); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSoundObject) \
	{ \
		P_GET_OBJECT(UAtomSoundObject,Z_Param_SoundObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetSoundObject(Z_Param_SoundObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVolume) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsPlaying) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsPlaying(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsPaused) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsPaused(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPause) \
	{ \
		P_GET_UBOOL(Z_Param_bPause); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Pause(Z_Param_bPause); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetStatus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EAtomComponentStatus*)Z_Param__Result=P_THIS->GetStatus(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFadeOut) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_FadeOutDuration); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_FadeVolumeLevel); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->FadeOut(Z_Param_FadeOutDuration,Z_Param_FadeVolumeLevel); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFadeIn) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_FadeInDuration); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_FadeVolumeLevel); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->FadeIn(Z_Param_FadeInDuration,Z_Param_FadeVolumeLevel,Z_Param_StartTime); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStop) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Stop(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlay) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Play(Z_Param_StartTime); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumQueuedSounds) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetNumQueuedSounds(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnqueueSound) \
	{ \
		P_GET_OBJECT(USoundAtomCue,Z_Param_NewSound); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EnqueueSound(Z_Param_NewSound); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSound) \
	{ \
		P_GET_OBJECT(USoundAtomCue,Z_Param_NewSound); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetSound(Z_Param_NewSound); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAtomComponent(); \
	friend struct Z_Construct_UClass_UAtomComponent_Statics; \
public: \
	DECLARE_CLASS(UAtomComponent, USceneComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(UAtomComponent)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_INCLASS \
private: \
	static void StaticRegisterNativesUAtomComponent(); \
	friend struct Z_Construct_UClass_UAtomComponent_Statics; \
public: \
	DECLARE_CLASS(UAtomComponent, USceneComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(UAtomComponent)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAtomComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAtomComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAtomComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAtomComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAtomComponent(UAtomComponent&&); \
	NO_API UAtomComponent(const UAtomComponent&); \
public:


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAtomComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAtomComponent(UAtomComponent&&); \
	NO_API UAtomComponent(const UAtomComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAtomComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAtomComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAtomComponent)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_PRIVATE_PROPERTY_OFFSET
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_113_PROLOG
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_RPC_WRAPPERS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_INCLASS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_RPC_WRAPPERS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_INCLASS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h_116_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class AtomComponent."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CRIWARERUNTIME_API UClass* StaticClass<class UAtomComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomComponent_h


#define FOREACH_ENUM_EATOMCOMPONENTSTATUS(op) \
	op(EAtomComponentStatus::Stop) \
	op(EAtomComponentStatus::Prep) \
	op(EAtomComponentStatus::Playing) \
	op(EAtomComponentStatus::PlayEnd) \
	op(EAtomComponentStatus::Error) 

enum class EAtomComponentStatus : uint8;
template<> CRIWARERUNTIME_API UEnum* StaticEnum<EAtomComponentStatus>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
