// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CriWareEditor/Classes/CriWarePreviewer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCriWarePreviewer() {}
// Cross Module References
	CRIWAREEDITOR_API UClass* Z_Construct_UClass_UCriWarePreviewer_NoRegister();
	CRIWAREEDITOR_API UClass* Z_Construct_UClass_UCriWarePreviewer();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_CriWareEditor();
// End Cross Module References
	void UCriWarePreviewer::StaticRegisterNativesUCriWarePreviewer()
	{
	}
	UClass* Z_Construct_UClass_UCriWarePreviewer_NoRegister()
	{
		return UCriWarePreviewer::StaticClass();
	}
	struct Z_Construct_UClass_UCriWarePreviewer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCriWarePreviewer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_CriWareEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCriWarePreviewer_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/***************************************************************************\n *      \xe3\x82\xaf\xe3\x83\xa9\xe3\x82\xb9\xe5\xae\xa3\xe8\xa8\x80\n *      Prototype Classes\n ***************************************************************************/" },
		{ "IncludePath", "CriWarePreviewer.h" },
		{ "ModuleRelativePath", "Classes/CriWarePreviewer.h" },
		{ "ToolTip", "\xe3\x82\xaf\xe3\x83\xa9\xe3\x82\xb9\xe5\xae\xa3\xe8\xa8\x80\nPrototype Classes" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCriWarePreviewer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCriWarePreviewer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCriWarePreviewer_Statics::ClassParams = {
		&UCriWarePreviewer::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UCriWarePreviewer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCriWarePreviewer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCriWarePreviewer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCriWarePreviewer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCriWarePreviewer, 2529918320);
	template<> CRIWAREEDITOR_API UClass* StaticClass<UCriWarePreviewer>()
	{
		return UCriWarePreviewer::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCriWarePreviewer(Z_Construct_UClass_UCriWarePreviewer, &UCriWarePreviewer::StaticClass, TEXT("/Script/CriWareEditor"), TEXT("UCriWarePreviewer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCriWarePreviewer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
