// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CriWareRuntime/Public/Tracks/MovieSceneAtomTrack.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMovieSceneAtomTrack() {}
// Cross Module References
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_UMovieSceneAtomTrack_NoRegister();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_UMovieSceneAtomTrack();
	MOVIESCENE_API UClass* Z_Construct_UClass_UMovieSceneNameableTrack();
	UPackage* Z_Construct_UPackage__Script_CriWareRuntime();
	MOVIESCENE_API UClass* Z_Construct_UClass_UMovieSceneSection_NoRegister();
// End Cross Module References
	void UMovieSceneAtomTrack::StaticRegisterNativesUMovieSceneAtomTrack()
	{
	}
	UClass* Z_Construct_UClass_UMovieSceneAtomTrack_NoRegister()
	{
		return UMovieSceneAtomTrack::StaticClass();
	}
	struct Z_Construct_UClass_UMovieSceneAtomTrack_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RowHeight_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_RowHeight;
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AtomSections_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_AtomSections;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AtomSections_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMovieSceneAtomTrack_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UMovieSceneNameableTrack,
		(UObject* (*)())Z_Construct_UPackage__Script_CriWareRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovieSceneAtomTrack_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Handles manipulation of audio.\n */" },
		{ "IncludePath", "Tracks/MovieSceneAtomTrack.h" },
		{ "ModuleRelativePath", "Public/Tracks/MovieSceneAtomTrack.h" },
		{ "ToolTip", "Handles manipulation of audio." },
	};
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovieSceneAtomTrack_Statics::NewProp_RowHeight_MetaData[] = {
		{ "Comment", "/** The height for each row of this track */" },
		{ "ModuleRelativePath", "Public/Tracks/MovieSceneAtomTrack.h" },
		{ "ToolTip", "The height for each row of this track" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMovieSceneAtomTrack_Statics::NewProp_RowHeight = { "RowHeight", nullptr, (EPropertyFlags)0x0040000800000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMovieSceneAtomTrack, RowHeight), METADATA_PARAMS(Z_Construct_UClass_UMovieSceneAtomTrack_Statics::NewProp_RowHeight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMovieSceneAtomTrack_Statics::NewProp_RowHeight_MetaData)) };
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovieSceneAtomTrack_Statics::NewProp_AtomSections_MetaData[] = {
		{ "Comment", "/** List of all master audio sections */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Tracks/MovieSceneAtomTrack.h" },
		{ "ToolTip", "List of all master audio sections" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UMovieSceneAtomTrack_Statics::NewProp_AtomSections = { "AtomSections", nullptr, (EPropertyFlags)0x0040008000000008, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMovieSceneAtomTrack, AtomSections), METADATA_PARAMS(Z_Construct_UClass_UMovieSceneAtomTrack_Statics::NewProp_AtomSections_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMovieSceneAtomTrack_Statics::NewProp_AtomSections_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMovieSceneAtomTrack_Statics::NewProp_AtomSections_Inner = { "AtomSections", nullptr, (EPropertyFlags)0x0000000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UMovieSceneSection_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMovieSceneAtomTrack_Statics::PropPointers[] = {
#if WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovieSceneAtomTrack_Statics::NewProp_RowHeight,
#endif // WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovieSceneAtomTrack_Statics::NewProp_AtomSections,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovieSceneAtomTrack_Statics::NewProp_AtomSections_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMovieSceneAtomTrack_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMovieSceneAtomTrack>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMovieSceneAtomTrack_Statics::ClassParams = {
		&UMovieSceneAtomTrack::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMovieSceneAtomTrack_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMovieSceneAtomTrack_Statics::PropPointers),
		0,
		0x00A800A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMovieSceneAtomTrack_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMovieSceneAtomTrack_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMovieSceneAtomTrack()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMovieSceneAtomTrack_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMovieSceneAtomTrack, 2368901013);
	template<> CRIWARERUNTIME_API UClass* StaticClass<UMovieSceneAtomTrack>()
	{
		return UMovieSceneAtomTrack::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMovieSceneAtomTrack(Z_Construct_UClass_UMovieSceneAtomTrack, &UMovieSceneAtomTrack::StaticClass, TEXT("/Script/CriWareRuntime"), TEXT("UMovieSceneAtomTrack"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMovieSceneAtomTrack);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
