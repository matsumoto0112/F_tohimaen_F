// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CriWareRuntime/Private/AtomParameter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAtomParameter() {}
// Cross Module References
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_AAtomParameter_NoRegister();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_AAtomParameter();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_CriWareRuntime();
// End Cross Module References
	void AAtomParameter::StaticRegisterNativesAAtomParameter()
	{
	}
	UClass* Z_Construct_UClass_AAtomParameter_NoRegister()
	{
		return AAtomParameter::StaticClass();
	}
	struct Z_Construct_UClass_AAtomParameter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAtomParameter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_CriWareRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAtomParameter_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/***************************************************************************\n *      \xe3\x82\xaf\xe3\x83\xa9\xe3\x82\xb9\xe5\xae\xa3\xe8\xa8\x80\n *      Prototype Classes\n ***************************************************************************/" },
		{ "IncludePath", "AtomParameter.h" },
		{ "ModuleRelativePath", "Private/AtomParameter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "\xe3\x82\xaf\xe3\x83\xa9\xe3\x82\xb9\xe5\xae\xa3\xe8\xa8\x80\nPrototype Classes" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAtomParameter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAtomParameter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAtomParameter_Statics::ClassParams = {
		&AAtomParameter::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008800A4u,
		METADATA_PARAMS(Z_Construct_UClass_AAtomParameter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAtomParameter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAtomParameter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAtomParameter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAtomParameter, 2410714853);
	template<> CRIWARERUNTIME_API UClass* StaticClass<AAtomParameter>()
	{
		return AAtomParameter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAtomParameter(Z_Construct_UClass_AAtomParameter, &AAtomParameter::StaticClass, TEXT("/Script/CriWareRuntime"), TEXT("AAtomParameter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAtomParameter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
