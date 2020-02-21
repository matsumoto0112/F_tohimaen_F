// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FAtomProfileItem;
enum class EAtomProfileSortType : uint8;
enum class EAtomSortOrderType : uint8;
class UObject;
#ifdef CRIWARERUNTIME_AtomProfileData_generated_h
#error "AtomProfileData.generated.h already included, missing '#pragma once' in AtomProfileData.h"
#endif
#define CRIWARERUNTIME_AtomProfileData_generated_h

#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_76_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAtomProfileItem_Statics; \
	CRIWARERUNTIME_API static class UScriptStruct* StaticStruct();


template<> CRIWARERUNTIME_API UScriptStruct* StaticStruct<struct FAtomProfileItem>();

#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_SPARSE_DATA
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCriWareAdx2ProfileDataSort) \
	{ \
		P_GET_TARRAY(FAtomProfileItem,Z_Param_original_item); \
		P_GET_ENUM(EAtomProfileSortType,Z_Param_sort_type); \
		P_GET_ENUM(EAtomSortOrderType,Z_Param_order_type); \
		P_GET_TARRAY_REF(FAtomProfileItem,Z_Param_Out_sorted_item); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomProfileData::CriWareAdx2ProfileDataSort(Z_Param_original_item,EAtomProfileSortType(Z_Param_sort_type),EAtomSortOrderType(Z_Param_order_type),Z_Param_Out_sorted_item); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCriWareAdx2ProfileDataUpdate) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FAtomProfileItem>*)Z_Param__Result=UAtomProfileData::CriWareAdx2ProfileDataUpdate(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCriWareAdx2ProfileDataSort) \
	{ \
		P_GET_TARRAY(FAtomProfileItem,Z_Param_original_item); \
		P_GET_ENUM(EAtomProfileSortType,Z_Param_sort_type); \
		P_GET_ENUM(EAtomSortOrderType,Z_Param_order_type); \
		P_GET_TARRAY_REF(FAtomProfileItem,Z_Param_Out_sorted_item); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAtomProfileData::CriWareAdx2ProfileDataSort(Z_Param_original_item,EAtomProfileSortType(Z_Param_sort_type),EAtomSortOrderType(Z_Param_order_type),Z_Param_Out_sorted_item); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCriWareAdx2ProfileDataUpdate) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FAtomProfileItem>*)Z_Param__Result=UAtomProfileData::CriWareAdx2ProfileDataUpdate(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAtomProfileData(); \
	friend struct Z_Construct_UClass_UAtomProfileData_Statics; \
public: \
	DECLARE_CLASS(UAtomProfileData, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(UAtomProfileData)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_INCLASS \
private: \
	static void StaticRegisterNativesUAtomProfileData(); \
	friend struct Z_Construct_UClass_UAtomProfileData_Statics; \
public: \
	DECLARE_CLASS(UAtomProfileData, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(UAtomProfileData)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAtomProfileData(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAtomProfileData) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAtomProfileData); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAtomProfileData); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAtomProfileData(UAtomProfileData&&); \
	NO_API UAtomProfileData(const UAtomProfileData&); \
public:


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAtomProfileData(UAtomProfileData&&); \
	NO_API UAtomProfileData(const UAtomProfileData&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAtomProfileData); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAtomProfileData); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UAtomProfileData)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_PRIVATE_PROPERTY_OFFSET
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_123_PROLOG
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_RPC_WRAPPERS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_INCLASS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_RPC_WRAPPERS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_INCLASS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h_126_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CRIWARERUNTIME_API UClass* StaticClass<class UAtomProfileData>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomProfileData_h


#define FOREACH_ENUM_EATOMSORTORDERTYPE(op) \
	op(EAtomSortOrderType::Ascending) \
	op(EAtomSortOrderType::Descending) 

enum class EAtomSortOrderType : uint8;
template<> CRIWARERUNTIME_API UEnum* StaticEnum<EAtomSortOrderType>();

#define FOREACH_ENUM_EATOMPROFILESORTTYPE(op) \
	op(EAtomProfileSortType::AtomComponentID) \
	op(EAtomProfileSortType::Distance) \
	op(EAtomProfileSortType::Name) \
	op(EAtomProfileSortType::Time) 

enum class EAtomProfileSortType : uint8;
template<> CRIWARERUNTIME_API UEnum* StaticEnum<EAtomProfileSortType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
