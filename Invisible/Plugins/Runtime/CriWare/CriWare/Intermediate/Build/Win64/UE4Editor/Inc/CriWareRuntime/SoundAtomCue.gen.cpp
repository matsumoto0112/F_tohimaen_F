// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CriWareRuntime/Classes/SoundAtomCue.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSoundAtomCue() {}
// Cross Module References
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_USoundAtomCue_NoRegister();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_USoundAtomCue();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_CriWareRuntime();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_USoundAtomCue_GetLength();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_USoundAtomCue_GetUserData();
	ENGINE_API UClass* Z_Construct_UClass_USoundAttenuation_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FSoundConcurrencySettings();
	ENGINE_API UClass* Z_Construct_UClass_USoundConcurrency_NoRegister();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_USoundAtomCueSheet_NoRegister();
// End Cross Module References
	void USoundAtomCue::StaticRegisterNativesUSoundAtomCue()
	{
		UClass* Class = USoundAtomCue::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetLength", &USoundAtomCue::execGetLength },
			{ "GetUserData", &USoundAtomCue::execGetUserData },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USoundAtomCue_GetLength_Statics
	{
		struct SoundAtomCue_eventGetLength_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USoundAtomCue_GetLength_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoundAtomCue_eventGetLength_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USoundAtomCue_GetLength_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCue_GetLength_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USoundAtomCue_GetLength_Statics::Function_MetaDataParams[] = {
		{ "Category", "Sound Atom Cue" },
		{ "ModuleRelativePath", "Classes/SoundAtomCue.h" },
		{ "ToolTip", "Get the length of the cue sheet." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USoundAtomCue_GetLength_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USoundAtomCue, nullptr, "GetLength", nullptr, nullptr, sizeof(SoundAtomCue_eventGetLength_Parms), Z_Construct_UFunction_USoundAtomCue_GetLength_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCue_GetLength_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USoundAtomCue_GetLength_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCue_GetLength_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USoundAtomCue_GetLength()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USoundAtomCue_GetLength_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USoundAtomCue_GetUserData_Statics
	{
		struct SoundAtomCue_eventGetUserData_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USoundAtomCue_GetUserData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoundAtomCue_eventGetUserData_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USoundAtomCue_GetUserData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCue_GetUserData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USoundAtomCue_GetUserData_Statics::Function_MetaDataParams[] = {
		{ "Category", "Sound Atom Cue" },
		{ "ModuleRelativePath", "Classes/SoundAtomCue.h" },
		{ "ToolTip", "Get user data of the cue sheet." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USoundAtomCue_GetUserData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USoundAtomCue, nullptr, "GetUserData", nullptr, nullptr, sizeof(SoundAtomCue_eventGetUserData_Parms), Z_Construct_UFunction_USoundAtomCue_GetUserData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCue_GetUserData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USoundAtomCue_GetUserData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCue_GetUserData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USoundAtomCue_GetUserData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USoundAtomCue_GetUserData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USoundAtomCue_NoRegister()
	{
		return USoundAtomCue::StaticClass();
	}
	struct Z_Construct_UClass_USoundAtomCue_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AisacControlName_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_AisacControlName;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AisacControlName_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CategoryName_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_CategoryName;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CategoryName_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UserData_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_UserData;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Duration_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Duration;
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultAttenuation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DefaultAttenuation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Priority_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Priority;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConcurrencyOverrides_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ConcurrencyOverrides;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SoundConcurrencySettings_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SoundConcurrencySettings;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bOverrideConcurrency_MetaData[];
#endif
		static void NewProp_bOverrideConcurrency_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bOverrideConcurrency;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bApplyAtomParameter_MetaData[];
#endif
		static void NewProp_bApplyAtomParameter_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bApplyAtomParameter;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CueName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CueName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CueSheet_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CueSheet;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USoundAtomCue_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_CriWareRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USoundAtomCue_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USoundAtomCue_GetLength, "GetLength" }, // 1030671025
		{ &Z_Construct_UFunction_USoundAtomCue_GetUserData, "GetUserData" }, // 4208575619
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCue_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "SoundAtomCue.h" },
		{ "ModuleRelativePath", "Classes/SoundAtomCue.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "SoundAtomCue class." },
	};
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCue_Statics::NewProp_AisacControlName_MetaData[] = {
		{ "Category", "Info" },
		{ "Comment", "/* AISAC\xe3\x82\xb3\xe3\x83\xb3\xe3\x83\x88\xe3\x83\xad\xe3\x83\xbc\xe3\x83\xab\xe5\x90\x8d\xe4\xb8\x80\xe8\xa6\xa7 */" },
		{ "ModuleRelativePath", "Classes/SoundAtomCue.h" },
		{ "ToolTip", "AISAC\xe3\x82\xb3\xe3\x83\xb3\xe3\x83\x88\xe3\x83\xad\xe3\x83\xbc\xe3\x83\xab\xe5\x90\x8d\xe4\xb8\x80\xe8\xa6\xa7" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USoundAtomCue_Statics::NewProp_AisacControlName = { "AisacControlName", nullptr, (EPropertyFlags)0x0010000800020001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomCue, AisacControlName), METADATA_PARAMS(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_AisacControlName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_AisacControlName_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USoundAtomCue_Statics::NewProp_AisacControlName_Inner = { "AisacControlName", nullptr, (EPropertyFlags)0x0000000800020000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CategoryName_MetaData[] = {
		{ "Category", "Info" },
		{ "Comment", "/* \xe3\x82\xab\xe3\x83\x86\xe3\x82\xb4\xe3\x83\xaa\xe5\x90\x8d\xe4\xb8\x80\xe8\xa6\xa7 */" },
		{ "ModuleRelativePath", "Classes/SoundAtomCue.h" },
		{ "ToolTip", "\xe3\x82\xab\xe3\x83\x86\xe3\x82\xb4\xe3\x83\xaa\xe5\x90\x8d\xe4\xb8\x80\xe8\xa6\xa7" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000800020001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomCue, CategoryName), METADATA_PARAMS(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CategoryName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CategoryName_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CategoryName_Inner = { "CategoryName", nullptr, (EPropertyFlags)0x0000000800020000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCue_Statics::NewProp_UserData_MetaData[] = {
		{ "Category", "Info" },
		{ "Comment", "/* \xe3\x83\xa6\xe3\x83\xbc\xe3\x82\xb6\xe3\x83\x87\xe3\x83\xbc\xe3\x82\xbf */" },
		{ "ModuleRelativePath", "Classes/SoundAtomCue.h" },
		{ "ToolTip", "\xe3\x83\xa6\xe3\x83\xbc\xe3\x82\xb6\xe3\x83\x87\xe3\x83\xbc\xe3\x82\xbf" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USoundAtomCue_Statics::NewProp_UserData = { "UserData", nullptr, (EPropertyFlags)0x0010000800020001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomCue, UserData), METADATA_PARAMS(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_UserData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_UserData_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCue_Statics::NewProp_Duration_MetaData[] = {
		{ "Category", "Info" },
		{ "Comment", "/** Duration of sound in seconds. */" },
		{ "ModuleRelativePath", "Classes/SoundAtomCue.h" },
		{ "ToolTip", "Duration of sound in seconds." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USoundAtomCue_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000800020001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomCue, Duration), METADATA_PARAMS(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_Duration_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_Duration_MetaData)) };
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCue_Statics::NewProp_DefaultAttenuation_MetaData[] = {
		{ "Category", "Attenuation" },
		{ "ModuleRelativePath", "Classes/SoundAtomCue.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USoundAtomCue_Statics::NewProp_DefaultAttenuation = { "DefaultAttenuation", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomCue, DefaultAttenuation), Z_Construct_UClass_USoundAttenuation_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_DefaultAttenuation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_DefaultAttenuation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCue_Statics::NewProp_Priority_MetaData[] = {
		{ "Category", "Concurrency" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.0" },
		{ "Comment", "/** Sound priority (higher value is higher priority) used for concurrency resolution. This priority value is weighted against the final volume of the sound. */" },
		{ "ModuleRelativePath", "Classes/SoundAtomCue.h" },
		{ "ToolTip", "Sound priority (higher value is higher priority) used for concurrency resolution. This priority value is weighted against the final volume of the sound." },
		{ "UIMax", "100.0" },
		{ "UIMin", "0.0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USoundAtomCue_Statics::NewProp_Priority = { "Priority", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomCue, Priority), METADATA_PARAMS(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_Priority_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_Priority_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCue_Statics::NewProp_ConcurrencyOverrides_MetaData[] = {
		{ "Category", "Concurrency" },
		{ "Comment", "/** If Override Concurrency is true, concurrency settings to use. */" },
		{ "EditCondition", "bOverrideConcurrency" },
		{ "ModuleRelativePath", "Classes/SoundAtomCue.h" },
		{ "ToolTip", "If Override Concurrency is true, concurrency settings to use." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USoundAtomCue_Statics::NewProp_ConcurrencyOverrides = { "ConcurrencyOverrides", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomCue, ConcurrencyOverrides), Z_Construct_UScriptStruct_FSoundConcurrencySettings, METADATA_PARAMS(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_ConcurrencyOverrides_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_ConcurrencyOverrides_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCue_Statics::NewProp_SoundConcurrencySettings_MetaData[] = {
		{ "Category", "Concurrency" },
		{ "Comment", "/** If Override Concurrency is false, the sound concurrency settings to use for this sound. */" },
		{ "EditCondition", "!bOverrideConcurrency" },
		{ "ModuleRelativePath", "Classes/SoundAtomCue.h" },
		{ "ToolTip", "If Override Concurrency is false, the sound concurrency settings to use for this sound." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USoundAtomCue_Statics::NewProp_SoundConcurrencySettings = { "SoundConcurrencySettings", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomCue, SoundConcurrencySettings), Z_Construct_UClass_USoundConcurrency_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_SoundConcurrencySettings_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_SoundConcurrencySettings_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCue_Statics::NewProp_bOverrideConcurrency_MetaData[] = {
		{ "Category", "Concurrency" },
		{ "Comment", "/** Whether or not to override the sound concurrency object with local concurrency settings. */" },
		{ "ModuleRelativePath", "Classes/SoundAtomCue.h" },
		{ "ToolTip", "Whether or not to override the sound concurrency object with local concurrency settings." },
	};
#endif
	void Z_Construct_UClass_USoundAtomCue_Statics::NewProp_bOverrideConcurrency_SetBit(void* Obj)
	{
		((USoundAtomCue*)Obj)->bOverrideConcurrency = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USoundAtomCue_Statics::NewProp_bOverrideConcurrency = { "bOverrideConcurrency", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USoundAtomCue), &Z_Construct_UClass_USoundAtomCue_Statics::NewProp_bOverrideConcurrency_SetBit, METADATA_PARAMS(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_bOverrideConcurrency_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_bOverrideConcurrency_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCue_Statics::NewProp_bApplyAtomParameter_MetaData[] = {
		{ "Category", "Atom" },
		{ "ModuleRelativePath", "Classes/SoundAtomCue.h" },
		{ "ToolTip", "Searches AtomParameterComponent of the owner actor and applies it on play." },
	};
#endif
	void Z_Construct_UClass_USoundAtomCue_Statics::NewProp_bApplyAtomParameter_SetBit(void* Obj)
	{
		((USoundAtomCue*)Obj)->bApplyAtomParameter = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USoundAtomCue_Statics::NewProp_bApplyAtomParameter = { "bApplyAtomParameter", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USoundAtomCue), &Z_Construct_UClass_USoundAtomCue_Statics::NewProp_bApplyAtomParameter_SetBit, METADATA_PARAMS(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_bApplyAtomParameter_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_bApplyAtomParameter_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CueName_MetaData[] = {
		{ "Category", "Target" },
		{ "ModuleRelativePath", "Classes/SoundAtomCue.h" },
		{ "ToolTip", "Cue name." },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CueName = { "CueName", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomCue, CueName), METADATA_PARAMS(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CueName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CueName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CueSheet_MetaData[] = {
		{ "Category", "Reference" },
		{ "ModuleRelativePath", "Classes/SoundAtomCue.h" },
		{ "ToolTip", "Cue sheet." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CueSheet = { "CueSheet", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomCue, CueSheet), Z_Construct_UClass_USoundAtomCueSheet_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CueSheet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CueSheet_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USoundAtomCue_Statics::PropPointers[] = {
#if WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCue_Statics::NewProp_AisacControlName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCue_Statics::NewProp_AisacControlName_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CategoryName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CategoryName_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCue_Statics::NewProp_UserData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCue_Statics::NewProp_Duration,
#endif // WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCue_Statics::NewProp_DefaultAttenuation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCue_Statics::NewProp_Priority,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCue_Statics::NewProp_ConcurrencyOverrides,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCue_Statics::NewProp_SoundConcurrencySettings,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCue_Statics::NewProp_bOverrideConcurrency,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCue_Statics::NewProp_bApplyAtomParameter,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CueName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCue_Statics::NewProp_CueSheet,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USoundAtomCue_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USoundAtomCue>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USoundAtomCue_Statics::ClassParams = {
		&USoundAtomCue::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USoundAtomCue_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCue_Statics::PropPointers),
		0,
		0x001010A0u,
		METADATA_PARAMS(Z_Construct_UClass_USoundAtomCue_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCue_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USoundAtomCue()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USoundAtomCue_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USoundAtomCue, 2150229733);
	template<> CRIWARERUNTIME_API UClass* StaticClass<USoundAtomCue>()
	{
		return USoundAtomCue::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USoundAtomCue(Z_Construct_UClass_USoundAtomCue, &USoundAtomCue::StaticClass, TEXT("/Script/CriWareRuntime"), TEXT("USoundAtomCue"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USoundAtomCue);
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(USoundAtomCue)
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
