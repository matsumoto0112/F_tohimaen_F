// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CriWareRuntime/Classes/SoundAtomConfig.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSoundAtomConfig() {}
// Cross Module References
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_USoundAtomConfig_NoRegister();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_USoundAtomConfig();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_CriWareRuntime();
	ENGINE_API UClass* Z_Construct_UClass_UAssetImportData_NoRegister();
// End Cross Module References
	void USoundAtomConfig::StaticRegisterNativesUSoundAtomConfig()
	{
	}
	UClass* Z_Construct_UClass_USoundAtomConfig_NoRegister()
	{
		return USoundAtomConfig::StaticClass();
	}
	struct Z_Construct_UClass_USoundAtomConfig_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AcfFilePath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AcfFilePath;
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
	UObject* (*const Z_Construct_UClass_USoundAtomConfig_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_CriWareRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomConfig_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "object" },
		{ "IncludePath", "SoundAtomConfig.h" },
		{ "ModuleRelativePath", "Classes/SoundAtomConfig.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "SoundAtomConfig class." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomConfig_Statics::NewProp_AcfFilePath_MetaData[] = {
		{ "Comment", "/** (DEPRECATED) ACF file path is now stored in AssetImportData. */" },
		{ "ModuleRelativePath", "Classes/SoundAtomConfig.h" },
		{ "ToolTip", "(DEPRECATED) ACF file path is now stored in AssetImportData." },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USoundAtomConfig_Statics::NewProp_AcfFilePath = { "AcfFilePath", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomConfig, AcfFilePath), METADATA_PARAMS(Z_Construct_UClass_USoundAtomConfig_Statics::NewProp_AcfFilePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomConfig_Statics::NewProp_AcfFilePath_MetaData)) };
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoundAtomConfig_Statics::NewProp_AssetImportData_MetaData[] = {
		{ "Category", "Reimport" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Classes/SoundAtomConfig.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USoundAtomConfig_Statics::NewProp_AssetImportData = { "AssetImportData", nullptr, (EPropertyFlags)0x0012000800080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USoundAtomConfig, AssetImportData), Z_Construct_UClass_UAssetImportData_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USoundAtomConfig_Statics::NewProp_AssetImportData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomConfig_Statics::NewProp_AssetImportData_MetaData)) };
#endif // WITH_EDITORONLY_DATA
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USoundAtomConfig_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomConfig_Statics::NewProp_AcfFilePath,
#if WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USoundAtomConfig_Statics::NewProp_AssetImportData,
#endif // WITH_EDITORONLY_DATA
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USoundAtomConfig_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USoundAtomConfig>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USoundAtomConfig_Statics::ClassParams = {
		&USoundAtomConfig::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USoundAtomConfig_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomConfig_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USoundAtomConfig_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USoundAtomConfig_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USoundAtomConfig()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USoundAtomConfig_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USoundAtomConfig, 307816074);
	template<> CRIWARERUNTIME_API UClass* StaticClass<USoundAtomConfig>()
	{
		return USoundAtomConfig::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USoundAtomConfig(Z_Construct_UClass_USoundAtomConfig, &USoundAtomConfig::StaticClass, TEXT("/Script/CriWareRuntime"), TEXT("USoundAtomConfig"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USoundAtomConfig);
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(USoundAtomConfig)
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
