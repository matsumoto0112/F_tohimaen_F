// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USoundAtomCue;
class USoundAtomCueSheet;
#ifdef CRIWARERUNTIME_SoundAtomCueSheet_generated_h
#error "SoundAtomCueSheet.generated.h already included, missing '#pragma once' in SoundAtomCueSheet.h"
#endif
#define CRIWARERUNTIME_SoundAtomCueSheet_generated_h

#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_SPARSE_DATA
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetAtomCueByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CueName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USoundAtomCue**)Z_Param__Result=P_THIS->GetAtomCueByName(Z_Param_CueName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAtomCueById) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_CueId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USoundAtomCue**)Z_Param__Result=P_THIS->GetAtomCueById(Z_Param_CueId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAtomCueByIndex) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_CueIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USoundAtomCue**)Z_Param__Result=P_THIS->GetAtomCueByIndex(Z_Param_CueIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsLoaded) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsLoaded(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execApplyDspBusSnapshot) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_SnapshotName); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Milliseconds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USoundAtomCueSheet::ApplyDspBusSnapshot(Z_Param_SnapshotName,Z_Param_Milliseconds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDetachDspBusSetting) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USoundAtomCueSheet::DetachDspBusSetting(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttachDspBusSetting) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_SettingName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USoundAtomCueSheet::AttachDspBusSetting(Z_Param_SettingName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReleaseAcb) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_AcbName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USoundAtomCueSheet::ReleaseAcb(Z_Param_AcbName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadAcb) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_AcbName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USoundAtomCueSheet**)Z_Param__Result=USoundAtomCueSheet::LoadAcb(Z_Param_AcbName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadAtomCueSheet) \
	{ \
		P_GET_OBJECT(USoundAtomCueSheet,Z_Param_CueSheet); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USoundAtomCueSheet**)Z_Param__Result=USoundAtomCueSheet::LoadAtomCueSheet(Z_Param_CueSheet); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAtomCueByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CueName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USoundAtomCue**)Z_Param__Result=P_THIS->GetAtomCueByName(Z_Param_CueName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAtomCueById) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_CueId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USoundAtomCue**)Z_Param__Result=P_THIS->GetAtomCueById(Z_Param_CueId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAtomCueByIndex) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_CueIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USoundAtomCue**)Z_Param__Result=P_THIS->GetAtomCueByIndex(Z_Param_CueIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsLoaded) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsLoaded(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execApplyDspBusSnapshot) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_SnapshotName); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Milliseconds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USoundAtomCueSheet::ApplyDspBusSnapshot(Z_Param_SnapshotName,Z_Param_Milliseconds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDetachDspBusSetting) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USoundAtomCueSheet::DetachDspBusSetting(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttachDspBusSetting) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_SettingName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USoundAtomCueSheet::AttachDspBusSetting(Z_Param_SettingName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReleaseAcb) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_AcbName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USoundAtomCueSheet::ReleaseAcb(Z_Param_AcbName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadAcb) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_AcbName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USoundAtomCueSheet**)Z_Param__Result=USoundAtomCueSheet::LoadAcb(Z_Param_AcbName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadAtomCueSheet) \
	{ \
		P_GET_OBJECT(USoundAtomCueSheet,Z_Param_CueSheet); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USoundAtomCueSheet**)Z_Param__Result=USoundAtomCueSheet::LoadAtomCueSheet(Z_Param_CueSheet); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(USoundAtomCueSheet, NO_API)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSoundAtomCueSheet(); \
	friend struct Z_Construct_UClass_USoundAtomCueSheet_Statics; \
public: \
	DECLARE_CLASS(USoundAtomCueSheet, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(USoundAtomCueSheet) \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_ARCHIVESERIALIZER


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_INCLASS \
private: \
	static void StaticRegisterNativesUSoundAtomCueSheet(); \
	friend struct Z_Construct_UClass_USoundAtomCueSheet_Statics; \
public: \
	DECLARE_CLASS(USoundAtomCueSheet, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(USoundAtomCueSheet) \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_ARCHIVESERIALIZER


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USoundAtomCueSheet(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USoundAtomCueSheet) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USoundAtomCueSheet); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USoundAtomCueSheet); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USoundAtomCueSheet(USoundAtomCueSheet&&); \
	NO_API USoundAtomCueSheet(const USoundAtomCueSheet&); \
public:


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USoundAtomCueSheet(USoundAtomCueSheet&&); \
	NO_API USoundAtomCueSheet(const USoundAtomCueSheet&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USoundAtomCueSheet); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USoundAtomCueSheet); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USoundAtomCueSheet)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_PRIVATE_PROPERTY_OFFSET
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_59_PROLOG
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_RPC_WRAPPERS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_INCLASS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_RPC_WRAPPERS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_INCLASS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h_62_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CRIWARERUNTIME_API UClass* StaticClass<class USoundAtomCueSheet>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCueSheet_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
