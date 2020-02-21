// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CriWareRuntime/Private/Evaluation/MovieSceneAtomTemplate.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMovieSceneAtomTemplate() {}
// Cross Module References
	CRIWARERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate();
	UPackage* Z_Construct_UPackage__Script_CriWareRuntime();
	MOVIESCENE_API UScriptStruct* Z_Construct_UScriptStruct_FMovieSceneEvalTemplate();
	CRIWARERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData();
	MOVIESCENE_API UScriptStruct* Z_Construct_UScriptStruct_FMovieSceneFloatChannel();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_USoundAtomCue_NoRegister();
// End Cross Module References
class UScriptStruct* FMovieSceneAtomSectionTemplate::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern CRIWARERUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate, Z_Construct_UPackage__Script_CriWareRuntime(), TEXT("MovieSceneAtomSectionTemplate"), sizeof(FMovieSceneAtomSectionTemplate), Get_Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Hash());
	}
	return Singleton;
}
template<> CRIWARERUNTIME_API UScriptStruct* StaticStruct<FMovieSceneAtomSectionTemplate>()
{
	return FMovieSceneAtomSectionTemplate::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FMovieSceneAtomSectionTemplate(FMovieSceneAtomSectionTemplate::StaticStruct, TEXT("/Script/CriWareRuntime"), TEXT("MovieSceneAtomSectionTemplate"), false, nullptr, nullptr);
static struct FScriptStruct_CriWareRuntime_StaticRegisterNativesFMovieSceneAtomSectionTemplate
{
	FScriptStruct_CriWareRuntime_StaticRegisterNativesFMovieSceneAtomSectionTemplate()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("MovieSceneAtomSectionTemplate")),new UScriptStruct::TCppStructOps<FMovieSceneAtomSectionTemplate>);
	}
} ScriptStruct_CriWareRuntime_StaticRegisterNativesFMovieSceneAtomSectionTemplate;
	struct Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AtomData_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AtomData;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Evaluation/MovieSceneAtomTemplate.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMovieSceneAtomSectionTemplate>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Statics::NewProp_AtomData_MetaData[] = {
		{ "ModuleRelativePath", "Private/Evaluation/MovieSceneAtomTemplate.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Statics::NewProp_AtomData = { "AtomData", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMovieSceneAtomSectionTemplate, AtomData), Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData, METADATA_PARAMS(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Statics::NewProp_AtomData_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Statics::NewProp_AtomData_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Statics::NewProp_AtomData,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_CriWareRuntime,
		Z_Construct_UScriptStruct_FMovieSceneEvalTemplate,
		&NewStructOps,
		"MovieSceneAtomSectionTemplate",
		sizeof(FMovieSceneAtomSectionTemplate),
		alignof(FMovieSceneAtomSectionTemplate),
		Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000005),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_CriWareRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("MovieSceneAtomSectionTemplate"), sizeof(FMovieSceneAtomSectionTemplate), Get_Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplate_Hash() { return 401743976U; }
class UScriptStruct* FMovieSceneAtomSectionTemplateData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern CRIWARERUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData, Z_Construct_UPackage__Script_CriWareRuntime(), TEXT("MovieSceneAtomSectionTemplateData"), sizeof(FMovieSceneAtomSectionTemplateData), Get_Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Hash());
	}
	return Singleton;
}
template<> CRIWARERUNTIME_API UScriptStruct* StaticStruct<FMovieSceneAtomSectionTemplateData>()
{
	return FMovieSceneAtomSectionTemplateData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FMovieSceneAtomSectionTemplateData(FMovieSceneAtomSectionTemplateData::StaticStruct, TEXT("/Script/CriWareRuntime"), TEXT("MovieSceneAtomSectionTemplateData"), false, nullptr, nullptr);
static struct FScriptStruct_CriWareRuntime_StaticRegisterNativesFMovieSceneAtomSectionTemplateData
{
	FScriptStruct_CriWareRuntime_StaticRegisterNativesFMovieSceneAtomSectionTemplateData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("MovieSceneAtomSectionTemplateData")),new UScriptStruct::TCppStructOps<FMovieSceneAtomSectionTemplateData>);
	}
} ScriptStruct_CriWareRuntime_StaticRegisterNativesFMovieSceneAtomSectionTemplateData;
	struct Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RowIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_RowIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AtomVolumeCurve_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AtomVolumeCurve;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AtomPitchMultiplierCurve_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AtomPitchMultiplierCurve;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SectionStartTimeSeconds_MetaData[];
