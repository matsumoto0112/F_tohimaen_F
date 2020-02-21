// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ECriFsBinderStatus : uint8;
#ifdef CRIWARERUNTIME_CriFsBinderComponent_generated_h
#error "CriFsBinderComponent.generated.h already included, missing '#pragma once' in CriFsBinderComponent.h"
#endif
#define CRIWARERUNTIME_CriFsBinderComponent_generated_h

#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_71_DELEGATE \
static inline void FOnBindError_DelegateWrapper(const FMulticastScriptDelegate& OnBindError) \
{ \
	OnBindError.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_70_DELEGATE \
static inline void FOnBindCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnBindCompleted) \
{ \
	OnBindCompleted.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_SPARSE_DATA
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetStatus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ECriFsBinderStatus*)Z_Param__Result=P_THIS->GetStatus(); \
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
	DECLARE_FUNCTION(execBind) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Bind(); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetStatus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ECriFsBinderStatus*)Z_Param__Result=P_THIS->GetStatus(); \
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
	DECLARE_FUNCTION(execBind) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Bind(); \
		P_NATIVE_END; \
	}


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCriFsBinderComponent(); \
	friend struct Z_Construct_UClass_UCriFsBinderComponent_Statics; \
public: \
	DECLARE_CLASS(UCriFsBinderComponent, USceneComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(UCriFsBinderComponent)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_INCLASS \
private: \
	static void StaticRegisterNativesUCriFsBinderComponent(); \
	friend struct Z_Construct_UClass_UCriFsBinderComponent_Statics; \
public: \
	DECLARE_CLASS(UCriFsBinderComponent, USceneComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CriWareRuntime"), NO_API) \
	DECLARE_SERIALIZER(UCriFsBinderComponent)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCriFsBinderComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCriFsBinderComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCriFsBinderComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCriFsBinderComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCriFsBinderComponent(UCriFsBinderComponent&&); \
	NO_API UCriFsBinderComponent(const UCriFsBinderComponent&); \
public:


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCriFsBinderComponent(UCriFsBinderComponent&&); \
	NO_API UCriFsBinderComponent(const UCriFsBinderComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCriFsBinderComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCriFsBinderComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCriFsBinderComponent)


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_PRIVATE_PROPERTY_OFFSET
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_65_PROLOG
#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_RPC_WRAPPERS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_INCLASS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_PRIVATE_PROPERTY_OFFSET \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_SPARSE_DATA \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_RPC_WRAPPERS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_INCLASS_NO_PURE_DECLS \
	Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h_68_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CRIWARERUNTIME_API UClass* StaticClass<class UCriFsBinderComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Invisible_Plugins_Runtime_CriWare_CriWare_Source_CriWareRuntime_Classes_CriFsBinderComponent_h


#define FOREACH_ENUM_ECRIFSBINDERSTATUS(op) \
	op(ECriFsBinderStatus::Stop) \
	op(ECriFsBinderStatus::Binding) \
	op(ECriFsBinderStatus::Complete) \
	op(ECriFsBinderStatus::Error) 

enum class ECriFsBinderStatus : uint8;
template<> CRIWARERUNTIME_API UEnum* StaticEnum<ECriFsBinderStatus>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
