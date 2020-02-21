// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAtomAsrRack;
#ifdef CRIWARERUNTIME_AtomAsrRack_generated_h
#error "AtomAsrRack.generated.h already included, missing '#pragma once' in AtomAsrRack.h"
#endif
#define CRIWARERUNTIME_AtomAsrRack_generated_h

#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_SPARSE_DATA
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetBusAnalyzerInfo) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_DspBusName); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_num_channels); \
		P_GET_TARRAY_REF(float,Z_Param_Out_rms_levels); \
		P_GET_TARRAY_REF(float,Z_Param_Out_peak_levels); \
		P_GET_TARRAY_REF(float,Z_Param_Out_peak_hold_levels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetBusAnalyzerInfo(Z_Param_DspBusName,Z_Param_Out_num_channels,Z_Param_Out_rms_levels,Z_Param_Out_peak_levels,Z_Param_Out_peak_hold_levels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEffectBypass) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_BusName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_EffectName); \
		P_GET_UBOOL(Z_Param_Bypasses); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetEffectBypass(Z_Param_BusName,Z_Param_EffectName,Z_Param_Bypasses); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBusSendLevelByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_SourceBusName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_DestBusName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Level); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBusSendLevelByName(Z_Param_SourceBusName,Z_Param_DestBusName,Z_Param_Level); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBusVolumeByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_BusName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBusVolumeByName(Z_Param_BusName,Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execApplyDspBusSnapshot) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_SnapshotName); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Milliseconds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ApplyDspBusSnapshot(Z_Param_SnapshotName,Z_Param_Milliseconds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDetachDspBusSetting) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DetachDspBusSetting(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttachDspBusSetting) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_SettingName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AttachDspBusSetting(Z_Param_SettingName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAsrRack) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_AsrRackId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAtomAsrRack**)Z_Param__Result=UAtomAsrRack::GetAsrRack(Z_Param_AsrRackId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetDefaultAsrRack) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAtomAsrRack**)Z_Param__Result=UAtomAsrRack::GetDefaultAsrRack(); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetBusAnalyzerInfo) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_DspBusName); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_num_channels); \
		P_GET_TARRAY_REF(float,Z_Param_Out_rms_levels); \
		P_GET_TARRAY_REF(float,Z_Param_Out_peak_levels); \
		P_GET_TARRAY_REF(float,Z_Param_Out_peak_hold_levels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetBusAnalyzerInfo(Z_Param_DspBusName,Z_Param_Out_num_channels,Z_Param_Out_rms_levels,Z_Param_Out_peak_levels,Z_Param_Out_peak_hold_levels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEffectBypass) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_BusName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_EffectName); \
		P_GET_UBOOL(Z_Param_Bypasses); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetEffectBypass(Z_Param_BusName,Z_Param_EffectName,Z_Param_Bypasses); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBusSendLevelByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_SourceBusName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_DestBusName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Level); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBusSendLevelByName(Z_Param_SourceBusName,Z_Param_DestBusName,Z_Param_Level); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBusVolumeByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_BusName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBusVolumeByName(Z_Param_BusName,Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execApplyDspBusSnapshot) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_SnapshotName); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Milliseconds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ApplyDspBusSnapshot(Z_Param_SnapshotName,Z_Param_Milliseconds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDetachDspBusSetting) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DetachDspBusSetting(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttachDspBusSetting) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_SettingName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AttachDspBusSetting(Z_Param_SettingName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAsrRack) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_AsrRackId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAtomAsrRack**)Z_Param__Result=UAtomAsrRack::GetAsrRack(Z_Param_AsrRackId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetDefaultAsrRack) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAtomAsrRack**)Z_Param__Result=UAtomAsrRack::GetDefaultAsrRack(); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAtomAsrRack(); \
	friend struct Z_Construct_UClass_UAtomAsrRack_Statics; \
public: \
	DECLARE_CLASS(UAtomAsrRack, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(UAtomAsrRack)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_INCLASS \
private: \
	static void StaticRegisterNativesUAtomAsrRack(); \
	friend struct Z_Construct_UClass_UAtomAsrRack_Statics; \
public: \
	DECLARE_CLASS(UAtomAsrRack, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(UAtomAsrRack)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAtomAsrRack(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAtomAsrRack) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAtomAsrRack); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAtomAsrRack); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAtomAsrRack(UAtomAsrRack&&); \
	NO_API UAtomAsrRack(const UAtomAsrRack&); \
public:


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAtomAsrRack(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAtomAsrRack(UAtomAsrRack&&); \
	NO_API UAtomAsrRack(const UAtomAsrRack&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAtomAsrRack); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAtomAsrRack); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAtomAsrRack)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_PRIVATE_PROPERTY_OFFSET
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_52_PROLOG
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_RPC_WRAPPERS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_INCLASS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_RPC_WRAPPERS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_INCLASS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h_55_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class AtomAsrRack."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CRIWARERUNTIME_API UClass* StaticClass<class UAtomAsrRack>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomAsrRack_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
