// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCriWareRuntime_init() {}
	CRIWARERUNTIME_API UFunction* Z_Construct_UDelegateFunction_UAtomComponent_OnAudioFinished__DelegateSignature();
	CRIWARERUNTIME_API UFunction* Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindCompleted__DelegateSignature();
	CRIWARERUNTIME_API UFunction* Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindError__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_CriWareRuntime()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_UAtomComponent_OnAudioFinished__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindCompleted__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindError__DelegateSignature,
			};
			static const UE4CodeGen_Private::FPackageParams PackageParams = {
				"/Script/CriWareRuntime",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xC2DBE0BC,
				0x54A9DE91,
				METADATA_PARAMS(nullptr, 0)
			};
			UE4CodeGen_Private::ConstructUPackage(ReturnPackage, PackageParams);
		}
		return ReturnPackage;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
