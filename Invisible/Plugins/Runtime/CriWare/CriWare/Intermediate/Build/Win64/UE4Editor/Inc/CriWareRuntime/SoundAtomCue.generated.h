// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CRIWARERUNTIME_SoundAtomCue_generated_h
#error "SoundAtomCue.generated.h already included, missing '#pragma once' in SoundAtomCue.h"
#endif
#define CRIWARERUNTIME_SoundAtomCue_generated_h

#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_SPARSE_DATA
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetUserData) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetUserData(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLength) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetLength(); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetUserData) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetUserData(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLength) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetLength(); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(USoundAtomCue, NO_API)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSoundAtomCue(); \
	friend struct Z_Construct_UClass_USoundAtomCue_Statics; \
public: \
	DECLARE_CLASS(USoundAtomCue, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(USoundAtomCue) \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_ARCHIVESERIALIZER


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_INCLASS \
private: \
	static void StaticRegisterNativesUSoundAtomCue(); \
	friend struct Z_Construct_UClass_USoundAtomCue_Statics; \
public: \
	DECLARE_CLASS(USoundAtomCue, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(USoundAtomCue) \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_ARCHIVESERIALIZER


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USoundAtomCue(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USoundAtomCue) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USoundAtomCue); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USoundAtomCue); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USoundAtomCue(USoundAtomCue&&); \
	NO_API USoundAtomCue(const USoundAtomCue&); \
public:


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USoundAtomCue(USoundAtomCue&&); \
	NO_API USoundAtomCue(const USoundAtomCue&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USoundAtomCue); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USoundAtomCue); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USoundAtomCue)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_PRIVATE_PROPERTY_OFFSET
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_56_PROLOG
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_RPC_WRAPPERS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_INCLASS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_RPC_WRAPPERS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_INCLASS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h_59_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CRIWARERUNTIME_API UClass* StaticClass<class USoundAtomCue>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_SoundAtomCue_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
