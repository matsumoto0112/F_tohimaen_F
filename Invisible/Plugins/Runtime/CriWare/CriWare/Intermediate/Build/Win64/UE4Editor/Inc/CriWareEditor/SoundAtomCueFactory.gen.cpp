// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CriWareEditor/Classes/SoundAtomCueFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSoundAtomCueFactory() {}
// Cross Module References
	CRIWAREEDITOR_API UClass* Z_Construct_UClass_USoundAtomCueFactory_NoRegister();
	CRIWAREEDITOR_API UClass* Z_Construct_UClass_USoundAtomCueFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_CriWareEditor();
// End Cross Module References
	void USoundAtomCueFactory::StaticRegisterNativesUSoundAtomCueFactory()
	{
	}
	UClass* Z_Construct_UClass_USoundAtomCueFactory_NoRegister()
	{
		return USoundAtomCueFactory::StaticClass();
	}
	struct Z_Construct_UClass_USoundAtomCueFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USoundAtomCueFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_CriWareEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomCueFactory_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/***************************************************************************\n*      \xe3\x82\xaf\xe3\x83\xa9\xe3\x82\xb9\xe5\xae\xa3\xe8\xa8\x80\n*      Prototype Classes\n***************************************************************************/" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "SoundAtomCueFactory.h" },
		{ "ModuleRelativePath", "Classes/SoundAtomCueFactory.h" },
		{ "ToolTip", "\xe3\x82\xaf\xe3\x83\xa9\xe3\x82\xb9\xe5\xae\xa3\xe8\xa8\x80\nPrototype Classes" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USoundAtomCueFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USoundAtomCueFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USoundAtomCueFactory_Statics::ClassParams = {
		&USoundAtomCueFactory::StaticClass,
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
		0x000800A0u,
		METADATA_PARAMS(Z_Construct_UClass_USoundAtomCueFactory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomCueFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USoundAtomCueFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USoundAtomCueFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USoundAtomCueFactory, 3453110657);
	template<> CRIWAREEDITOR_API UClass* StaticClass<USoundAtomCueFactory>()
	{
		return USoundAtomCueFactory::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USoundAtomCueFactory(Z_Construct_UClass_USoundAtomCueFactory, &USoundAtomCueFactory::StaticClass, TEXT("/Script/CriWareEditor"), TEXT("USoundAtomCueFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USoundAtomCueFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
