// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USoundAtomConfig;
class USoundAtomCue;
class USceneComponent;
struct FVector;
class USoundAttenuation;
class UAtomComponent;
struct FRotator;
class USoundConcurrency;
class UObject;
#ifdef CRIWARERUNTIME_AtomStatics_generated_h
#error "AtomStatics.generated.h already included, missing '#pragma once' in AtomStatics.h"
#endif
#define CRIWARERUNTIME_AtomStatics_generated_h

#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_SPARSE_DATA
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execLoadAtomConfig) \
	{ \
		P_GET_OBJECT(USoundAtomConfig,Z_Param_AcfObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UAtomStatics::LoadAtomConfig(Z_Param_AcfObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopAllSounds) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomStatics::StopAllSounds(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPauseAudioOutput) \
	{ \
		P_GET_UBOOL(Z_Param_bPause); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomStatics::PauseAudioOutput(Z_Param_bPause); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlaySoundForAnimNotify) \
	{ \
		P_GET_OBJECT(USoundAtomCue,Z_Param_Sound); \
		P_GET_OBJECT(USceneComponent,Z_Param_AttachToComponent); \
		P_GET_PROPERTY(UNameProperty,Z_Param_AttachPointName); \
		P_GET_STRUCT(FVector,Z_Param_Location); \
		P_GET_UBOOL(Z_Param_bStopWhenAttachedToDestroyed); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_VolumeMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PitchMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_GET_OBJECT(USoundAttenuation,Z_Param_AttenuationSettings); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomStatics::PlaySoundForAnimNotify(Z_Param_Sound,Z_Param_AttachToComponent,Z_Param_AttachPointName,Z_Param_Location,Z_Param_bStopWhenAttachedToDestroyed,Z_Param_VolumeMultiplier,Z_Param_PitchMultiplier,Z_Param_StartTime,Z_Param_AttenuationSettings); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlaySoundAttached) \
	{ \
		P_GET_OBJECT(USoundAtomCue,Z_Param_Sound); \
		P_GET_OBJECT(USceneComponent,Z_Param_AttachToComponent); \
		P_GET_PROPERTY(UNameProperty,Z_Param_AttachPointName); \
		P_GET_STRUCT(FVector,Z_Param_Location); \
		P_GET_UBOOL(Z_Param_bStopWhenAttachedToDestroyed); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_VolumeMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PitchMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_GET_OBJECT(USoundAttenuation,Z_Param_AttenuationSettings); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAtomComponent**)Z_Param__Result=UAtomStatics::PlaySoundAttached(Z_Param_Sound,Z_Param_AttachToComponent,Z_Param_AttachPointName,Z_Param_Location,Z_Param_bStopWhenAttachedToDestroyed,Z_Param_VolumeMultiplier,Z_Param_PitchMultiplier,Z_Param_StartTime,Z_Param_AttenuationSettings); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSpawnSoundAttached) \
	{ \
		P_GET_OBJECT(USoundAtomCue,Z_Param_Sound); \
		P_GET_OBJECT(USceneComponent,Z_Param_AttachToComponent); \
		P_GET_PROPERTY(UNameProperty,Z_Param_AttachPointName); \
		P_GET_STRUCT(FVector,Z_Param_Location); \
		P_GET_STRUCT(FRotator,Z_Param_Rotation); \
		P_GET_PROPERTY(UByteProperty,Z_Param_LocationType); \
		P_GET_UBOOL(Z_Param_bStopWhenAttachedToDestroyed); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_VolumeMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PitchMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_GET_OBJECT(USoundAttenuation,Z_Param_AttenuationSettings); \
		P_GET_OBJECT(USoundConcurrency,Z_Param_ConcurrencySettings); \
		P_GET_UBOOL(Z_Param_bAutoDestroy); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAtomComponent**)Z_Param__Result=UAtomStatics::SpawnSoundAttached(Z_Param_Sound,Z_Param_AttachToComponent,Z_Param_AttachPointName,Z_Param_Location,Z_Param_Rotation,EAttachLocation::Type(Z_Param_LocationType),Z_Param_bStopWhenAttachedToDestroyed,Z_Param_VolumeMultiplier,Z_Param_PitchMultiplier,Z_Param_StartTime,Z_Param_AttenuationSettings,Z_Param_ConcurrencySettings,Z_Param_bAutoDestroy); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSpawnSoundAtLocation) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(USoundAtomCue,Z_Param_Sound); \
		P_GET_STRUCT(FVector,Z_Param_Location); \
		P_GET_STRUCT(FRotator,Z_Param_Rotation); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_VolumeMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PitchMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_GET_OBJECT(USoundAttenuation,Z_Param_AttenuationSettings); \
		P_GET_OBJECT(USoundConcurrency,Z_Param_ConcurrencySettings); \
		P_GET_UBOOL(Z_Param_bAutoDestroy); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAtomComponent**)Z_Param__Result=UAtomStatics::SpawnSoundAtLocation(Z_Param_WorldContextObject,Z_Param_Sound,Z_Param_Location,Z_Param_Rotation,Z_Param_VolumeMultiplier,Z_Param_PitchMultiplier,Z_Param_StartTime,Z_Param_AttenuationSettings,Z_Param_ConcurrencySettings,Z_Param_bAutoDestroy); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateRootedAtomComponent) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_UBOOL(Z_Param_bAutoDestroy); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAtomComponent**)Z_Param__Result=UAtomStatics::CreateRootedAtomComponent(Z_Param_WorldContextObject,Z_Param_bAutoDestroy); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSpawnSound2D) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(USoundAtomCue,Z_Param_Sound); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PitchMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_GET_UBOOL(Z_Param_bPersistAcrossLevelTransition); \
		P_GET_UBOOL(Z_Param_bAutoDestroy); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAtomComponent**)Z_Param__Result=UAtomStatics::SpawnSound2D(Z_Param_WorldContextObject,Z_Param_Sound,Z_Param_PitchMultiplier,Z_Param_StartTime,Z_Param_bPersistAcrossLevelTransition,Z_Param_bAutoDestroy); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlaySoundAtLocation) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(USoundAtomCue,Z_Param_Sound); \
		P_GET_STRUCT(FVector,Z_Param_Location); \
		P_GET_STRUCT(FRotator,Z_Param_Rotation); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_VolumeMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PitchMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_GET_OBJECT(USoundAttenuation,Z_Param_AttenuationSettings); \
		P_GET_OBJECT(USoundConcurrency,Z_Param_ConcurrencySettings); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomStatics::PlaySoundAtLocation(Z_Param_WorldContextObject,Z_Param_Sound,Z_Param_Location,Z_Param_Rotation,Z_Param_VolumeMultiplier,Z_Param_PitchMultiplier,Z_Param_StartTime,Z_Param_AttenuationSettings,Z_Param_ConcurrencySettings); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLoadAtomConfig) \
	{ \
		P_GET_OBJECT(USoundAtomConfig,Z_Param_AcfObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UAtomStatics::LoadAtomConfig(Z_Param_AcfObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopAllSounds) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomStatics::StopAllSounds(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPauseAudioOutput) \
	{ \
		P_GET_UBOOL(Z_Param_bPause); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomStatics::PauseAudioOutput(Z_Param_bPause); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlaySoundForAnimNotify) \
	{ \
		P_GET_OBJECT(USoundAtomCue,Z_Param_Sound); \
		P_GET_OBJECT(USceneComponent,Z_Param_AttachToComponent); \
		P_GET_PROPERTY(UNameProperty,Z_Param_AttachPointName); \
		P_GET_STRUCT(FVector,Z_Param_Location); \
		P_GET_UBOOL(Z_Param_bStopWhenAttachedToDestroyed); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_VolumeMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PitchMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_GET_OBJECT(USoundAttenuation,Z_Param_AttenuationSettings); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomStatics::PlaySoundForAnimNotify(Z_Param_Sound,Z_Param_AttachToComponent,Z_Param_AttachPointName,Z_Param_Location,Z_Param_bStopWhenAttachedToDestroyed,Z_Param_VolumeMultiplier,Z_Param_PitchMultiplier,Z_Param_StartTime,Z_Param_AttenuationSettings); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlaySoundAttached) \
	{ \
		P_GET_OBJECT(USoundAtomCue,Z_Param_Sound); \
		P_GET_OBJECT(USceneComponent,Z_Param_AttachToComponent); \
		P_GET_PROPERTY(UNameProperty,Z_Param_AttachPointName); \
		P_GET_STRUCT(FVector,Z_Param_Location); \
		P_GET_UBOOL(Z_Param_bStopWhenAttachedToDestroyed); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_VolumeMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PitchMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_GET_OBJECT(USoundAttenuation,Z_Param_AttenuationSettings); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAtomComponent**)Z_Param__Result=UAtomStatics::PlaySoundAttached(Z_Param_Sound,Z_Param_AttachToComponent,Z_Param_AttachPointName,Z_Param_Location,Z_Param_bStopWhenAttachedToDestroyed,Z_Param_VolumeMultiplier,Z_Param_PitchMultiplier,Z_Param_StartTime,Z_Param_AttenuationSettings); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSpawnSoundAttached) \
	{ \
		P_GET_OBJECT(USoundAtomCue,Z_Param_Sound); \
		P_GET_OBJECT(USceneComponent,Z_Param_AttachToComponent); \
		P_GET_PROPERTY(UNameProperty,Z_Param_AttachPointName); \
		P_GET_STRUCT(FVector,Z_Param_Location); \
		P_GET_STRUCT(FRotator,Z_Param_Rotation); \
		P_GET_PROPERTY(UByteProperty,Z_Param_LocationType); \
		P_GET_UBOOL(Z_Param_bStopWhenAttachedToDestroyed); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_VolumeMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PitchMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_GET_OBJECT(USoundAttenuation,Z_Param_AttenuationSettings); \
		P_GET_OBJECT(USoundConcurrency,Z_Param_ConcurrencySettings); \
		P_GET_UBOOL(Z_Param_bAutoDestroy); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAtomComponent**)Z_Param__Result=UAtomStatics::SpawnSoundAttached(Z_Param_Sound,Z_Param_AttachToComponent,Z_Param_AttachPointName,Z_Param_Location,Z_Param_Rotation,EAttachLocation::Type(Z_Param_LocationType),Z_Param_bStopWhenAttachedToDestroyed,Z_Param_VolumeMultiplier,Z_Param_PitchMultiplier,Z_Param_StartTime,Z_Param_AttenuationSettings,Z_Param_ConcurrencySettings,Z_Param_bAutoDestroy); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSpawnSoundAtLocation) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(USoundAtomCue,Z_Param_Sound); \
		P_GET_STRUCT(FVector,Z_Param_Location); \
		P_GET_STRUCT(FRotator,Z_Param_Rotation); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_VolumeMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PitchMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_GET_OBJECT(USoundAttenuation,Z_Param_AttenuationSettings); \
		P_GET_OBJECT(USoundConcurrency,Z_Param_ConcurrencySettings); \
		P_GET_UBOOL(Z_Param_bAutoDestroy); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAtomComponent**)Z_Param__Result=UAtomStatics::SpawnSoundAtLocation(Z_Param_WorldContextObject,Z_Param_Sound,Z_Param_Location,Z_Param_Rotation,Z_Param_VolumeMultiplier,Z_Param_PitchMultiplier,Z_Param_StartTime,Z_Param_AttenuationSettings,Z_Param_ConcurrencySettings,Z_Param_bAutoDestroy); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateRootedAtomComponent) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_UBOOL(Z_Param_bAutoDestroy); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAtomComponent**)Z_Param__Result=UAtomStatics::CreateRootedAtomComponent(Z_Param_WorldContextObject,Z_Param_bAutoDestroy); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSpawnSound2D) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(USoundAtomCue,Z_Param_Sound); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PitchMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_GET_UBOOL(Z_Param_bPersistAcrossLevelTransition); \
		P_GET_UBOOL(Z_Param_bAutoDestroy); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAtomComponent**)Z_Param__Result=UAtomStatics::SpawnSound2D(Z_Param_WorldContextObject,Z_Param_Sound,Z_Param_PitchMultiplier,Z_Param_StartTime,Z_Param_bPersistAcrossLevelTransition,Z_Param_bAutoDestroy); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlaySoundAtLocation) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(USoundAtomCue,Z_Param_Sound); \
		P_GET_STRUCT(FVector,Z_Param_Location); \
		P_GET_STRUCT(FRotator,Z_Param_Rotation); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_VolumeMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PitchMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_GET_OBJECT(USoundAttenuation,Z_Param_AttenuationSettings); \
		P_GET_OBJECT(USoundConcurrency,Z_Param_ConcurrencySettings); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomStatics::PlaySoundAtLocation(Z_Param_WorldContextObject,Z_Param_Sound,Z_Param_Location,Z_Param_Rotation,Z_Param_VolumeMultiplier,Z_Param_PitchMultiplier,Z_Param_StartTime,Z_Param_AttenuationSettings,Z_Param_ConcurrencySettings); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAtomStatics(); \
	friend struct Z_Construct_UClass_UAtomStatics_Statics; \
public: \
	DECLARE_CLASS(UAtomStatics, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(UAtomStatics)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_INCLASS \
private: \
	static void StaticRegisterNativesUAtomStatics(); \
	friend struct Z_Construct_UClass_UAtomStatics_Statics; \
public: \
	DECLARE_CLASS(UAtomStatics, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(UAtomStatics)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAtomStatics(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAtomStatics) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAtomStatics); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAtomStatics); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAtomStatics(UAtomStatics&&); \
	NO_API UAtomStatics(const UAtomStatics&); \
public:


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAtomStatics(UAtomStatics&&); \
	NO_API UAtomStatics(const UAtomStatics&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAtomStatics); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAtomStatics); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UAtomStatics)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_PRIVATE_PROPERTY_OFFSET
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_56_PROLOG
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_RPC_WRAPPERS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_INCLASS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_RPC_WRAPPERS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_INCLASS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h_59_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CRIWARERUNTIME_API UClass* StaticClass<class UAtomStatics>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomStatics_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
