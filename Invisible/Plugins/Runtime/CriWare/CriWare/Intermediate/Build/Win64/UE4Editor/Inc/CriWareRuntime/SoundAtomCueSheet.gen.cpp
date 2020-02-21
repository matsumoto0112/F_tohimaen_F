// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CriWareRuntime/Classes/SoundAtomCueSheet.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSoundAtomCueSheet() {}
// Cross Module References
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_USoundAtomCueSheet_NoRegister();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_USoundAtomCueSheet();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_CriWareRuntime();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_USoundAtomCueSheet_ApplyDspBusSnapshot();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_USoundAtomCueSheet_AttachDspBusSetting();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_USoundAtomCueSheet_DetachDspBusSetting();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueById();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_USoundAtomCue_NoRegister();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByIndex();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByName();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_USoundAtomCueSheet_IsLoaded();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_USoundAtomCueSheet_LoadAcb();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_USoundAtomCueSheet_LoadAtomCueSheet();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_USoundAtomCueSheet_ReleaseAcb();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FDirectoryPath();
	ENGINE_API UClass* Z_Construct_UClass_UAssetImportData_NoRegister();
// End Cross Module References
	void USoundAtomCueSheet::StaticRegisterNativesUSoundAtomCueSheet()
	{
		UClass* Class = USoundAtomCueSheet::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ApplyDspBusSnapshot", &USoundAtomCueSheet::execApplyDspBusSnapshot },
			{ "AttachDspBusSetting", &USoundAtomCueSheet::execAttachDspBusSetting },
			{ "DetachDspBusSetting", &USoundAtomCueSheet::execDetachDspBusSetting },
			{ "GetAtomCueById", &USoundAtomCueSheet::execGetAtomCueById },
			{ "GetAtomCueByIndex", &USoundAtomCueSheet::execGetAtomCueByIndex },
			{ "GetAtomCueByName", &USoundAtomCueSheet::execGetAtomCueByName },
			{ "IsLoaded", &USoundAtomCueSheet::execIsLoaded },
			{ "LoadAcb", &USoundAtomCueSheet::execLoadAcb },
			{ "LoadAtomCueSheet", &USoundAtomCueSheet::execLoadAtomCueSheet },
			{ "ReleaseAcb", &USoundAtomCueSheet::execReleaseAcb },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USoundAtomCueSheet_ApplyDspBusSnapshot_Statics
	{
		struct SoundAtomCueSheet_eventApplyDspBusSnapshot_Parms
		{
			FString SnapshotName;
			int32 Milliseconds;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Milliseconds;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_SnapshotName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USoundAtomCueSheet_ApplyDspBusSnapshot_Statics::NewProp_Milliseconds = { "Milliseconds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoundAtomCueSheet_eventApplyDspBusSnapshot_Parms, Milliseconds), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USoundAtomCueSheet_ApplyDspBusSnapshot_Statics::NewProp_SnapshotName = { "SnapshotName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoundAtomCueSheet_eventApplyDspBusSnapshot_Parms, SnapshotName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USoundAtomCueSheet_ApplyDspBusSnapshot_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCueSheet_ApplyDspBusSnapshot_Statics::NewProp_Milliseconds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCueSheet_ApplyDspBusSnapshot_Statics::NewProp_SnapshotName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USoundAtomCueSheet_ApplyDspBusSnapshot_Statics::Function_MetaDataParams[] = {
		{ "Category", "CRIWARE" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ToolTip", "Apply DSP bus setting." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USoundAtomCueSheet_ApplyDspBusSnapshot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USoundAtomCueSheet, nullptr, "ApplyDspBusSnapshot", nullptr, nullptr, sizeof(SoundAtomCueSheet_eventApplyDspBusSnapshot_Parms), Z_Construct_UFunction_USoundAtomCueSheet_ApplyDspBusSnapshot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_ApplyDspBusSnapshot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USoundAtomCueSheet_ApplyDspBusSnapshot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_ApplyDspBusSnapshot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USoundAtomCueSheet_ApplyDspBusSnapshot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USoundAtomCueSheet_ApplyDspBusSnapshot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USoundAtomCueSheet_AttachDspBusSetting_Statics
	{
		struct SoundAtomCueSheet_eventAttachDspBusSetting_Parms
		{
			FString SettingName;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_SettingName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USoundAtomCueSheet_AttachDspBusSetting_Statics::NewProp_SettingName = { "SettingName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoundAtomCueSheet_eventAttachDspBusSetting_Parms, SettingName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USoundAtomCueSheet_AttachDspBusSetting_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCueSheet_AttachDspBusSetting_Statics::NewProp_SettingName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USoundAtomCueSheet_AttachDspBusSetting_Statics::Function_MetaDataParams[] = {
		{ "Category", "CRIWARE" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ToolTip", "Attach DSP bus setting." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USoundAtomCueSheet_AttachDspBusSetting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USoundAtomCueSheet, nullptr, "AttachDspBusSetting", nullptr, nullptr, sizeof(SoundAtomCueSheet_eventAttachDspBusSetting_Parms), Z_Construct_UFunction_USoundAtomCueSheet_AttachDspBusSetting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_AttachDspBusSetting_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USoundAtomCueSheet_AttachDspBusSetting_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_AttachDspBusSetting_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USoundAtomCueSheet_AttachDspBusSetting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USoundAtomCueSheet_AttachDspBusSetting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USoundAtomCueSheet_DetachDspBusSetting_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USoundAtomCueSheet_DetachDspBusSetting_Statics::Function_MetaDataParams[] = {
		{ "Category", "CRIWARE" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ToolTip", "Detach DSP bus setting." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USoundAtomCueSheet_DetachDspBusSetting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USoundAtomCueSheet, nullptr, "DetachDspBusSetting", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USoundAtomCueSheet_DetachDspBusSetting_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_DetachDspBusSetting_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USoundAtomCueSheet_DetachDspBusSetting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USoundAtomCueSheet_DetachDspBusSetting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueById_Statics
	{
		struct SoundAtomCueSheet_eventGetAtomCueById_Parms
		{
			int32 CueId;
			USoundAtomCue* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CueId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueById_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoundAtomCueSheet_eventGetAtomCueById_Parms, ReturnValue), Z_Construct_UClass_USoundAtomCue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueById_Statics::NewProp_CueId = { "CueId", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoundAtomCueSheet_eventGetAtomCueById_Parms, CueId), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueById_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueById_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueById_Statics::NewProp_CueId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueById_Statics::Function_MetaDataParams[] = {
		{ "Category", "Atom Cue Sheet" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ToolTip", "Gets Atom Cue asset from cue sheet by ID." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueById_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USoundAtomCueSheet, nullptr, "GetAtomCueById", nullptr, nullptr, sizeof(SoundAtomCueSheet_eventGetAtomCueById_Parms), Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueById_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueById_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueById_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueById_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueById()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueById_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByIndex_Statics
	{
		struct SoundAtomCueSheet_eventGetAtomCueByIndex_Parms
		{
			int32 CueIndex;
			USoundAtomCue* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CueIndex;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoundAtomCueSheet_eventGetAtomCueByIndex_Parms, ReturnValue), Z_Construct_UClass_USoundAtomCue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByIndex_Statics::NewProp_CueIndex = { "CueIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoundAtomCueSheet_eventGetAtomCueByIndex_Parms, CueIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByIndex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByIndex_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByIndex_Statics::NewProp_CueIndex,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "Atom Cue Sheet" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ToolTip", "Gets Atom Cue asset from cue sheet by index." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USoundAtomCueSheet, nullptr, "GetAtomCueByIndex", nullptr, nullptr, sizeof(SoundAtomCueSheet_eventGetAtomCueByIndex_Parms), Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByIndex_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByIndex_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByName_Statics
	{
		struct SoundAtomCueSheet_eventGetAtomCueByName_Parms
		{
			FString CueName;
			USoundAtomCue* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CueName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoundAtomCueSheet_eventGetAtomCueByName_Parms, ReturnValue), Z_Construct_UClass_USoundAtomCue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByName_Statics::NewProp_CueName = { "CueName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoundAtomCueSheet_eventGetAtomCueByName_Parms, CueName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByName_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByName_Statics::NewProp_CueName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Atom Cue Sheet" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ToolTip", "Gets Atom Cue asset from cue sheet by name." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USoundAtomCueSheet, nullptr, "GetAtomCueByName", nullptr, nullptr, sizeof(SoundAtomCueSheet_eventGetAtomCueByName_Parms), Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USoundAtomCueSheet_IsLoaded_Statics
	{
		struct SoundAtomCueSheet_eventIsLoaded_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USoundAtomCueSheet_IsLoaded_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SoundAtomCueSheet_eventIsLoaded_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USoundAtomCueSheet_IsLoaded_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SoundAtomCueSheet_eventIsLoaded_Parms), &Z_Construct_UFunction_USoundAtomCueSheet_IsLoaded_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USoundAtomCueSheet_IsLoaded_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCueSheet_IsLoaded_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USoundAtomCueSheet_IsLoaded_Statics::Function_MetaDataParams[] = {
		{ "Category", "Atom Cue Sheet" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ToolTip", "Checks whether the cue sheet is loaded." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USoundAtomCueSheet_IsLoaded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USoundAtomCueSheet, nullptr, "IsLoaded", nullptr, nullptr, sizeof(SoundAtomCueSheet_eventIsLoaded_Parms), Z_Construct_UFunction_USoundAtomCueSheet_IsLoaded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_IsLoaded_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USoundAtomCueSheet_IsLoaded_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_IsLoaded_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USoundAtomCueSheet_IsLoaded()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USoundAtomCueSheet_IsLoaded_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USoundAtomCueSheet_LoadAcb_Statics
	{
		struct SoundAtomCueSheet_eventLoadAcb_Parms
		{
			FName AcbName;
			USoundAtomCueSheet* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_AcbName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USoundAtomCueSheet_LoadAcb_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoundAtomCueSheet_eventLoadAcb_Parms, ReturnValue), Z_Construct_UClass_USoundAtomCueSheet_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USoundAtomCueSheet_LoadAcb_Statics::NewProp_AcbName = { "AcbName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoundAtomCueSheet_eventLoadAcb_Parms, AcbName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USoundAtomCueSheet_LoadAcb_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCueSheet_LoadAcb_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCueSheet_LoadAcb_Statics::NewProp_AcbName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USoundAtomCueSheet_LoadAcb_Statics::Function_MetaDataParams[] = {
		{ "Category", "CRIWARE" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ToolTip", "Searchs and loads Atom Cue Sheet asset by name." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USoundAtomCueSheet_LoadAcb_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USoundAtomCueSheet, nullptr, "LoadAcb", nullptr, nullptr, sizeof(SoundAtomCueSheet_eventLoadAcb_Parms), Z_Construct_UFunction_USoundAtomCueSheet_LoadAcb_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_LoadAcb_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USoundAtomCueSheet_LoadAcb_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_LoadAcb_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USoundAtomCueSheet_LoadAcb()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USoundAtomCueSheet_LoadAcb_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USoundAtomCueSheet_LoadAtomCueSheet_Statics
	{
		struct SoundAtomCueSheet_eventLoadAtomCueSheet_Parms
		{
			USoundAtomCueSheet* CueSheet;
			USoundAtomCueSheet* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CueSheet;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USoundAtomCueSheet_LoadAtomCueSheet_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoundAtomCueSheet_eventLoadAtomCueSheet_Parms, ReturnValue), Z_Construct_UClass_USoundAtomCueSheet_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USoundAtomCueSheet_LoadAtomCueSheet_Statics::NewProp_CueSheet = { "CueSheet", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoundAtomCueSheet_eventLoadAtomCueSheet_Parms, CueSheet), Z_Construct_UClass_USoundAtomCueSheet_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USoundAtomCueSheet_LoadAtomCueSheet_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCueSheet_LoadAtomCueSheet_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCueSheet_LoadAtomCueSheet_Statics::NewProp_CueSheet,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USoundAtomCueSheet_LoadAtomCueSheet_Statics::Function_MetaDataParams[] = {
		{ "Category", "Atom Cue Sheet" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ToolTip", "Loads Atom Cue Sheet asset." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USoundAtomCueSheet_LoadAtomCueSheet_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USoundAtomCueSheet, nullptr, "LoadAtomCueSheet", nullptr, nullptr, sizeof(SoundAtomCueSheet_eventLoadAtomCueSheet_Parms), Z_Construct_UFunction_USoundAtomCueSheet_LoadAtomCueSheet_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_LoadAtomCueSheet_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USoundAtomCueSheet_LoadAtomCueSheet_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_LoadAtomCueSheet_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USoundAtomCueSheet_LoadAtomCueSheet()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USoundAtomCueSheet_LoadAtomCueSheet_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USoundAtomCueSheet_ReleaseAcb_Statics
	{
		struct SoundAtomCueSheet_eventReleaseAcb_Parms
		{
			FName AcbName;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_AcbName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USoundAtomCueSheet_ReleaseAcb_Statics::NewProp_AcbName = { "AcbName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoundAtomCueSheet_eventReleaseAcb_Parms, AcbName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USoundAtomCueSheet_ReleaseAcb_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoundAtomCueSheet_ReleaseAcb_Statics::NewProp_AcbName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USoundAtomCueSheet_ReleaseAcb_Statics::Function_MetaDataParams[] = {
		{ "Category", "CRIWARE" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ToolTip", "This function has no effect." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USoundAtomCueSheet_ReleaseAcb_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USoundAtomCueSheet, nullptr, "ReleaseAcb", nullptr, nullptr, sizeof(SoundAtomCueSheet_eventReleaseAcb_Parms), Z_Construct_UFunction_USoundAtomCueSheet_ReleaseAcb_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_ReleaseAcb_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USoundAtomCueSheet_ReleaseAcb_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USoundAtomCueSheet_ReleaseAcb_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USoundAtomCueSheet_ReleaseAcb()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USoundAtomCueSheet_ReleaseAcb_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USoundAtomCueSheet_NoRegister()
	{
		return USoundAtomCueSheet::StaticClass();
	}
	struct Z_Construct_UClass_USoundAtomCueSheet_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NumSlots_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_NumSlots;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CueSheetName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CueSheetName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AwbDirectory_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AwbDirectory;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bOverrideAwbDirectory_MetaData[];
#endif
		static void NewProp_bOverrideAwbDirectory_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bOverrideAwbDirectory;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AcbFilePath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AcbFilePath;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Contains_MetaData[];
#endif
		static void NewProp_Contains_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Contains;
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AssetImportData_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AssetImportData;
#endif // WITH_EDITORONLY_DATA
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USoundAtomCueSheet_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_CriWareRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USoundAtomCueSheet_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USoundAtomCueSheet_ApplyDspBusSnapshot, "ApplyDspBusSnapshot" }, // 2779503119
		{ &Z_Construct_UFunction_USoundAtomCueSheet_AttachDspBusSetting, "AttachDspBusSetting" }, // 3370314793
		{ &Z_Construct_UFunction_USoundAtomCueSheet_DetachDspBusSetting, "DetachDspBusSetting" }, // 1729113087
		{ &Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueById, "GetAtomCueById" }, // 1134482394
		{ &Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByIndex, "GetAtomCueByIndex" }, // 3965102779
		{ &Z_Construct_UFunction_USoundAtomCueSheet_GetAtomCueByName, "GetAtomCueByName" }, // 3134402302
		{ &Z_Construct_UFunction_USoundAtomCueSheet_IsLoaded, "IsLoaded" }, // 1996988336
		{ &Z_Construct_UFunction_USoundAtomCueSheet_LoadAcb, "LoadAcb" }, // 1739754184
		{ &Z_Construct_UFunction_USoundAtomCueSheet_LoadAtomCueSheet, "LoadAtomCueSheet" }, // 1095210729
		{ &Z_Construct_UFunction_USoundAtomCueSheet_ReleaseAcb, "ReleaseAcb" }, // 4109702687
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCueSheet_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "object" },
		{ "IncludePath", "SoundAtomCueSheet.h" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "SoundAtomCueSheet class." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_NumSlots_MetaData[] = {
		{ "Category", "Details" },
		{ "DisplayName", "Number of related AWB files" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ToolTip", "Number of related AWB files." },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_NumSlots = { "NumSlots", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomCueSheet, NumSlots), METADATA_PARAMS(Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_NumSlots_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_NumSlots_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_CueSheetName_MetaData[] = {
		{ "Category", "Details" },
		{ "DisplayName", "CueSheet name" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ToolTip", "CueSheet name." },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_CueSheetName = { "CueSheetName", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomCueSheet, CueSheetName), METADATA_PARAMS(Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_CueSheetName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_CueSheetName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_AwbDirectory_MetaData[] = {
		{ "Category", "AwbFileHandling" },
		{ "DisplayName", "AWB directory" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ToolTip", "Directory containing AWB file." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_AwbDirectory = { "AwbDirectory", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomCueSheet, AwbDirectory), Z_Construct_UScriptStruct_FDirectoryPath, METADATA_PARAMS(Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_AwbDirectory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_AwbDirectory_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_bOverrideAwbDirectory_MetaData[] = {
		{ "Category", "AwbFileHandling" },
		{ "DisplayName", "Override AWB directory" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ToolTip", "Load AWB file from the specified path. Ignore [Non-Asset Content Directory] setting." },
	};
#endif
	void Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_bOverrideAwbDirectory_SetBit(void* Obj)
	{
		((USoundAtomCueSheet*)Obj)->bOverrideAwbDirectory = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_bOverrideAwbDirectory = { "bOverrideAwbDirectory", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USoundAtomCueSheet), &Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_bOverrideAwbDirectory_SetBit, METADATA_PARAMS(Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_bOverrideAwbDirectory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_bOverrideAwbDirectory_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_AcbFilePath_MetaData[] = {
		{ "Comment", "/** DEPRECATED - ACB file path is now stored in AssetImportData. */" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ToolTip", "DEPRECATED - ACB file path is now stored in AssetImportData." },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_AcbFilePath = { "AcbFilePath", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomCueSheet, AcbFilePath), METADATA_PARAMS(Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_AcbFilePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_AcbFilePath_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_Contains_MetaData[] = {
		{ "Category", "AcbDataHandling" },
		{ "DisplayName", "Is ACB data contained" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
		{ "ToolTip", "Is ACB data contained." },
	};
#endif
	void Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_Contains_SetBit(void* Obj)
	{
		((USoundAtomCueSheet*)Obj)->Contains = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_Contains = { "Contains", nullptr, (EPropertyFlags)0x0010000000022001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USoundAtomCueSheet), &Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_Contains_SetBit, METADATA_PARAMS(Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_Contains_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_Contains_MetaData)) };
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_AssetImportData_MetaData[] = {
		{ "Category", "Reimport" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueSheet.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_AssetImportData = { "AssetImportData", nullptr, (EPropertyFlags)0x0012000800080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomCueSheet, AssetImportData), Z_Construct_UClass_UAssetImportData_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_AssetImportData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_AssetImportData_MetaData)) };
#endif // WITH_EDITORONLY_DATA
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USoundAtomCueSheet_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_NumSlots,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_CueSheetName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_AwbDirectory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_bOverrideAwbDirectory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_AcbFilePath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_Contains,
#if WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomCueSheet_Statics::NewProp_AssetImportData,
#endif // WITH_EDITORONLY_DATA
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USoundAtomCueSheet_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USoundAtomCueSheet>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USoundAtomCueSheet_Statics::ClassParams = {
		&USoundAtomCueSheet::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USoundAtomCueSheet_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCueSheet_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USoundAtomCueSheet_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCueSheet_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USoundAtomCueSheet()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USoundAtomCueSheet_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USoundAtomCueSheet, 2424639845);
	template<> CRIWARERUNTIME_API UClass* StaticClass<USoundAtomCueSheet>()
	{
		return USoundAtomCueSheet::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USoundAtomCueSheet(Z_Construct_UClass_USoundAtomCueSheet, &USoundAtomCueSheet::StaticClass, TEXT("/Script/CriWareRuntime"), TEXT("USoundAtomCueSheet"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USoundAtomCueSheet);
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(USoundAtomCueSheet)
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
