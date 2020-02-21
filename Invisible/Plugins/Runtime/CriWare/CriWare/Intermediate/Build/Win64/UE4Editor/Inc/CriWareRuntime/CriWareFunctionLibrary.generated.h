// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ECriWareSpeakerSystem : uint8;
#ifdef CRIWARERUNTIME_CriWareFunctionLibrary_generated_h
#error "CriWareFunctionLibrary.generated.h already included, missing '#pragma once' in CriWareFunctionLibrary.h"
#endif
#define CRIWARERUNTIME_CriWareFunctionLibrary_generated_h

#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_SPARSE_DATA
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetGlobalLabelToSelectorByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_SelectorName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_LabelName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UCriWareFunctionLibrary::SetGlobalLabelToSelectorByName(Z_Param_SelectorName,Z_Param_LabelName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetGameVariableByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_GameVariableName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UCriWareFunctionLibrary::SetGameVariableByName(Z_Param_GameVariableName,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSpeakerAngleArray) \
	{ \
		P_GET_ENUM(ECriWareSpeakerSystem,Z_Param_SpeakerSystem); \
		P_GET_TARRAY_REF(float,Z_Param_Out_Angles); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UCriWareFunctionLibrary::SetSpeakerAngleArray(ECriWareSpeakerSystem(Z_Param_SpeakerSystem),Z_Param_Out_Angles); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetGlobalLabelToSelectorByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_SelectorName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_LabelName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UCriWareFunctionLibrary::SetGlobalLabelToSelectorByName(Z_Param_SelectorName,Z_Param_LabelName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetGameVariableByName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_GameVariableName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UCriWareFunctionLibrary::SetGameVariableByName(Z_Param_GameVariableName,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSpeakerAngleArray) \
	{ \
		P_GET_ENUM(ECriWareSpeakerSystem,Z_Param_SpeakerSystem); \
		P_GET_TARRAY_REF(float,Z_Param_Out_Angles); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UCriWareFunctionLibrary::SetSpeakerAngleArray(ECriWareSpeakerSystem(Z_Param_SpeakerSystem),Z_Param_Out_Angles); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCriWareFunctionLibrary(); \
	friend struct Z_Construct_UClass_UCriWareFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UCriWareFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(UCriWareFunctionLibrary)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_INCLASS \
private: \
	static void StaticRegisterNativesUCriWareFunctionLibrary(); \
	friend struct Z_Construct_UClass_UCriWareFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UCriWareFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(UCriWareFunctionLibrary)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCriWareFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCriWareFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCriWareFunctionLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCriWareFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCriWareFunctionLibrary(UCriWareFunctionLibrary&&); \
	NO_API UCriWareFunctionLibrary(const UCriWareFunctionLibrary&); \
public:


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCriWareFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCriWareFunctionLibrary(UCriWareFunctionLibrary&&); \
	NO_API UCriWareFunctionLibrary(const UCriWareFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCriWareFunctionLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCriWareFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCriWareFunctionLibrary)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_PRIVATE_PROPERTY_OFFSET
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_58_PROLOG
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_RPC_WRAPPERS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_INCLASS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_RPC_WRAPPERS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_INCLASS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h_61_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CRIWARERUNTIME_API UClass* StaticClass<class UCriWareFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriWareFunctionLibrary_h


#define FOREACH_ENUM_ECRIWARESPEAKERSYSTEM(op) \
	op(ECriWareSpeakerSystem::Surround5Point1) \
	op(ECriWareSpeakerSystem::Surround7Point1) 

enum class ECriWareSpeakerSystem : uint8;
template<> CRIWARERUNTIME_API UEnum* StaticEnum<ECriWareSpeakerSystem>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
