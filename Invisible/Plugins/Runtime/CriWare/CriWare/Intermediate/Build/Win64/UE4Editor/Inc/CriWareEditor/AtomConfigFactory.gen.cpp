// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CriWareEditor/Classes/AtomConfigFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAtomConfigFactory() {}
// Cross Module References
	CRIWAREEDITOR_API UClass* Z_Construct_UClass_UAtomConfigFactory_NoRegister();
	CRIWAREEDITOR_API UClass* Z_Construct_UClass_UAtomConfigFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_CriWareEditor();
// End Cross Module References
	void UAtomConfigFactory::StaticRegisterNativesUAtomConfigFactory()
	{
	}
	UClass* Z_Construct_UClass_UAtomConfigFactory_NoRegister()
	{
		return UAtomConfigFactory::StaticClass();
	}
	struct Z_Construct_UClass_UAtomConfigFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAtomConfigFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_CriWareEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAtomConfigFactory_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/***************************************************************************\n *      \xe3\x82\xaf\xe3\x83\xa9\xe3\x82\xb9\xe5\xae\xa3\xe8\xa8\x80\n *      Prototype Classes\n ***************************************************************************/" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "AtomConfigFactory.h" },
		{ "ModuleRelativePath", "Classes/AtomConfigFactory.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "\xe3\x82\xaf\xe3\x83\xa9\xe3\x82\xb9\xe5\xae\xa3\xe8\xa8\x80\nPrototype Classes" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAtomConfigFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAtomConfigFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAtomConfigFactory_Statics::ClassParams = {
		&UAtomConfigFactory::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UAtomConfigFactory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UAtomConfigFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAtomConfigFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAtomConfigFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAtomConfigFactory, 1758436604);
	template<> CRIWAREEDITOR_API UClass* StaticClass<UAtomConfigFactory>()
	{
		return UAtomConfigFactory::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAtomConfigFactory(Z_Construct_UClass_UAtomConfigFactory, &UAtomConfigFactory::StaticClass, TEXT("/Script/CriWareEditor"), TEXT("UAtomConfigFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAtomConfigFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
