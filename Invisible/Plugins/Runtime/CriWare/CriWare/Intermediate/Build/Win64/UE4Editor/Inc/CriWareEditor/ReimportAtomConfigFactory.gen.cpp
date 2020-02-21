// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CriWareEditor/Classes/ReimportAtomConfigFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReimportAtomConfigFactory() {}
// Cross Module References
	CRIWAREEDITOR_API UClass* Z_Construct_UClass_UReimportAtomConfigFactory_NoRegister();
	CRIWAREEDITOR_API UClass* Z_Construct_UClass_UReimportAtomConfigFactory();
	CRIWAREEDITOR_API UClass* Z_Construct_UClass_UAtomConfigFactory();
	UPackage* Z_Construct_UPackage__Script_CriWareEditor();
// End Cross Module References
	void UReimportAtomConfigFactory::StaticRegisterNativesUReimportAtomConfigFactory()
	{
	}
	UClass* Z_Construct_UClass_UReimportAtomConfigFactory_NoRegister()
	{
		return UReimportAtomConfigFactory::StaticClass();
	}
	struct Z_Construct_UClass_UReimportAtomConfigFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UReimportAtomConfigFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAtomConfigFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_CriWareEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReimportAtomConfigFactory_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/***************************************************************************\n *      \xe3\x82\xaf\xe3\x83\xa9\xe3\x82\xb9\xe5\xae\xa3\xe8\xa8\x80\n *      Prototype Classes\n ***************************************************************************/" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "ReimportAtomConfigFactory.h" },
		{ "ModuleRelativePath", "Classes/ReimportAtomConfigFactory.h" },
		{ "ToolTip", "\xe3\x82\xaf\xe3\x83\xa9\xe3\x82\xb9\xe5\xae\xa3\xe8\xa8\x80\nPrototype Classes" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UReimportAtomConfigFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UReimportAtomConfigFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UReimportAtomConfigFactory_Statics::ClassParams = {
		&UReimportAtomConfigFactory::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UReimportAtomConfigFactory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UReimportAtomConfigFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UReimportAtomConfigFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UReimportAtomConfigFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UReimportAtomConfigFactory, 3491930823);
	template<> CRIWAREEDITOR_API UClass* StaticClass<UReimportAtomConfigFactory>()
	{
		return UReimportAtomConfigFactory::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UReimportAtomConfigFactory(Z_Construct_UClass_UReimportAtomConfigFactory, &UReimportAtomConfigFactory::StaticClass, TEXT("/Script/CriWareEditor"), TEXT("UReimportAtomConfigFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UReimportAtomConfigFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
