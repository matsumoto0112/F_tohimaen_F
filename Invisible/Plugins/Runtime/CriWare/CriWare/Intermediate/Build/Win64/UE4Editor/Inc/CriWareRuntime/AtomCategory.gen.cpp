// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CriWareRuntime/Classes/AtomCategory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAtomCategory() {}
// Cross Module References
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_UAtomCategory_NoRegister();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_UAtomCategory();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_CriWareRuntime();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById();
	CRIWARERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FAtomAisacInfo();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsById();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsByName();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomCategory_GetVolumeByName();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomCategory_IsPausedByName();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomCategory_PauseByName();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomCategory_SetAisacControlByName();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomCategory_SetVolumeByName();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomCategory_StopByName();
// End Cross Module References
	void UAtomCategory::StaticRegisterNativesUAtomCategory()
	{
		UClass* Class = UAtomCategory::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAttachedAisacInfoById", &UAtomCategory::execGetAttachedAisacInfoById },
			{ "GetAttachedAisacInfoByName", &UAtomCategory::execGetAttachedAisacInfoByName },
			{ "GetCurrentAisacControlValueById", &UAtomCategory::execGetCurrentAisacControlValueById },
			{ "GetCurrentAisacControlValueByName", &UAtomCategory::execGetCurrentAisacControlValueByName },
			{ "GetNumAttachedAisacsById", &UAtomCategory::execGetNumAttachedAisacsById },
			{ "GetNumAttachedAisacsByName", &UAtomCategory::execGetNumAttachedAisacsByName },
			{ "GetVolumeByName", &UAtomCategory::execGetVolumeByName },
			{ "IsPausedByName", &UAtomCategory::execIsPausedByName },
			{ "PauseByName", &UAtomCategory::execPauseByName },
			{ "ResetAllAisacControlById", &UAtomCategory::execResetAllAisacControlById },
			{ "ResetAllAisacControlByName", &UAtomCategory::execResetAllAisacControlByName },
			{ "SetAisacControlByName", &UAtomCategory::execSetAisacControlByName },
			{ "SetVolumeByName", &UAtomCategory::execSetVolumeByName },
			{ "StopByName", &UAtomCategory::execStopByName },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics
	{
		struct AtomCategory_eventGetAttachedAisacInfoById_Parms
		{
			int32 CategoryId;
			int32 AisacAttachedIndex;
			bool IsSuccess;
			FAtomAisacInfo AisacInfo;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AisacInfo;
		static void NewProp_IsSuccess_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsSuccess;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_AisacAttachedIndex;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CategoryId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::NewProp_AisacInfo = { "AisacInfo", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetAttachedAisacInfoById_Parms, AisacInfo), Z_Construct_UScriptStruct_FAtomAisacInfo, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::NewProp_IsSuccess_SetBit(void* Obj)
	{
		((AtomCategory_eventGetAttachedAisacInfoById_Parms*)Obj)->IsSuccess = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::NewProp_IsSuccess = { "IsSuccess", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomCategory_eventGetAttachedAisacInfoById_Parms), &Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::NewProp_IsSuccess_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::NewProp_AisacAttachedIndex = { "AisacAttachedIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetAttachedAisacInfoById_Parms, AisacAttachedIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::NewProp_CategoryId = { "CategoryId", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetAttachedAisacInfoById_Parms, CategoryId), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::NewProp_AisacInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::NewProp_IsSuccess,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::NewProp_AisacAttachedIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::NewProp_CategoryId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomCategory" },
		{ "ModuleRelativePath", "Classes/AtomCategory.h" },
		{ "ToolTip", "Get attached AISAC info by id." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomCategory, nullptr, "GetAttachedAisacInfoById", nullptr, nullptr, sizeof(AtomCategory_eventGetAttachedAisacInfoById_Parms), Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics
	{
		struct AtomCategory_eventGetAttachedAisacInfoByName_Parms
		{
			FString CategoryName;
			int32 AisacAttachedIndex;
			bool IsSuccess;
			FAtomAisacInfo AisacInfo;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AisacInfo;
		static void NewProp_IsSuccess_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsSuccess;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_AisacAttachedIndex;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CategoryName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::NewProp_AisacInfo = { "AisacInfo", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetAttachedAisacInfoByName_Parms, AisacInfo), Z_Construct_UScriptStruct_FAtomAisacInfo, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::NewProp_IsSuccess_SetBit(void* Obj)
	{
		((AtomCategory_eventGetAttachedAisacInfoByName_Parms*)Obj)->IsSuccess = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::NewProp_IsSuccess = { "IsSuccess", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomCategory_eventGetAttachedAisacInfoByName_Parms), &Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::NewProp_IsSuccess_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::NewProp_AisacAttachedIndex = { "AisacAttachedIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetAttachedAisacInfoByName_Parms, AisacAttachedIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetAttachedAisacInfoByName_Parms, CategoryName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::NewProp_AisacInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::NewProp_IsSuccess,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::NewProp_AisacAttachedIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::NewProp_CategoryName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomCategory" },
		{ "ModuleRelativePath", "Classes/AtomCategory.h" },
		{ "ToolTip", "Get attached AISAC info by name." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomCategory, nullptr, "GetAttachedAisacInfoByName", nullptr, nullptr, sizeof(AtomCategory_eventGetAttachedAisacInfoByName_Parms), Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById_Statics
	{
		struct AtomCategory_eventGetCurrentAisacControlValueById_Parms
		{
			int32 CategoryId;
			int32 AisacControlId;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_AisacControlId;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CategoryId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetCurrentAisacControlValueById_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById_Statics::NewProp_AisacControlId = { "AisacControlId", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetCurrentAisacControlValueById_Parms, AisacControlId), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById_Statics::NewProp_CategoryId = { "CategoryId", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetCurrentAisacControlValueById_Parms, CategoryId), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById_Statics::NewProp_AisacControlId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById_Statics::NewProp_CategoryId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomCategory" },
		{ "ModuleRelativePath", "Classes/AtomCategory.h" },
		{ "ToolTip", "Get current AISAC control value by id." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomCategory, nullptr, "GetCurrentAisacControlValueById", nullptr, nullptr, sizeof(AtomCategory_eventGetCurrentAisacControlValueById_Parms), Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName_Statics
	{
		struct AtomCategory_eventGetCurrentAisacControlValueByName_Parms
		{
			FString CategoryName;
			FString AisacControlName;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AisacControlName;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CategoryName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetCurrentAisacControlValueByName_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName_Statics::NewProp_AisacControlName = { "AisacControlName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetCurrentAisacControlValueByName_Parms, AisacControlName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetCurrentAisacControlValueByName_Parms, CategoryName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName_Statics::NewProp_AisacControlName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName_Statics::NewProp_CategoryName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomCategory" },
		{ "ModuleRelativePath", "Classes/AtomCategory.h" },
		{ "ToolTip", "Get current AISAC control value by name." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomCategory, nullptr, "GetCurrentAisacControlValueByName", nullptr, nullptr, sizeof(AtomCategory_eventGetCurrentAisacControlValueByName_Parms), Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsById_Statics
	{
		struct AtomCategory_eventGetNumAttachedAisacsById_Parms
		{
			int32 CategoryId;
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CategoryId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsById_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetNumAttachedAisacsById_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsById_Statics::NewProp_CategoryId = { "CategoryId", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetNumAttachedAisacsById_Parms, CategoryId), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsById_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsById_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsById_Statics::NewProp_CategoryId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsById_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomCategory" },
		{ "ModuleRelativePath", "Classes/AtomCategory.h" },
		{ "ToolTip", "Get number of attached AISACs by id." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsById_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomCategory, nullptr, "GetNumAttachedAisacsById", nullptr, nullptr, sizeof(AtomCategory_eventGetNumAttachedAisacsById_Parms), Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsById_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsById_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsById_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsById_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsById()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsById_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsByName_Statics
	{
		struct AtomCategory_eventGetNumAttachedAisacsByName_Parms
		{
			FString CategoryName;
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CategoryName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetNumAttachedAisacsByName_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsByName_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetNumAttachedAisacsByName_Parms, CategoryName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsByName_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsByName_Statics::NewProp_CategoryName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomCategory" },
		{ "ModuleRelativePath", "Classes/AtomCategory.h" },
		{ "ToolTip", "Get number of attached AISACs by name." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomCategory, nullptr, "GetNumAttachedAisacsByName", nullptr, nullptr, sizeof(AtomCategory_eventGetNumAttachedAisacsByName_Parms), Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomCategory_GetVolumeByName_Statics
	{
		struct AtomCategory_eventGetVolumeByName_Parms
		{
			FString CategoryName;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CategoryName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomCategory_GetVolumeByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetVolumeByName_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomCategory_GetVolumeByName_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventGetVolumeByName_Parms, CategoryName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomCategory_GetVolumeByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetVolumeByName_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_GetVolumeByName_Statics::NewProp_CategoryName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomCategory_GetVolumeByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomCategory" },
		{ "ModuleRelativePath", "Classes/AtomCategory.h" },
		{ "ToolTip", "Get volume by name." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomCategory_GetVolumeByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomCategory, nullptr, "GetVolumeByName", nullptr, nullptr, sizeof(AtomCategory_eventGetVolumeByName_Parms), Z_Construct_UFunction_UAtomCategory_GetVolumeByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_GetVolumeByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomCategory_GetVolumeByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_GetVolumeByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomCategory_GetVolumeByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomCategory_GetVolumeByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomCategory_IsPausedByName_Statics
	{
		struct AtomCategory_eventIsPausedByName_Parms
		{
			FString CategoryName;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CategoryName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAtomCategory_IsPausedByName_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((AtomCategory_eventIsPausedByName_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomCategory_IsPausedByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomCategory_eventIsPausedByName_Parms), &Z_Construct_UFunction_UAtomCategory_IsPausedByName_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomCategory_IsPausedByName_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventIsPausedByName_Parms, CategoryName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomCategory_IsPausedByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_IsPausedByName_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_IsPausedByName_Statics::NewProp_CategoryName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomCategory_IsPausedByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomCategory" },
		{ "ModuleRelativePath", "Classes/AtomCategory.h" },
		{ "ToolTip", "Is paused by name." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomCategory_IsPausedByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomCategory, nullptr, "IsPausedByName", nullptr, nullptr, sizeof(AtomCategory_eventIsPausedByName_Parms), Z_Construct_UFunction_UAtomCategory_IsPausedByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_IsPausedByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomCategory_IsPausedByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_IsPausedByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomCategory_IsPausedByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomCategory_IsPausedByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomCategory_PauseByName_Statics
	{
		struct AtomCategory_eventPauseByName_Parms
		{
			FString CategoryName;
			bool bPause;
		};
		static void NewProp_bPause_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bPause;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CategoryName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAtomCategory_PauseByName_Statics::NewProp_bPause_SetBit(void* Obj)
	{
		((AtomCategory_eventPauseByName_Parms*)Obj)->bPause = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomCategory_PauseByName_Statics::NewProp_bPause = { "bPause", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomCategory_eventPauseByName_Parms), &Z_Construct_UFunction_UAtomCategory_PauseByName_Statics::NewProp_bPause_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomCategory_PauseByName_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventPauseByName_Parms, CategoryName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomCategory_PauseByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_PauseByName_Statics::NewProp_bPause,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_PauseByName_Statics::NewProp_CategoryName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomCategory_PauseByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomCategory" },
		{ "ModuleRelativePath", "Classes/AtomCategory.h" },
		{ "ToolTip", "Pause by name." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomCategory_PauseByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomCategory, nullptr, "PauseByName", nullptr, nullptr, sizeof(AtomCategory_eventPauseByName_Parms), Z_Construct_UFunction_UAtomCategory_PauseByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_PauseByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomCategory_PauseByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_PauseByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomCategory_PauseByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomCategory_PauseByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById_Statics
	{
		struct AtomCategory_eventResetAllAisacControlById_Parms
		{
			int32 CategoryId;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CategoryId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((AtomCategory_eventResetAllAisacControlById_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomCategory_eventResetAllAisacControlById_Parms), &Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById_Statics::NewProp_CategoryId = { "CategoryId", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventResetAllAisacControlById_Parms, CategoryId), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById_Statics::NewProp_CategoryId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomCategory" },
		{ "ModuleRelativePath", "Classes/AtomCategory.h" },
		{ "ToolTip", "Reset all AISAC control by id." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomCategory, nullptr, "ResetAllAisacControlById", nullptr, nullptr, sizeof(AtomCategory_eventResetAllAisacControlById_Parms), Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName_Statics
	{
		struct AtomCategory_eventResetAllAisacControlByName_Parms
		{
			FString CategoryName;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CategoryName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((AtomCategory_eventResetAllAisacControlByName_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomCategory_eventResetAllAisacControlByName_Parms), &Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventResetAllAisacControlByName_Parms, CategoryName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName_Statics::NewProp_CategoryName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomCategory" },
		{ "ModuleRelativePath", "Classes/AtomCategory.h" },
		{ "ToolTip", "Reset all AISAC control by name." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomCategory, nullptr, "ResetAllAisacControlByName", nullptr, nullptr, sizeof(AtomCategory_eventResetAllAisacControlByName_Parms), Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomCategory_SetAisacControlByName_Statics
	{
		struct AtomCategory_eventSetAisacControlByName_Parms
		{
			FString CategoryName;
			FString AisacName;
			float Value;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AisacName;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CategoryName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomCategory_SetAisacControlByName_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventSetAisacControlByName_Parms, Value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomCategory_SetAisacControlByName_Statics::NewProp_AisacName = { "AisacName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventSetAisacControlByName_Parms, AisacName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomCategory_SetAisacControlByName_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventSetAisacControlByName_Parms, CategoryName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomCategory_SetAisacControlByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_SetAisacControlByName_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_SetAisacControlByName_Statics::NewProp_AisacName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_SetAisacControlByName_Statics::NewProp_CategoryName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomCategory_SetAisacControlByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomCategory" },
		{ "ModuleRelativePath", "Classes/AtomCategory.h" },
		{ "ToolTip", "Set AISAC control by name." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomCategory_SetAisacControlByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomCategory, nullptr, "SetAisacControlByName", nullptr, nullptr, sizeof(AtomCategory_eventSetAisacControlByName_Parms), Z_Construct_UFunction_UAtomCategory_SetAisacControlByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_SetAisacControlByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomCategory_SetAisacControlByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_SetAisacControlByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomCategory_SetAisacControlByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomCategory_SetAisacControlByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomCategory_SetVolumeByName_Statics
	{
		struct AtomCategory_eventSetVolumeByName_Parms
		{
			FString CategoryName;
			float Volume;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Volume;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CategoryName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomCategory_SetVolumeByName_Statics::NewProp_Volume = { "Volume", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventSetVolumeByName_Parms, Volume), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomCategory_SetVolumeByName_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventSetVolumeByName_Parms, CategoryName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomCategory_SetVolumeByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_SetVolumeByName_Statics::NewProp_Volume,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_SetVolumeByName_Statics::NewProp_CategoryName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomCategory_SetVolumeByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomCategory" },
		{ "ModuleRelativePath", "Classes/AtomCategory.h" },
		{ "ToolTip", "Set volume by name." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomCategory_SetVolumeByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomCategory, nullptr, "SetVolumeByName", nullptr, nullptr, sizeof(AtomCategory_eventSetVolumeByName_Parms), Z_Construct_UFunction_UAtomCategory_SetVolumeByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_SetVolumeByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomCategory_SetVolumeByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_SetVolumeByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomCategory_SetVolumeByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomCategory_SetVolumeByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomCategory_StopByName_Statics
	{
		struct AtomCategory_eventStopByName_Parms
		{
			FString CategoryName;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CategoryName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAtomCategory_StopByName_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomCategory_eventStopByName_Parms, CategoryName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomCategory_StopByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomCategory_StopByName_Statics::NewProp_CategoryName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomCategory_StopByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "AtomCategory" },
		{ "ModuleRelativePath", "Classes/AtomCategory.h" },
		{ "ToolTip", "Stop by name." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomCategory_StopByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomCategory, nullptr, "StopByName", nullptr, nullptr, sizeof(AtomCategory_eventStopByName_Parms), Z_Construct_UFunction_UAtomCategory_StopByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_StopByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomCategory_StopByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomCategory_StopByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomCategory_StopByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomCategory_StopByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAtomCategory_NoRegister()
	{
		return UAtomCategory::StaticClass();
	}
	struct Z_Construct_UClass_UAtomCategory_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAtomCategory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_CriWareRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAtomCategory_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoById, "GetAttachedAisacInfoById" }, // 4102354655
		{ &Z_Construct_UFunction_UAtomCategory_GetAttachedAisacInfoByName, "GetAttachedAisacInfoByName" }, // 2676852670
		{ &Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueById, "GetCurrentAisacControlValueById" }, // 422620732
		{ &Z_Construct_UFunction_UAtomCategory_GetCurrentAisacControlValueByName, "GetCurrentAisacControlValueByName" }, // 1889113303
		{ &Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsById, "GetNumAttachedAisacsById" }, // 1021984007
		{ &Z_Construct_UFunction_UAtomCategory_GetNumAttachedAisacsByName, "GetNumAttachedAisacsByName" }, // 3615600987
		{ &Z_Construct_UFunction_UAtomCategory_GetVolumeByName, "GetVolumeByName" }, // 4211348006
		{ &Z_Construct_UFunction_UAtomCategory_IsPausedByName, "IsPausedByName" }, // 3256334843
		{ &Z_Construct_UFunction_UAtomCategory_PauseByName, "PauseByName" }, // 1101581222
		{ &Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlById, "ResetAllAisacControlById" }, // 1423412833
		{ &Z_Construct_UFunction_UAtomCategory_ResetAllAisacControlByName, "ResetAllAisacControlByName" }, // 206304874
		{ &Z_Construct_UFunction_UAtomCategory_SetAisacControlByName, "SetAisacControlByName" }, // 885229271
		{ &Z_Construct_UFunction_UAtomCategory_SetVolumeByName, "SetVolumeByName" }, // 465297497
		{ &Z_Construct_UFunction_UAtomCategory_StopByName, "StopByName" }, // 967552568
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAtomCategory_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AtomCategory.h" },
		{ "ModuleRelativePath", "Classes/AtomCategory.h" },
		{ "ToolTip", "AtomCategory class." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAtomCategory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAtomCategory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAtomCategory_Statics::ClassParams = {
		&UAtomCategory::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UAtomCategory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UAtomCategory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAtomCategory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAtomCategory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAtomCategory, 3960380423);
	template<> CRIWARERUNTIME_API UClass* StaticClass<UAtomCategory>()
	{
		return UAtomCategory::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAtomCategory(Z_Construct_UClass_UAtomCategory, &UAtomCategory::StaticClass, TEXT("/Script/CriWareRuntime"), TEXT("UAtomCategory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAtomCategory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
