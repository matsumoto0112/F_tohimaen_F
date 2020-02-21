// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDataTable;
struct FAtomTriggerRow;
#ifdef CRIWARERUNTIME_AtomTriggerTableFunctionLibrary_generated_h
#error "AtomTriggerTableFunctionLibrary.generated.h already included, missing '#pragma once' in AtomTriggerTableFunctionLibrary.h"
#endif
#define CRIWARERUNTIME_AtomTriggerTableFunctionLibrary_generated_h

#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_57_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAtomTriggerRow_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> CRIWARERUNTIME_API UScriptStruct* StaticStruct<struct FAtomTriggerRow>();

#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_SPARSE_DATA
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetDataTableRowFromName) \
	{ \
		P_GET_OBJECT(UDataTable,Z_Param_Table); \
		P_GET_PROPERTY(UNameProperty,Z_Param_RowName); \
		P_GET_STRUCT_REF(FAtomTriggerRow,Z_Param_Out_OutRow); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UAtomTriggerTableFunctionLibrary::GetDataTableRowFromName(Z_Param_Table,Z_Param_RowName,Z_Param_Out_OutRow); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetDataTableRowFromName) \
	{ \
		P_GET_OBJECT(UDataTable,Z_Param_Table); \
		P_GET_PROPERTY(UNameProperty,Z_Param_RowName); \
		P_GET_STRUCT_REF(FAtomTriggerRow,Z_Param_Out_OutRow); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UAtomTriggerTableFunctionLibrary::GetDataTableRowFromName(Z_Param_Table,Z_Param_RowName,Z_Param_Out_OutRow); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAtomTriggerTableFunctionLibrary(); \
	friend struct Z_Construct_UClass_UAtomTriggerTableFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UAtomTriggerTableFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(UAtomTriggerTableFunctionLibrary)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_INCLASS \
private: \
	static void StaticRegisterNativesUAtomTriggerTableFunctionLibrary(); \
	friend struct Z_Construct_UClass_UAtomTriggerTableFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UAtomTriggerTableFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(UAtomTriggerTableFunctionLibrary)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAtomTriggerTableFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAtomTriggerTableFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAtomTriggerTableFunctionLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAtomTriggerTableFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAtomTriggerTableFunctionLibrary(UAtomTriggerTableFunctionLibrary&&); \
	NO_API UAtomTriggerTableFunctionLibrary(const UAtomTriggerTableFunctionLibrary&); \
public:


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAtomTriggerTableFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAtomTriggerTableFunctionLibrary(UAtomTriggerTableFunctionLibrary&&); \
	NO_API UAtomTriggerTableFunctionLibrary(const UAtomTriggerTableFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAtomTriggerTableFunctionLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAtomTriggerTableFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAtomTriggerTableFunctionLibrary)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_PRIVATE_PROPERTY_OFFSET
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_75_PROLOG
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_RPC_WRAPPERS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_INCLASS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_RPC_WRAPPERS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_INCLASS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h_78_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CRIWARERUNTIME_API UClass* StaticClass<class UAtomTriggerTableFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_AtomTriggerTableFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