#endif
		static const UE4CodeGen_Private::FDoublePropertyParams NewProp_SectionStartTimeSeconds;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AtomStartOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AtomStartOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Sound_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Sound;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/***************************************************************************\n *      \xe3\x82\xaf\xe3\x83\xa9\xe3\x82\xb9\xe5\xae\xa3\xe8\xa8\x80\n *      Prototype Classes\n ***************************************************************************/" },
		{ "ModuleRelativePath", "Private/Evaluation/MovieSceneAtomTemplate.h" },
		{ "ToolTip", "\xe3\x82\xaf\xe3\x83\xa9\xe3\x82\xb9\xe5\xae\xa3\xe8\xa8\x80\nPrototype Classes" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMovieSceneAtomSectionTemplateData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_RowIndex_MetaData[] = {
		{ "Comment", "/** The row index of the section */" },
		{ "ModuleRelativePath", "Private/Evaluation/MovieSceneAtomTemplate.h" },
		{ "ToolTip", "The row index of the section" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_RowIndex = { "RowIndex", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMovieSceneAtomSectionTemplateData, RowIndex), METADATA_PARAMS(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_RowIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_RowIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_AtomVolumeCurve_MetaData[] = {
		{ "Comment", "/** The volume the sound will be played with. */" },
		{ "ModuleRelativePath", "Private/Evaluation/MovieSceneAtomTemplate.h" },
		{ "ToolTip", "The volume the sound will be played with." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_AtomVolumeCurve = { "AtomVolumeCurve", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMovieSceneAtomSectionTemplateData, AtomVolumeCurve), Z_Construct_UScriptStruct_FMovieSceneFloatChannel, METADATA_PARAMS(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_AtomVolumeCurve_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_AtomVolumeCurve_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_AtomPitchMultiplierCurve_MetaData[] = {
		{ "Comment", "/** The amount which this audio is time dilated by */" },
		{ "ModuleRelativePath", "Private/Evaluation/MovieSceneAtomTemplate.h" },
		{ "ToolTip", "The amount which this audio is time dilated by" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_AtomPitchMultiplierCurve = { "AtomPitchMultiplierCurve", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMovieSceneAtomSectionTemplateData, AtomPitchMultiplierCurve), Z_Construct_UScriptStruct_FMovieSceneFloatChannel, METADATA_PARAMS(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_AtomPitchMultiplierCurve_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_AtomPitchMultiplierCurve_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_SectionStartTimeSeconds_MetaData[] = {
		{ "Comment", "/** The frame number at which the audio starts playing */" },
		{ "ModuleRelativePath", "Private/Evaluation/MovieSceneAtomTemplate.h" },
		{ "ToolTip", "The frame number at which the audio starts playing" },
	};
#endif
	const UE4CodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_SectionStartTimeSeconds = { "SectionStartTimeSeconds", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMovieSceneAtomSectionTemplateData, SectionStartTimeSeconds), METADATA_PARAMS(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_SectionStartTimeSeconds_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_SectionStartTimeSeconds_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_AtomStartOffset_MetaData[] = {
		{ "Comment", "/** The offset into the beginning of the audio clip */" },
		{ "ModuleRelativePath", "Private/Evaluation/MovieSceneAtomTemplate.h" },
		{ "ToolTip", "The offset into the beginning of the audio clip" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_AtomStartOffset = { "AtomStartOffset", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMovieSceneAtomSectionTemplateData, AtomStartOffset), METADATA_PARAMS(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_AtomStartOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_AtomStartOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_Sound_MetaData[] = {
		{ "Comment", "/** The sound cue or wave that this template plays. Not to be dereferenced on a background thread */" },
		{ "ModuleRelativePath", "Private/Evaluation/MovieSceneAtomTemplate.h" },
		{ "ToolTip", "The sound cue or wave that this template plays. Not to be dereferenced on a background thread" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMovieSceneAtomSectionTemplateData, Sound), Z_Construct_UClass_USoundAtomCue_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_Sound_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_Sound_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_RowIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_AtomVolumeCurve,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_AtomPitchMultiplierCurve,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_SectionStartTimeSeconds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_AtomStartOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::NewProp_Sound,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_CriWareRuntime,
		nullptr,
		&NewStructOps,
		"MovieSceneAtomSectionTemplateData",
		sizeof(FMovieSceneAtomSectionTemplateData),
		alignof(FMovieSceneAtomSectionTemplateData),
		Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_CriWareRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("MovieSceneAtomSectionTemplateData"), sizeof(FMovieSceneAtomSectionTemplateData), Get_Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FMovieSceneAtomSectionTemplateData_Hash() { return 1718525351U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
