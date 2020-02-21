// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FAtomAisacInfo;
#ifdef CRIWARERUNTIME_AtomCategory_generated_h
#error "AtomCategory.generated.h already included, missing '#pragma once' in AtomCategory.h"
#endif
#define CRIWARERUNTIME_AtomCategory_generated_h

#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_SPARSE_DATA
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execStopByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomCategory::StopByName(Z_Param_CategoryName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentAisacControlValueByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_AisacControlName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=UAtomCategory::GetCurrentAisacControlValueByName(Z_Param_CategoryName,Z_Param_AisacControlName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentAisacControlValueById) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_CategoryId); \
		P_GET_PROPERTY(UIntProperty,Z_Param_AisacControlId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=UAtomCategory::GetCurrentAisacControlValueById(Z_Param_CategoryId,Z_Param_AisacControlId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAisacControlByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_AisacName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomCategory::SetAisacControlByName(Z_Param_CategoryName,Z_Param_AisacName,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAttachedAisacInfoByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_GET_PROPERTY(UIntProperty,Z_Param_AisacAttachedIndex); \
		P_GET_UBOOL_REF(Z_Param_Out_IsSuccess); \
		P_GET_STRUCT_REF(FAtomAisacInfo,Z_Param_Out_AisacInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomCategory::GetAttachedAisacInfoByName(Z_Param_CategoryName,Z_Param_AisacAttachedIndex,Z_Param_Out_IsSuccess,Z_Param_Out_AisacInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAttachedAisacInfoById) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_CategoryId); \
		P_GET_PROPERTY(UIntProperty,Z_Param_AisacAttachedIndex); \
		P_GET_UBOOL_REF(Z_Param_Out_IsSuccess); \
		P_GET_STRUCT_REF(FAtomAisacInfo,Z_Param_Out_AisacInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomCategory::GetAttachedAisacInfoById(Z_Param_CategoryId,Z_Param_AisacAttachedIndex,Z_Param_Out_IsSuccess,Z_Param_Out_AisacInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumAttachedAisacsByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=UAtomCategory::GetNumAttachedAisacsByName(Z_Param_CategoryName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumAttachedAisacsById) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_CategoryId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=UAtomCategory::GetNumAttachedAisacsById(Z_Param_CategoryId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetAllAisacControlByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UAtomCategory::ResetAllAisacControlByName(Z_Param_CategoryName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetAllAisacControlById) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_CategoryId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UAtomCategory::ResetAllAisacControlById(Z_Param_CategoryId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsPausedByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UAtomCategory::IsPausedByName(Z_Param_CategoryName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPauseByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_GET_UBOOL(Z_Param_bPause); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomCategory::PauseByName(Z_Param_CategoryName,Z_Param_bPause); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVolumeByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=UAtomCategory::GetVolumeByName(Z_Param_CategoryName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVolumeByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomCategory::SetVolumeByName(Z_Param_CategoryName,Z_Param_Volume); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStopByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomCategory::StopByName(Z_Param_CategoryName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentAisacControlValueByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_AisacControlName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=UAtomCategory::GetCurrentAisacControlValueByName(Z_Param_CategoryName,Z_Param_AisacControlName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentAisacControlValueById) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_CategoryId); \
		P_GET_PROPERTY(UIntProperty,Z_Param_AisacControlId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=UAtomCategory::GetCurrentAisacControlValueById(Z_Param_CategoryId,Z_Param_AisacControlId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAisacControlByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_AisacName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomCategory::SetAisacControlByName(Z_Param_CategoryName,Z_Param_AisacName,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAttachedAisacInfoByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_GET_PROPERTY(UIntProperty,Z_Param_AisacAttachedIndex); \
		P_GET_UBOOL_REF(Z_Param_Out_IsSuccess); \
		P_GET_STRUCT_REF(FAtomAisacInfo,Z_Param_Out_AisacInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomCategory::GetAttachedAisacInfoByName(Z_Param_CategoryName,Z_Param_AisacAttachedIndex,Z_Param_Out_IsSuccess,Z_Param_Out_AisacInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAttachedAisacInfoById) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_CategoryId); \
		P_GET_PROPERTY(UIntProperty,Z_Param_AisacAttachedIndex); \
		P_GET_UBOOL_REF(Z_Param_Out_IsSuccess); \
		P_GET_STRUCT_REF(FAtomAisacInfo,Z_Param_Out_AisacInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomCategory::GetAttachedAisacInfoById(Z_Param_CategoryId,Z_Param_AisacAttachedIndex,Z_Param_Out_IsSuccess,Z_Param_Out_AisacInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumAttachedAisacsByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=UAtomCategory::GetNumAttachedAisacsByName(Z_Param_CategoryName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumAttachedAisacsById) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_CategoryId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=UAtomCategory::GetNumAttachedAisacsById(Z_Param_CategoryId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetAllAisacControlByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UAtomCategory::ResetAllAisacControlByName(Z_Param_CategoryName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetAllAisacControlById) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_CategoryId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UAtomCategory::ResetAllAisacControlById(Z_Param_CategoryId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsPausedByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UAtomCategory::IsPausedByName(Z_Param_CategoryName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPauseByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_GET_UBOOL(Z_Param_bPause); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomCategory::PauseByName(Z_Param_CategoryName,Z_Param_bPause); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVolumeByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=UAtomCategory::GetVolumeByName(Z_Param_CategoryName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVolumeByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CategoryName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomCategory::SetVolumeByName(Z_Param_CategoryName,Z_Param_Volume); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAtomCategory(); \
	friend struct Z_Construct_UClass_UAtomCategory_Statics; \
public: \
	DECLARE_CLASS(UAtomCategory, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(UAtomCategory)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_INCLASS \
private: \
	static void StaticRegisterNativesUAtomCategory(); \
	friend struct Z_Construct_UClass_UAtomCategory_Statics; \
public: \
	DECLARE_CLASS(UAtomCategory, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(UAtomCategory)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAtomCategory(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAtomCategory) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAtomCategory); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAtomCategory); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAtomCategory(UAtomCategory&&); \
	NO_API UAtomCategory(const UAtomCategory&); \
public:


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAtomCategory(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAtomCategory(UAtomCategory&&); \
	NO_API UAtomCategory(const UAtomCategory&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAtomCategory); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAtomCategory); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAtomCategory)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_PRIVATE_PROPERTY_OFFSET
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_54_PROLOG
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_RPC_WRAPPERS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_INCLASS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_RPC_WRAPPERS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_INCLASS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h_57_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CRIWARERUNTIME_API UClass* StaticClass<class UAtomCategory>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomCategory_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
