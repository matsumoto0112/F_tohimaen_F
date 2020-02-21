// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CriWareRuntime/Classes/AtomStatics.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAtomStatics() {}
// Cross Module References
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_UAtomStatics_NoRegister();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_UAtomStatics();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_CriWareRuntime();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_UAtomComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomStatics_LoadAtomConfig();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_USoundAtomConfig_NoRegister();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomStatics_PauseAudioOutput();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation();
	ENGINE_API UClass* Z_Construct_UClass_USoundConcurrency_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundAttenuation_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_USoundAtomCue_NoRegister();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomStatics_PlaySoundAttached();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomStatics_SpawnSound2D();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_EAttachLocation();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UAtomStatics_StopAllSounds();
// End Cross Module References
	void UAtomStatics::StaticRegisterNativesUAtomStatics()
	{
		UClass* Class = UAtomStatics::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateRootedAtomComponent", &UAtomStatics::execCreateRootedAtomComponent },
			{ "LoadAtomConfig", &UAtomStatics::execLoadAtomConfig },
			{ "PauseAudioOutput", &UAtomStatics::execPauseAudioOutput },
			{ "PlaySoundAtLocation", &UAtomStatics::execPlaySoundAtLocation },
			{ "PlaySoundAttached", &UAtomStatics::execPlaySoundAttached },
			{ "PlaySoundForAnimNotify", &UAtomStatics::execPlaySoundForAnimNotify },
			{ "SpawnSound2D", &UAtomStatics::execSpawnSound2D },
			{ "SpawnSoundAtLocation", &UAtomStatics::execSpawnSoundAtLocation },
			{ "SpawnSoundAttached", &UAtomStatics::execSpawnSoundAttached },
			{ "StopAllSounds", &UAtomStatics::execStopAllSounds },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics
	{
		struct AtomStatics_eventCreateRootedAtomComponent_Parms
		{
			const UObject* WorldContextObject;
			bool bAutoDestroy;
			UAtomComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static void NewProp_bAutoDestroy_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAutoDestroy;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventCreateRootedAtomComponent_Parms, ReturnValue), Z_Construct_UClass_UAtomComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::NewProp_ReturnValue_MetaData)) };
	void Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::NewProp_bAutoDestroy_SetBit(void* Obj)
	{
		((AtomStatics_eventCreateRootedAtomComponent_Parms*)Obj)->bAutoDestroy = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::NewProp_bAutoDestroy = { "bAutoDestroy", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomStatics_eventCreateRootedAtomComponent_Parms), &Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::NewProp_bAutoDestroy_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventCreateRootedAtomComponent_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::NewProp_WorldContextObject_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::NewProp_WorldContextObject_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::NewProp_bAutoDestroy,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "2" },
		{ "Category", "Atom" },
		{ "CPP_Default_bAutoDestroy", "true" },
		{ "Keywords", "Create" },
		{ "ModuleRelativePath", "Classes/AtomStatics.h" },
		{ "ToolTip", "Create rooted atom component." },
		{ "UnsafeDuringActorConstruction", "true" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomStatics, nullptr, "CreateRootedAtomComponent", nullptr, nullptr, sizeof(AtomStatics_eventCreateRootedAtomComponent_Parms), Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022409, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomStatics_LoadAtomConfig_Statics
	{
		struct AtomStatics_eventLoadAtomConfig_Parms
		{
			USoundAtomConfig* AcfObject;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AcfObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAtomStatics_LoadAtomConfig_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((AtomStatics_eventLoadAtomConfig_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomStatics_LoadAtomConfig_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomStatics_eventLoadAtomConfig_Parms), &Z_Construct_UFunction_UAtomStatics_LoadAtomConfig_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_LoadAtomConfig_Statics::NewProp_AcfObject = { "AcfObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventLoadAtomConfig_Parms, AcfObject), Z_Construct_UClass_USoundAtomConfig_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomStatics_LoadAtomConfig_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_LoadAtomConfig_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_LoadAtomConfig_Statics::NewProp_AcfObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_LoadAtomConfig_Statics::Function_MetaDataParams[] = {
		{ "Category", "Atom" },
		{ "ModuleRelativePath", "Classes/AtomStatics.h" },
		{ "ToolTip", "Reload ACF." },
		{ "UnsafeDuringActorConstruction", "true" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomStatics_LoadAtomConfig_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomStatics, nullptr, "LoadAtomConfig", nullptr, nullptr, sizeof(AtomStatics_eventLoadAtomConfig_Parms), Z_Construct_UFunction_UAtomStatics_LoadAtomConfig_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_LoadAtomConfig_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_LoadAtomConfig_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_LoadAtomConfig_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomStatics_LoadAtomConfig()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomStatics_LoadAtomConfig_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomStatics_PauseAudioOutput_Statics
	{
		struct AtomStatics_eventPauseAudioOutput_Parms
		{
			bool bPause;
		};
		static void NewProp_bPause_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bPause;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAtomStatics_PauseAudioOutput_Statics::NewProp_bPause_SetBit(void* Obj)
	{
		((AtomStatics_eventPauseAudioOutput_Parms*)Obj)->bPause = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomStatics_PauseAudioOutput_Statics::NewProp_bPause = { "bPause", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomStatics_eventPauseAudioOutput_Parms), &Z_Construct_UFunction_UAtomStatics_PauseAudioOutput_Statics::NewProp_bPause_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomStatics_PauseAudioOutput_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PauseAudioOutput_Statics::NewProp_bPause,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_PauseAudioOutput_Statics::Function_MetaDataParams[] = {
		{ "Category", "Atom" },
		{ "ModuleRelativePath", "Classes/AtomStatics.h" },
		{ "ToolTip", "Pause audio output." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomStatics_PauseAudioOutput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomStatics, nullptr, "PauseAudioOutput", nullptr, nullptr, sizeof(AtomStatics_eventPauseAudioOutput_Parms), Z_Construct_UFunction_UAtomStatics_PauseAudioOutput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_PauseAudioOutput_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_PauseAudioOutput_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_PauseAudioOutput_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomStatics_PauseAudioOutput()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomStatics_PauseAudioOutput_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics
	{
		struct AtomStatics_eventPlaySoundAtLocation_Parms
		{
			UObject* WorldContextObject;
			USoundAtomCue* Sound;
			FVector Location;
			FRotator Rotation;
			float VolumeMultiplier;
			float PitchMultiplier;
			float StartTime;
			USoundAttenuation* AttenuationSettings;
			USoundConcurrency* ConcurrencySettings;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ConcurrencySettings;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttenuationSettings;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StartTime;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PitchMultiplier;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VolumeMultiplier;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Rotation;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Sound;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_ConcurrencySettings = { "ConcurrencySettings", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAtLocation_Parms, ConcurrencySettings), Z_Construct_UClass_USoundConcurrency_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_AttenuationSettings = { "AttenuationSettings", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAtLocation_Parms, AttenuationSettings), Z_Construct_UClass_USoundAttenuation_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_StartTime = { "StartTime", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAtLocation_Parms, StartTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_PitchMultiplier = { "PitchMultiplier", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAtLocation_Parms, PitchMultiplier), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_VolumeMultiplier = { "VolumeMultiplier", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAtLocation_Parms, VolumeMultiplier), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAtLocation_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAtLocation_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAtLocation_Parms, Sound), Z_Construct_UClass_USoundAtomCue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAtLocation_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_ConcurrencySettings,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_AttenuationSettings,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_StartTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_PitchMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_VolumeMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_Rotation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_Location,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_Sound,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "3" },
		{ "Category", "Atom" },
		{ "CPP_Default_AttenuationSettings", "None" },
		{ "CPP_Default_ConcurrencySettings", "None" },
		{ "CPP_Default_PitchMultiplier", "1.000000" },
		{ "CPP_Default_Rotation", "" },
		{ "CPP_Default_StartTime", "0.000000" },
		{ "CPP_Default_VolumeMultiplier", "1.000000" },
		{ "ModuleRelativePath", "Classes/AtomStatics.h" },
		{ "ToolTip", "Play sound at location." },
		{ "UnsafeDuringActorConstruction", "true" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomStatics, nullptr, "PlaySoundAtLocation", nullptr, nullptr, sizeof(AtomStatics_eventPlaySoundAtLocation_Parms), Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics
	{
		struct AtomStatics_eventPlaySoundAttached_Parms
		{
			USoundAtomCue* Sound;
			USceneComponent* AttachToComponent;
			FName AttachPointName;
			FVector Location;
			bool bStopWhenAttachedToDestroyed;
			float VolumeMultiplier;
			float PitchMultiplier;
			float StartTime;
			USoundAttenuation* AttenuationSettings;
			UAtomComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttenuationSettings;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StartTime;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PitchMultiplier;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VolumeMultiplier;
		static void NewProp_bStopWhenAttachedToDestroyed_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bStopWhenAttachedToDestroyed;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_AttachPointName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachToComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttachToComponent;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Sound;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAttached_Parms, ReturnValue), Z_Construct_UClass_UAtomComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_AttenuationSettings = { "AttenuationSettings", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAttached_Parms, AttenuationSettings), Z_Construct_UClass_USoundAttenuation_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_StartTime = { "StartTime", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAttached_Parms, StartTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_PitchMultiplier = { "PitchMultiplier", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAttached_Parms, PitchMultiplier), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_VolumeMultiplier = { "VolumeMultiplier", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAttached_Parms, VolumeMultiplier), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_bStopWhenAttachedToDestroyed_SetBit(void* Obj)
	{
		((AtomStatics_eventPlaySoundAttached_Parms*)Obj)->bStopWhenAttachedToDestroyed = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_bStopWhenAttachedToDestroyed = { "bStopWhenAttachedToDestroyed", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomStatics_eventPlaySoundAttached_Parms), &Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_bStopWhenAttachedToDestroyed_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAttached_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_AttachPointName = { "AttachPointName", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAttached_Parms, AttachPointName), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_AttachToComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_AttachToComponent = { "AttachToComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAttached_Parms, AttachToComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_AttachToComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_AttachToComponent_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundAttached_Parms, Sound), Z_Construct_UClass_USoundAtomCue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_AttenuationSettings,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_StartTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_PitchMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_VolumeMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_bStopWhenAttachedToDestroyed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_Location,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_AttachPointName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_AttachToComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::NewProp_Sound,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "2" },
		{ "Category", "Atom" },
		{ "CPP_Default_AttachPointName", "None" },
		{ "CPP_Default_AttenuationSettings", "None" },
		{ "CPP_Default_bStopWhenAttachedToDestroyed", "false" },
		{ "CPP_Default_Location", "" },
		{ "CPP_Default_PitchMultiplier", "1.000000" },
		{ "CPP_Default_StartTime", "0.000000" },
		{ "CPP_Default_VolumeMultiplier", "1.000000" },
		{ "ModuleRelativePath", "Classes/AtomStatics.h" },
		{ "ToolTip", "Play sound attached." },
		{ "UnsafeDuringActorConstruction", "true" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomStatics, nullptr, "PlaySoundAttached", nullptr, nullptr, sizeof(AtomStatics_eventPlaySoundAttached_Parms), Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomStatics_PlaySoundAttached()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomStatics_PlaySoundAttached_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics
	{
		struct AtomStatics_eventPlaySoundForAnimNotify_Parms
		{
			USoundAtomCue* Sound;
			USceneComponent* AttachToComponent;
			FName AttachPointName;
			FVector Location;
			bool bStopWhenAttachedToDestroyed;
			float VolumeMultiplier;
			float PitchMultiplier;
			float StartTime;
			USoundAttenuation* AttenuationSettings;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttenuationSettings;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StartTime;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PitchMultiplier;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VolumeMultiplier;
		static void NewProp_bStopWhenAttachedToDestroyed_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bStopWhenAttachedToDestroyed;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_AttachPointName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachToComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttachToComponent;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Sound;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_AttenuationSettings = { "AttenuationSettings", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundForAnimNotify_Parms, AttenuationSettings), Z_Construct_UClass_USoundAttenuation_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_StartTime = { "StartTime", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundForAnimNotify_Parms, StartTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_PitchMultiplier = { "PitchMultiplier", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundForAnimNotify_Parms, PitchMultiplier), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_VolumeMultiplier = { "VolumeMultiplier", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundForAnimNotify_Parms, VolumeMultiplier), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_bStopWhenAttachedToDestroyed_SetBit(void* Obj)
	{
		((AtomStatics_eventPlaySoundForAnimNotify_Parms*)Obj)->bStopWhenAttachedToDestroyed = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_bStopWhenAttachedToDestroyed = { "bStopWhenAttachedToDestroyed", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomStatics_eventPlaySoundForAnimNotify_Parms), &Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_bStopWhenAttachedToDestroyed_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundForAnimNotify_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_AttachPointName = { "AttachPointName", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundForAnimNotify_Parms, AttachPointName), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_AttachToComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_AttachToComponent = { "AttachToComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundForAnimNotify_Parms, AttachToComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_AttachToComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_AttachToComponent_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventPlaySoundForAnimNotify_Parms, Sound), Z_Construct_UClass_USoundAtomCue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_AttenuationSettings,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_StartTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_PitchMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_VolumeMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_bStopWhenAttachedToDestroyed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_Location,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_AttachPointName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_AttachToComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::NewProp_Sound,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "2" },
		{ "Category", "Atom" },
		{ "CPP_Default_AttachPointName", "None" },
		{ "CPP_Default_AttenuationSettings", "None" },
		{ "CPP_Default_bStopWhenAttachedToDestroyed", "false" },
		{ "CPP_Default_Location", "" },
		{ "CPP_Default_PitchMultiplier", "1.000000" },
		{ "CPP_Default_StartTime", "0.000000" },
		{ "CPP_Default_VolumeMultiplier", "1.000000" },
		{ "ModuleRelativePath", "Classes/AtomStatics.h" },
		{ "ToolTip", "Play sound attached." },
		{ "UnsafeDuringActorConstruction", "true" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomStatics, nullptr, "PlaySoundForAnimNotify", nullptr, nullptr, sizeof(AtomStatics_eventPlaySoundForAnimNotify_Parms), Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics
	{
		struct AtomStatics_eventSpawnSound2D_Parms
		{
			const UObject* WorldContextObject;
			USoundAtomCue* Sound;
			float PitchMultiplier;
			float StartTime;
			bool bPersistAcrossLevelTransition;
			bool bAutoDestroy;
			UAtomComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static void NewProp_bAutoDestroy_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAutoDestroy;
		static void NewProp_bPersistAcrossLevelTransition_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bPersistAcrossLevelTransition;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StartTime;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PitchMultiplier;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Sound;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSound2D_Parms, ReturnValue), Z_Construct_UClass_UAtomComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_ReturnValue_MetaData)) };
	void Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_bAutoDestroy_SetBit(void* Obj)
	{
		((AtomStatics_eventSpawnSound2D_Parms*)Obj)->bAutoDestroy = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_bAutoDestroy = { "bAutoDestroy", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomStatics_eventSpawnSound2D_Parms), &Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_bAutoDestroy_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_bPersistAcrossLevelTransition_SetBit(void* Obj)
	{
		((AtomStatics_eventSpawnSound2D_Parms*)Obj)->bPersistAcrossLevelTransition = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_bPersistAcrossLevelTransition = { "bPersistAcrossLevelTransition", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomStatics_eventSpawnSound2D_Parms), &Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_bPersistAcrossLevelTransition_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_StartTime = { "StartTime", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSound2D_Parms, StartTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_PitchMultiplier = { "PitchMultiplier", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSound2D_Parms, PitchMultiplier), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSound2D_Parms, Sound), Z_Construct_UClass_USoundAtomCue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSound2D_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_WorldContextObject_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_WorldContextObject_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_bAutoDestroy,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_bPersistAcrossLevelTransition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_StartTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_PitchMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_Sound,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "2" },
		{ "Category", "Atom" },
		{ "CPP_Default_bAutoDestroy", "true" },
		{ "CPP_Default_bPersistAcrossLevelTransition", "false" },
		{ "CPP_Default_PitchMultiplier", "1.000000" },
		{ "CPP_Default_StartTime", "0.000000" },
		{ "Keywords", "Play" },
		{ "ModuleRelativePath", "Classes/AtomStatics.h" },
		{ "UnsafeDuringActorConstruction", "true" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomStatics, nullptr, "SpawnSound2D", nullptr, nullptr, sizeof(AtomStatics_eventSpawnSound2D_Parms), Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022409, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomStatics_SpawnSound2D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomStatics_SpawnSound2D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics
	{
		struct AtomStatics_eventSpawnSoundAtLocation_Parms
		{
			const UObject* WorldContextObject;
			USoundAtomCue* Sound;
			FVector Location;
			FRotator Rotation;
			float VolumeMultiplier;
			float PitchMultiplier;
			float StartTime;
			USoundAttenuation* AttenuationSettings;
			USoundConcurrency* ConcurrencySettings;
			bool bAutoDestroy;
			UAtomComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static void NewProp_bAutoDestroy_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAutoDestroy;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ConcurrencySettings;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttenuationSettings;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StartTime;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PitchMultiplier;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VolumeMultiplier;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Rotation;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Sound;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAtLocation_Parms, ReturnValue), Z_Construct_UClass_UAtomComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_ReturnValue_MetaData)) };
	void Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_bAutoDestroy_SetBit(void* Obj)
	{
		((AtomStatics_eventSpawnSoundAtLocation_Parms*)Obj)->bAutoDestroy = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_bAutoDestroy = { "bAutoDestroy", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomStatics_eventSpawnSoundAtLocation_Parms), &Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_bAutoDestroy_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_ConcurrencySettings = { "ConcurrencySettings", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAtLocation_Parms, ConcurrencySettings), Z_Construct_UClass_USoundConcurrency_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_AttenuationSettings = { "AttenuationSettings", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAtLocation_Parms, AttenuationSettings), Z_Construct_UClass_USoundAttenuation_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_StartTime = { "StartTime", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAtLocation_Parms, StartTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_PitchMultiplier = { "PitchMultiplier", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAtLocation_Parms, PitchMultiplier), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_VolumeMultiplier = { "VolumeMultiplier", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAtLocation_Parms, VolumeMultiplier), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAtLocation_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAtLocation_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAtLocation_Parms, Sound), Z_Construct_UClass_USoundAtomCue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAtLocation_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_WorldContextObject_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_WorldContextObject_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_bAutoDestroy,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_ConcurrencySettings,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_AttenuationSettings,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_StartTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_PitchMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_VolumeMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_Rotation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_Location,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_Sound,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "3" },
		{ "Category", "Atom" },
		{ "CPP_Default_AttenuationSettings", "None" },
		{ "CPP_Default_bAutoDestroy", "true" },
		{ "CPP_Default_ConcurrencySettings", "None" },
		{ "CPP_Default_PitchMultiplier", "1.000000" },
		{ "CPP_Default_Rotation", "" },
		{ "CPP_Default_StartTime", "0.000000" },
		{ "CPP_Default_VolumeMultiplier", "1.000000" },
		{ "Keywords", "play" },
		{ "ModuleRelativePath", "Classes/AtomStatics.h" },
		{ "ToolTip", "Spawn sound at location." },
		{ "UnsafeDuringActorConstruction", "true" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomStatics, nullptr, "SpawnSoundAtLocation", nullptr, nullptr, sizeof(AtomStatics_eventSpawnSoundAtLocation_Parms), Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics
	{
		struct AtomStatics_eventSpawnSoundAttached_Parms
		{
			USoundAtomCue* Sound;
			USceneComponent* AttachToComponent;
			FName AttachPointName;
			FVector Location;
			FRotator Rotation;
			TEnumAsByte<EAttachLocation::Type> LocationType;
			bool bStopWhenAttachedToDestroyed;
			float VolumeMultiplier;
			float PitchMultiplier;
			float StartTime;
			USoundAttenuation* AttenuationSettings;
			USoundConcurrency* ConcurrencySettings;
			bool bAutoDestroy;
			UAtomComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static void NewProp_bAutoDestroy_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAutoDestroy;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ConcurrencySettings;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttenuationSettings;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StartTime;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PitchMultiplier;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VolumeMultiplier;
		static void NewProp_bStopWhenAttachedToDestroyed_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bStopWhenAttachedToDestroyed;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_LocationType;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Rotation;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_AttachPointName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachToComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttachToComponent;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Sound;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAttached_Parms, ReturnValue), Z_Construct_UClass_UAtomComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_ReturnValue_MetaData)) };
	void Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_bAutoDestroy_SetBit(void* Obj)
	{
		((AtomStatics_eventSpawnSoundAttached_Parms*)Obj)->bAutoDestroy = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_bAutoDestroy = { "bAutoDestroy", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomStatics_eventSpawnSoundAttached_Parms), &Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_bAutoDestroy_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_ConcurrencySettings = { "ConcurrencySettings", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAttached_Parms, ConcurrencySettings), Z_Construct_UClass_USoundConcurrency_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_AttenuationSettings = { "AttenuationSettings", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAttached_Parms, AttenuationSettings), Z_Construct_UClass_USoundAttenuation_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_StartTime = { "StartTime", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAttached_Parms, StartTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_PitchMultiplier = { "PitchMultiplier", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAttached_Parms, PitchMultiplier), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_VolumeMultiplier = { "VolumeMultiplier", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAttached_Parms, VolumeMultiplier), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_bStopWhenAttachedToDestroyed_SetBit(void* Obj)
	{
		((AtomStatics_eventSpawnSoundAttached_Parms*)Obj)->bStopWhenAttachedToDestroyed = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_bStopWhenAttachedToDestroyed = { "bStopWhenAttachedToDestroyed", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AtomStatics_eventSpawnSoundAttached_Parms), &Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_bStopWhenAttachedToDestroyed_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_LocationType = { "LocationType", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAttached_Parms, LocationType), Z_Construct_UEnum_Engine_EAttachLocation, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAttached_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAttached_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_AttachPointName = { "AttachPointName", nullptr, (EPropertyFlags)0x0010040000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAttached_Parms, AttachPointName), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_AttachToComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_AttachToComponent = { "AttachToComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAttached_Parms, AttachToComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_AttachToComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_AttachToComponent_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AtomStatics_eventSpawnSoundAttached_Parms, Sound), Z_Construct_UClass_USoundAtomCue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_bAutoDestroy,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_ConcurrencySettings,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_AttenuationSettings,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_StartTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_PitchMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_VolumeMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_bStopWhenAttachedToDestroyed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_LocationType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_Rotation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_Location,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_AttachPointName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_AttachToComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::NewProp_Sound,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "2" },
		{ "Category", "Atom" },
		{ "CPP_Default_AttachPointName", "None" },
		{ "CPP_Default_AttenuationSettings", "None" },
		{ "CPP_Default_bAutoDestroy", "true" },
		{ "CPP_Default_bStopWhenAttachedToDestroyed", "false" },
		{ "CPP_Default_ConcurrencySettings", "None" },
		{ "CPP_Default_Location", "" },
		{ "CPP_Default_LocationType", "KeepRelativeOffset" },
		{ "CPP_Default_PitchMultiplier", "1.000000" },
		{ "CPP_Default_Rotation", "" },
		{ "CPP_Default_StartTime", "0.000000" },
		{ "CPP_Default_VolumeMultiplier", "1.000000" },
		{ "ModuleRelativePath", "Classes/AtomStatics.h" },
		{ "ToolTip", "Spawn sound attached." },
		{ "UnsafeDuringActorConstruction", "true" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomStatics, nullptr, "SpawnSoundAttached", nullptr, nullptr, sizeof(AtomStatics_eventSpawnSoundAttached_Parms), Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAtomStatics_StopAllSounds_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAtomStatics_StopAllSounds_Statics::Function_MetaDataParams[] = {
		{ "Category", "Atom" },
		{ "ModuleRelativePath", "Classes/AtomStatics.h" },
		{ "ToolTip", "Stop all sounds." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAtomStatics_StopAllSounds_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAtomStatics, nullptr, "StopAllSounds", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAtomStatics_StopAllSounds_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAtomStatics_StopAllSounds_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAtomStatics_StopAllSounds()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAtomStatics_StopAllSounds_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAtomStatics_NoRegister()
	{
		return UAtomStatics::StaticClass();
	}
	struct Z_Construct_UClass_UAtomStatics_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAtomStatics_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_CriWareRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAtomStatics_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAtomStatics_CreateRootedAtomComponent, "CreateRootedAtomComponent" }, // 2382351975
		{ &Z_Construct_UFunction_UAtomStatics_LoadAtomConfig, "LoadAtomConfig" }, // 3409660466
		{ &Z_Construct_UFunction_UAtomStatics_PauseAudioOutput, "PauseAudioOutput" }, // 1078673896
		{ &Z_Construct_UFunction_UAtomStatics_PlaySoundAtLocation, "PlaySoundAtLocation" }, // 2354862388
		{ &Z_Construct_UFunction_UAtomStatics_PlaySoundAttached, "PlaySoundAttached" }, // 2488026825
		{ &Z_Construct_UFunction_UAtomStatics_PlaySoundForAnimNotify, "PlaySoundForAnimNotify" }, // 2811633881
		{ &Z_Construct_UFunction_UAtomStatics_SpawnSound2D, "SpawnSound2D" }, // 1439237964
		{ &Z_Construct_UFunction_UAtomStatics_SpawnSoundAtLocation, "SpawnSoundAtLocation" }, // 305643623
		{ &Z_Construct_UFunction_UAtomStatics_SpawnSoundAttached, "SpawnSoundAttached" }, // 2535511579
		{ &Z_Construct_UFunction_UAtomStatics_StopAllSounds, "StopAllSounds" }, // 2720588582
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAtomStatics_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AtomStatics.h" },
		{ "ModuleRelativePath", "Classes/AtomStatics.h" },
		{ "ToolTip", "AtomComponent class." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAtomStatics_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAtomStatics>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAtomStatics_Statics::ClassParams = {
		&UAtomStatics::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UAtomStatics_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UAtomStatics_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAtomStatics()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAtomStatics_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAtomStatics, 3757417411);
	template<> CRIWARERUNTIME_API UClass* StaticClass<UAtomStatics>()
	{
		return UAtomStatics::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAtomStatics(Z_Construct_UClass_UAtomStatics, &UAtomStatics::StaticClass, TEXT("/Script/CriWareRuntime"), TEXT("UAtomStatics"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAtomStatics);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
