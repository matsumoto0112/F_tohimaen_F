// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CriWareRuntime/Classes/AtomAsrRack.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAtomAsrRack() {}
// Cross Module References
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_UAtomAsrRack_NoRegister();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_UAtomAsrRack();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_CriWareRuntime();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomAsrRack_ApplyDspBusSnapshot();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomAsrRack_AttachDspBusSetting();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomAsrRack_DetachDspBusSetting();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomAsrRack_GetAsrRack();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomAsrRack_GetDefaultAsrRack();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomAsrRack_SetBusVolumeByName();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass();
// End Cross Module References
	void UAtomAsrRack::StaticRegisterNativesUAtomAsrRack()
	{
		UClass* Class = UAtomAsrRack::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ApplyDspBusSnapshot", &UAtomAsrRack::execApplyDspBusSnapshot },
			{ "AttachDspBusSetting", &UAtomAsrRack::execAttachDspBusSetting },
			{ "DetachDspBusSetting", &UAtomAsrRack::execDetachDspBusSetting },
			{ "GetAsrRack", &UAtomAsrRack::execGetAsrRack },
			{ "GetBusAnalyzerInfo", &UAtomAsrRack::execGetBusAnalyzerInfo },
			{ "GetDefaultAsrRack", &UAtomAsrRack::execGetDefaultAsrRack },
			{ "SetBusSendLevelByName", &UAtomAsrRack::execSetBusSendLevelByName },
			{ "SetBusVolumeByName", &UAtomAsrRack::execSetBusVolumeByName },
			{ "SetEffectBypass", &UAtomAsrRack::execSetEffectBypass },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAtomAsrRack_ApplyDspBusSnapshot_Statics
	{
		struct AtomAsrRack_eventApplyDspBusSnapshot_Parms
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
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAtomAsrRack_ApplyDspBusSnapshot_Statics::NewProp_Milliseconds = { "Milliseconds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventApplyDspBusSnapshot_Parms, Milliseconds), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomAsrRack_ApplyDspBusSnapshot_Statics::NewProp_SnapshotName = { "SnapshotName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventApplyDspBusSnapshot_Parms, SnapshotName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomAsrRack_ApplyDspBusSnapshot_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_ApplyDspBusSnapshot_Statics::NewProp_Milliseconds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_ApplyDspBusSnapshot_Statics::NewProp_SnapshotName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomAsrRack_ApplyDspBusSnapshot_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomAsrRack" },
		{ "ModuleRelativePath", "Classes/AtomAsrRack.h" },
		{ "ToolTip", "Apply DSP bus snapshot." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomAsrRack_ApplyDspBusSnapshot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomAsrRack, nullptr, "ApplyDspBusSnapshot", nullptr, nullptr, sizeof(AtomAsrRack_eventApplyDspBusSnapshot_Parms), Z_Construct_UFunction_UAtomAsrRack_ApplyDspBusSnapshot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_ApplyDspBusSnapshot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomAsrRack_ApplyDspBusSnapshot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_ApplyDspBusSnapshot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomAsrRack_ApplyDspBusSnapshot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomAsrRack_ApplyDspBusSnapshot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomAsrRack_AttachDspBusSetting_Statics
	{
		struct AtomAsrRack_eventAttachDspBusSetting_Parms
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
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomAsrRack_AttachDspBusSetting_Statics::NewProp_SettingName = { "SettingName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventAttachDspBusSetting_Parms, SettingName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomAsrRack_AttachDspBusSetting_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_AttachDspBusSetting_Statics::NewProp_SettingName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomAsrRack_AttachDspBusSetting_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomAsrRack" },
		{ "ModuleRelativePath", "Classes/AtomAsrRack.h" },
		{ "ToolTip", "Attach DSP bus setting." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomAsrRack_AttachDspBusSetting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomAsrRack, nullptr, "AttachDspBusSetting", nullptr, nullptr, sizeof(AtomAsrRack_eventAttachDspBusSetting_Parms), Z_Construct_UFunction_UAtomAsrRack_AttachDspBusSetting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_AttachDspBusSetting_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomAsrRack_AttachDspBusSetting_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_AttachDspBusSetting_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomAsrRack_AttachDspBusSetting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomAsrRack_AttachDspBusSetting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomAsrRack_DetachDspBusSetting_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomAsrRack_DetachDspBusSetting_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomAsrRack" },
		{ "ModuleRelativePath", "Classes/AtomAsrRack.h" },
		{ "ToolTip", "Detach DSP bus setting." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomAsrRack_DetachDspBusSetting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomAsrRack, nullptr, "DetachDspBusSetting", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomAsrRack_DetachDspBusSetting_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_DetachDspBusSetting_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomAsrRack_DetachDspBusSetting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomAsrRack_DetachDspBusSetting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomAsrRack_GetAsrRack_Statics
	{
		struct AtomAsrRack_eventGetAsrRack_Parms
		{
			int32 AsrRackId;
			UAtomAsrRack* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_AsrRackId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomAsrRack_GetAsrRack_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventGetAsrRack_Parms, ReturnValue), Z_Construct_UClass_UAtomAsrRack_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAtomAsrRack_GetAsrRack_Statics::NewProp_AsrRackId = { "AsrRackId", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventGetAsrRack_Parms, AsrRackId), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomAsrRack_GetAsrRack_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_GetAsrRack_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_GetAsrRack_Statics::NewProp_AsrRackId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomAsrRack_GetAsrRack_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomAsrRack" },
		{ "ModuleRelativePath", "Classes/AtomAsrRack.h" },
		{ "ToolTip", "Get ASR rack." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomAsrRack_GetAsrRack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomAsrRack, nullptr, "GetAsrRack", nullptr, nullptr, sizeof(AtomAsrRack_eventGetAsrRack_Parms), Z_Construct_UFunction_UAtomAsrRack_GetAsrRack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_GetAsrRack_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomAsrRack_GetAsrRack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_GetAsrRack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomAsrRack_GetAsrRack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomAsrRack_GetAsrRack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics
	{
		struct AtomAsrRack_eventGetBusAnalyzerInfo_Parms
		{
			FString DspBusName;
			int32 num_channels;
			TArray<float> rms_levels;
			TArray<float> peak_levels;
			TArray<float> peak_hold_levels;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_peak_hold_levels;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_peak_hold_levels_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_peak_levels;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_peak_levels_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_rms_levels;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_rms_levels_Inner;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_num_channels;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_DspBusName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((AtomAsrRack_eventGetBusAnalyzerInfo_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomAsrRack_eventGetBusAnalyzerInfo_Parms), &Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_peak_hold_levels = { "peak_hold_levels", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventGetBusAnalyzerInfo_Parms, peak_hold_levels), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_peak_hold_levels_Inner = { "peak_hold_levels", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_peak_levels = { "peak_levels", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventGetBusAnalyzerInfo_Parms, peak_levels), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_peak_levels_Inner = { "peak_levels", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_rms_levels = { "rms_levels", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventGetBusAnalyzerInfo_Parms, rms_levels), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_rms_levels_Inner = { "rms_levels", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_num_channels = { "num_channels", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventGetBusAnalyzerInfo_Parms, num_channels), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_DspBusName = { "DspBusName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventGetBusAnalyzerInfo_Parms, DspBusName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_peak_hold_levels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_peak_hold_levels_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_peak_levels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_peak_levels_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_rms_levels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_rms_levels_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_num_channels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::NewProp_DspBusName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomAsrRack" },
		{ "ModuleRelativePath", "Classes/AtomAsrRack.h" },
		{ "ToolTip", "Set bus send level." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomAsrRack, nullptr, "GetBusAnalyzerInfo", nullptr, nullptr, sizeof(AtomAsrRack_eventGetBusAnalyzerInfo_Parms), Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomAsrRack_GetDefaultAsrRack_Statics
	{
		struct AtomAsrRack_eventGetDefaultAsrRack_Parms
		{
			UAtomAsrRack* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomAsrRack_GetDefaultAsrRack_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventGetDefaultAsrRack_Parms, ReturnValue), Z_Construct_UClass_UAtomAsrRack_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomAsrRack_GetDefaultAsrRack_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_GetDefaultAsrRack_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomAsrRack_GetDefaultAsrRack_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomAsrRack" },
		{ "ModuleRelativePath", "Classes/AtomAsrRack.h" },
		{ "ToolTip", "Get the default ASR rack." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomAsrRack_GetDefaultAsrRack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomAsrRack, nullptr, "GetDefaultAsrRack", nullptr, nullptr, sizeof(AtomAsrRack_eventGetDefaultAsrRack_Parms), Z_Construct_UFunction_UAtomAsrRack_GetDefaultAsrRack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_GetDefaultAsrRack_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomAsrRack_GetDefaultAsrRack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_GetDefaultAsrRack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomAsrRack_GetDefaultAsrRack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomAsrRack_GetDefaultAsrRack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName_Statics
	{
		struct AtomAsrRack_eventSetBusSendLevelByName_Parms
		{
			FString SourceBusName;
			FString DestBusName;
			float Level;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Level;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_DestBusName;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_SourceBusName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventSetBusSendLevelByName_Parms, Level), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName_Statics::NewProp_DestBusName = { "DestBusName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventSetBusSendLevelByName_Parms, DestBusName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName_Statics::NewProp_SourceBusName = { "SourceBusName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventSetBusSendLevelByName_Parms, SourceBusName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName_Statics::NewProp_Level,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName_Statics::NewProp_DestBusName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName_Statics::NewProp_SourceBusName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomAsrRack" },
		{ "ModuleRelativePath", "Classes/AtomAsrRack.h" },
		{ "ToolTip", "Set bus send level." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomAsrRack, nullptr, "SetBusSendLevelByName", nullptr, nullptr, sizeof(AtomAsrRack_eventSetBusSendLevelByName_Parms), Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomAsrRack_SetBusVolumeByName_Statics
	{
		struct AtomAsrRack_eventSetBusVolumeByName_Parms
		{
			FString BusName;
			float Volume;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Volume;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_BusName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomAsrRack_SetBusVolumeByName_Statics::NewProp_Volume = { "Volume", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventSetBusVolumeByName_Parms, Volume), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomAsrRack_SetBusVolumeByName_Statics::NewProp_BusName = { "BusName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventSetBusVolumeByName_Parms, BusName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomAsrRack_SetBusVolumeByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_SetBusVolumeByName_Statics::NewProp_Volume,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_SetBusVolumeByName_Statics::NewProp_BusName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomAsrRack_SetBusVolumeByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomAsrRack" },
		{ "ModuleRelativePath", "Classes/AtomAsrRack.h" },
		{ "ToolTip", "Set bus volume." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomAsrRack_SetBusVolumeByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomAsrRack, nullptr, "SetBusVolumeByName", nullptr, nullptr, sizeof(AtomAsrRack_eventSetBusVolumeByName_Parms), Z_Construct_UFunction_UAtomAsrRack_SetBusVolumeByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_SetBusVolumeByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomAsrRack_SetBusVolumeByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_SetBusVolumeByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomAsrRack_SetBusVolumeByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomAsrRack_SetBusVolumeByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics
	{
		struct AtomAsrRack_eventSetEffectBypass_Parms
		{
			FString BusName;
			FString EffectName;
			bool Bypasses;
		};
		static void NewProp_Bypasses_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Bypasses;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_EffectName;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_BusName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics::NewProp_Bypasses_SetBit(void* Obj)
	{
		((AtomAsrRack_eventSetEffectBypass_Parms*)Obj)->Bypasses = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics::NewProp_Bypasses = { "Bypasses", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomAsrRack_eventSetEffectBypass_Parms), &Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics::NewProp_Bypasses_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics::NewProp_EffectName = { "EffectName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventSetEffectBypass_Parms, EffectName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics::NewProp_BusName = { "BusName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomAsrRack_eventSetEffectBypass_Parms, BusName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics::NewProp_Bypasses,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics::NewProp_EffectName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics::NewProp_BusName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomAsrRack" },
		{ "ModuleRelativePath", "Classes/AtomAsrRack.h" },
		{ "ToolTip", "Set effect bypass." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomAsrRack, nullptr, "SetEffectBypass", nullptr, nullptr, sizeof(AtomAsrRack_eventSetEffectBypass_Parms), Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAtomAsrRack_NoRegister()
	{
		return UAtomAsrRack::StaticClass();
	}
	struct Z_Construct_UClass_UAtomAsrRack_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RackId_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_RackId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAtomAsrRack_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_CriWareRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAtomAsrRack_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAtomAsrRack_ApplyDspBusSnapshot, "ApplyDspBusSnapshot" }, // 614907558
		{ &Z_Construct_UFunction_UAtomAsrRack_AttachDspBusSetting, "AttachDspBusSetting" }, // 3817202688
		{ &Z_Construct_UFunction_UAtomAsrRack_DetachDspBusSetting, "DetachDspBusSetting" }, // 3596999542
		{ &Z_Construct_UFunction_UAtomAsrRack_GetAsrRack, "GetAsrRack" }, // 1822061315
		{ &Z_Construct_UFunction_UAtomAsrRack_GetBusAnalyzerInfo, "GetBusAnalyzerInfo" }, // 358452257
		{ &Z_Construct_UFunction_UAtomAsrRack_GetDefaultAsrRack, "GetDefaultAsrRack" }, // 145955877
		{ &Z_Construct_UFunction_UAtomAsrRack_SetBusSendLevelByName, "SetBusSendLevelByName" }, // 2021352415
		{ &Z_Construct_UFunction_UAtomAsrRack_SetBusVolumeByName, "SetBusVolumeByName" }, // 296106135
		{ &Z_Construct_UFunction_UAtomAsrRack_SetEffectBypass, "SetEffectBypass" }, // 3852635872
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAtomAsrRack_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "AtomAsrRack.h" },
		{ "ModuleRelativePath", "Classes/AtomAsrRack.h" },
		{ "ToolTip", "AtomAsrRack class." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAtomAsrRack_Statics::NewProp_RackId_MetaData[] = {
		{ "Category", "AtomAsrRack" },
		{ "ModuleRelativePath", "Classes/AtomAsrRack.h" },
		{ "ToolTip", "Rack ID." },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UAtomAsrRack_Statics::NewProp_RackId = { "RackId", nullptr, (EPropertyFlags)0x0010000000020815, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAtomAsrRack, RackId), METADATA_PARAMS(Z_Construct_UClass_UAtomAsrRack_Statics::NewProp_RackId_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAtomAsrRack_Statics::NewProp_RackId_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAtomAsrRack_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAtomAsrRack_Statics::NewProp_RackId,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAtomAsrRack_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAtomAsrRack>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAtomAsrRack_Statics::ClassParams = {
		&UAtomAsrRack::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UAtomAsrRack_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UAtomAsrRack_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UAtomAsrRack_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UAtomAsrRack_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAtomAsrRack()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAtomAsrRack_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAtomAsrRack, 100732191);
	template<> CRIWARERUNTIME_API UClass* StaticClass<UAtomAsrRack>()
	{
		return UAtomAsrRack::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAtomAsrRack(Z_Construct_UClass_UAtomAsrRack, &UAtomAsrRack::StaticClass, TEXT("/Script/CriWareRuntime"), TEXT("UAtomAsrRack"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAtomAsrRack);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
