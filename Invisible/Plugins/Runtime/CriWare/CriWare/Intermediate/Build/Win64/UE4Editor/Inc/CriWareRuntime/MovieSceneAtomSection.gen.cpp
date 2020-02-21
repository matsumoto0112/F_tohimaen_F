// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CriWareRuntime/Public/Sections/MovieSceneAtomSection.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMovieSceneAtomSection() {}
// Cross Module References
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_UMovieSceneAtomSection_NoRegister();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_UMovieSceneAtomSection();
	MOVIESCENE_API UClass* Z_Construct_UClass_UMovieSceneSection();
	UPackage* Z_Construct_UPackage__Script_CriWareRuntime();
	MOVIESCENE_API UScriptStruct* Z_Construct_UScriptStruct_FMovieSceneFloatChannel();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_USoundAtomCue_NoRegister();
// End Cross Module References
	void UMovieSceneAtomSection::StaticRegisterNativesUMovieSceneAtomSection()
	{
	}
	UClass* Z_Construct_UClass_UMovieSceneAtomSection_NoRegister()
	{
		return UMovieSceneAtomSection::StaticClass();
	}
	struct Z_Construct_UClass_UMovieSceneAtomSection_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bSuppressSubtitles_MetaData[];
#endif
		static void NewProp_bSuppressSubtitles_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSuppressSubtitles;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PitchMultiplier_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PitchMultiplier;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SoundVolume_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SoundVolume;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StartOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StartOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Sound_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Sound;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMovieSceneAtomSection_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UMovieSceneSection,
		(UObject* (*)())Z_Construct_UPackage__Script_CriWareRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovieSceneAtomSection_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Atom section, for use in the master audio, or by attached audio objects\n */" },
		{ "IncludePath", "Sections/MovieSceneAtomSection.h" },
		{ "ModuleRelativePath", "Public/Sections/MovieSceneAtomSection.h" },
		{ "ToolTip", "Atom section, for use in the master audio, or by attached audio objects" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_bSuppressSubtitles_MetaData[] = {
		{ "Category", "Atom" },
		{ "ModuleRelativePath", "Public/Sections/MovieSceneAtomSection.h" },
	};
#endif
	void Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_bSuppressSubtitles_SetBit(void* Obj)
	{
		((UMovieSceneAtomSection*)Obj)->bSuppressSubtitles = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_bSuppressSubtitles = { "bSuppressSubtitles", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UMovieSceneAtomSection), &Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_bSuppressSubtitles_SetBit, METADATA_PARAMS(Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_bSuppressSubtitles_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_bSuppressSubtitles_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_PitchMultiplier_MetaData[] = {
		{ "Comment", "/** The pitch multiplier the sound will be played with. */" },
		{ "ModuleRelativePath", "Public/Sections/MovieSceneAtomSection.h" },
		{ "ToolTip", "The pitch multiplier the sound will be played with." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_PitchMultiplier = { "PitchMultiplier", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMovieSceneAtomSection, PitchMultiplier), Z_Construct_UScriptStruct_FMovieSceneFloatChannel, METADATA_PARAMS(Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_PitchMultiplier_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_PitchMultiplier_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_SoundVolume_MetaData[] = {
		{ "Comment", "/** The volume the sound will be played with. */" },
		{ "ModuleRelativePath", "Public/Sections/MovieSceneAtomSection.h" },
		{ "ToolTip", "The volume the sound will be played with." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_SoundVolume = { "SoundVolume", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMovieSceneAtomSection, SoundVolume), Z_Construct_UScriptStruct_FMovieSceneFloatChannel, METADATA_PARAMS(Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_SoundVolume_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_SoundVolume_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_StartOffset_MetaData[] = {
		{ "Category", "Atom" },
		{ "Comment", "/** The offset into the beginning of the audio clip */" },
		{ "ModuleRelativePath", "Public/Sections/MovieSceneAtomSection.h" },
		{ "ToolTip", "The offset into the beginning of the audio clip" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_StartOffset = { "StartOffset", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMovieSceneAtomSection, StartOffset), METADATA_PARAMS(Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_StartOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_StartOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_Sound_MetaData[] = {
		{ "Category", "Atom" },
		{ "Comment", "/** The sound cue or wave that this section plays */" },
		{ "ModuleRelativePath", "Public/Sections/MovieSceneAtomSection.h" },
		{ "ToolTip", "The sound cue or wave that this section plays" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMovieSceneAtomSection, Sound), Z_Construct_UClass_USoundAtomCue_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_Sound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_Sound_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMovieSceneAtomSection_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_bSuppressSubtitles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_PitchMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_SoundVolume,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_StartOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovieSceneAtomSection_Statics::NewProp_Sound,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMovieSceneAtomSection_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMovieSceneAtomSection>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMovieSceneAtomSection_Statics::ClassParams = {
		&UMovieSceneAtomSection::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMovieSceneAtomSection_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMovieSceneAtomSection_Statics::PropPointers),
		0,
		0x002800A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMovieSceneAtomSection_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMovieSceneAtomSection_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMovieSceneAtomSection()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMovieSceneAtomSection_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMovieSceneAtomSection, 4147014772);
	template<> CRIWARERUNTIME_API UClass* StaticClass<UMovieSceneAtomSection>()
	{
		return UMovieSceneAtomSection::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMovieSceneAtomSection(Z_Construct_UClass_UMovieSceneAtomSection, &UMovieSceneAtomSection::StaticClass, TEXT("/Script/CriWareRuntime"), TEXT("UMovieSceneAtomSection"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMovieSceneAtomSection);
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(UMovieSceneAtomSection)
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
