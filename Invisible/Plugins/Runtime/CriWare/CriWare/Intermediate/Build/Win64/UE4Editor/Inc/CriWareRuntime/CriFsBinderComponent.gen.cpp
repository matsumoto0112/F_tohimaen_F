// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CriWareRuntime/Classes/CriFsBinderComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCriFsBinderComponent() {}
// Cross Module References
	CRIWARERUNTIME_API UFunction* Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindError__DelegateSignature();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_UCriFsBinderComponent();
	CRIWARERUNTIME_API UFunction* Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindCompleted__DelegateSignature();
	CRIWARERUNTIME_API UEnum* Z_Construct_UEnum_CriWareRuntime_ECriFsBinderStatus();
	UPackage* Z_Construct_UPackage__Script_CriWareRuntime();
	CRIWARERUNTIME_API UClass* Z_Construct_UClass_UCriFsBinderComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UCriFsBinderComponent_Bind();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UCriFsBinderComponent_GetStatus();
	CRIWARERUNTIME_API UFunction* Z_Construct_UFunction_UCriFsBinderComponent_Stop();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindError__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindError__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/CriFsBinderComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindError__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCriFsBinderComponent, nullptr, "OnBindError__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindError__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindError__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindError__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindError__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindCompleted__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindCompleted__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/CriFsBinderComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindCompleted__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCriFsBinderComponent, nullptr, "OnBindCompleted__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindCompleted__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindCompleted__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindCompleted__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindCompleted__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	static UEnum* ECriFsBinderStatus_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_CriWareRuntime_ECriFsBinderStatus, Z_Construct_UPackage__Script_CriWareRuntime(), TEXT("ECriFsBinderStatus"));
		}
		return Singleton;
	}
	template<> CRIWARERUNTIME_API UEnum* StaticEnum<ECriFsBinderStatus>()
	{
		return ECriFsBinderStatus_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ECriFsBinderStatus(ECriFsBinderStatus_StaticEnum, TEXT("/Script/CriWareRuntime"), TEXT("ECriFsBinderStatus"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_CriWareRuntime_ECriFsBinderStatus_Hash() { return 2877524102U; }
	UEnum* Z_Construct_UEnum_CriWareRuntime_ECriFsBinderStatus()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_CriWareRuntime();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ECriFsBinderStatus"), 0, Get_Z_Construct_UEnum_CriWareRuntime_ECriFsBinderStatus_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ECriFsBinderStatus::Stop", (int64)ECriFsBinderStatus::Stop },
				{ "ECriFsBinderStatus::Binding", (int64)ECriFsBinderStatus::Binding },
				{ "ECriFsBinderStatus::Complete", (int64)ECriFsBinderStatus::Complete },
				{ "ECriFsBinderStatus::Error", (int64)ECriFsBinderStatus::Error },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Binding.Comment", "/** \xe5\x81\x9c\xe6\xad\xa2\xe4\xb8\xad */" },
				{ "Binding.Name", "ECriFsBinderStatus::Binding" },
				{ "Binding.ToolTip", "\xe5\x81\x9c\xe6\xad\xa2\xe4\xb8\xad" },
				{ "Comment", "/***************************************************************************\n *      \xe3\x83\x87\xe3\x83\xbc\xe3\x82\xbf\xe5\x9e\x8b\xe5\xae\xa3\xe8\xa8\x80\n *      Data Type Declarations\n ***************************************************************************/" },
				{ "Complete.Comment", "/** \xe3\x83\x90\xe3\x82\xa4\xe3\x83\xb3\xe3\x83\x89\xe4\xb8\xad */" },
				{ "Complete.Name", "ECriFsBinderStatus::Complete" },
				{ "Complete.ToolTip", "\xe3\x83\x90\xe3\x82\xa4\xe3\x83\xb3\xe3\x83\x89\xe4\xb8\xad" },
				{ "Error.Comment", "/** \xe3\x83\x90\xe3\x82\xa4\xe3\x83\xb3\xe3\x83\x89\xe5\xae\x8c\xe4\xba\x86 */" },
				{ "Error.Name", "ECriFsBinderStatus::Error" },
				{ "Error.ToolTip", "\xe3\x83\x90\xe3\x82\xa4\xe3\x83\xb3\xe3\x83\x89\xe5\xae\x8c\xe4\xba\x86" },
				{ "ModuleRelativePath", "Classes/CriFsBinderComponent.h" },
				{ "Stop.Name", "ECriFsBinderStatus::Stop" },
				{ "ToolTip", "\xe3\x83\x87\xe3\x83\xbc\xe3\x82\xbf\xe5\x9e\x8b\xe5\xae\xa3\xe8\xa8\x80\nData Type Declarations" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_CriWareRuntime,
				nullptr,
				"ECriFsBinderStatus",
				"ECriFsBinderStatus",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void UCriFsBinderComponent::StaticRegisterNativesUCriFsBinderComponent()
	{
		UClass* Class = UCriFsBinderComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Bind", &UCriFsBinderComponent::execBind },
			{ "GetStatus", &UCriFsBinderComponent::execGetStatus },
			{ "Stop", &UCriFsBinderComponent::execStop },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCriFsBinderComponent_Bind_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCriFsBinderComponent_Bind_Statics::Function_MetaDataParams[] = {
		{ "Category", "CriFsBinderComponent" },
		{ "Comment", "/* \xe3\x83\x90\xe3\x82\xa4\xe3\x83\xb3\xe3\x83\x89 */" },
		{ "ModuleRelativePath", "Classes/CriFsBinderComponent.h" },
		{ "ToolTip", "\xe3\x83\x90\xe3\x82\xa4\xe3\x83\xb3\xe3\x83\x89" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCriFsBinderComponent_Bind_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCriFsBinderComponent, nullptr, "Bind", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCriFsBinderComponent_Bind_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCriFsBinderComponent_Bind_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCriFsBinderComponent_Bind()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCriFsBinderComponent_Bind_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCriFsBinderComponent_GetStatus_Statics
	{
		struct CriFsBinderComponent_eventGetStatus_Parms
		{
			ECriFsBinderStatus ReturnValue;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCriFsBinderComponent_GetStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CriFsBinderComponent_eventGetStatus_Parms, ReturnValue), Z_Construct_UEnum_CriWareRuntime_ECriFsBinderStatus, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCriFsBinderComponent_GetStatus_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCriFsBinderComponent_GetStatus_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCriFsBinderComponent_GetStatus_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCriFsBinderComponent_GetStatus_Statics::NewProp_ReturnValue_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCriFsBinderComponent_GetStatus_Statics::Function_MetaDataParams[] = {
		{ "Category", "CriFsBinderComponent" },
		{ "Comment", "/* \xe3\x82\xb9\xe3\x83\x86\xe3\x83\xbc\xe3\x82\xbf\xe3\x82\xb9\xe3\x81\xae\xe5\x8f\x96\xe5\xbe\x97 */" },
		{ "ModuleRelativePath", "Classes/CriFsBinderComponent.h" },
		{ "ToolTip", "\xe3\x82\xb9\xe3\x83\x86\xe3\x83\xbc\xe3\x82\xbf\xe3\x82\xb9\xe3\x81\xae\xe5\x8f\x96\xe5\xbe\x97" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCriFsBinderComponent_GetStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCriFsBinderComponent, nullptr, "GetStatus", nullptr, nullptr, sizeof(CriFsBinderComponent_eventGetStatus_Parms), Z_Construct_UFunction_UCriFsBinderComponent_GetStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCriFsBinderComponent_GetStatus_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCriFsBinderComponent_GetStatus_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCriFsBinderComponent_GetStatus_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCriFsBinderComponent_GetStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCriFsBinderComponent_GetStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCriFsBinderComponent_Stop_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCriFsBinderComponent_Stop_Statics::Function_MetaDataParams[] = {
		{ "Category", "CriFsBinderComponent" },
		{ "Comment", "/* \xe5\x81\x9c\xe6\xad\xa2 */" },
		{ "ModuleRelativePath", "Classes/CriFsBinderComponent.h" },
		{ "ToolTip", "\xe5\x81\x9c\xe6\xad\xa2" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCriFsBinderComponent_Stop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCriFsBinderComponent, nullptr, "Stop", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCriFsBinderComponent_Stop_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCriFsBinderComponent_Stop_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCriFsBinderComponent_Stop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCriFsBinderComponent_Stop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCriFsBinderComponent_NoRegister()
	{
		return UCriFsBinderComponent::StaticClass();
	}
	struct Z_Construct_UClass_UCriFsBinderComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnBindError_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnBindError;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnBindCompleted_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnBindCompleted;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_FilePath;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCriFsBinderComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USceneComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_CriWareRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCriFsBinderComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCriFsBinderComponent_Bind, "Bind" }, // 142539466
		{ &Z_Construct_UFunction_UCriFsBinderComponent_GetStatus, "GetStatus" }, // 3387342895
		{ &Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindCompleted__DelegateSignature, "OnBindCompleted__DelegateSignature" }, // 2424441436
		{ &Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindError__DelegateSignature, "OnBindError__DelegateSignature" }, // 708583723
		{ &Z_Construct_UFunction_UCriFsBinderComponent_Stop, "Stop" }, // 2999745993
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCriFsBinderComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "CRIWARE" },
		{ "DisplayName", "Cri Fs Binder" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "CriFsBinderComponent.h" },
		{ "ModuleRelativePath", "Classes/CriFsBinderComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "Cri Fs Binder Component" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCriFsBinderComponent_Statics::NewProp_OnBindError_MetaData[] = {
		{ "Category", "CriFsBinderComponent" },
		{ "Comment", "/* \xe3\x83\x90\xe3\x82\xa4\xe3\x83\xb3\xe3\x83\x89\xe5\xa4\xb1\xe6\x95\x97\xe6\x99\x82\xe3\x81\xab\xe5\x91\xbc\xe3\x81\xb3\xe5\x87\xba\xe3\x81\x95\xe3\x82\x8c\xe3\x82\x8b\xe3\x83\x87\xe3\x83\xaa\xe3\x82\xb2\xe3\x83\xbc\xe3\x83\x88 */" },
		{ "ModuleRelativePath", "Classes/CriFsBinderComponent.h" },
		{ "ToolTip", "\xe3\x83\x90\xe3\x82\xa4\xe3\x83\xb3\xe3\x83\x89\xe5\xa4\xb1\xe6\x95\x97\xe6\x99\x82\xe3\x81\xab\xe5\x91\xbc\xe3\x81\xb3\xe5\x87\xba\xe3\x81\x95\xe3\x82\x8c\xe3\x82\x8b\xe3\x83\x87\xe3\x83\xaa\xe3\x82\xb2\xe3\x83\xbc\xe3\x83\x88" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCriFsBinderComponent_Statics::NewProp_OnBindError = { "OnBindError", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCriFsBinderComponent, OnBindError), Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindError__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UCriFsBinderComponent_Statics::NewProp_OnBindError_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCriFsBinderComponent_Statics::NewProp_OnBindError_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCriFsBinderComponent_Statics::NewProp_OnBindCompleted_MetaData[] = {
		{ "Category", "CriFsBinderComponent" },
		{ "Comment", "/* \xe3\x83\x90\xe3\x82\xa4\xe3\x83\xb3\xe3\x83\x89\xe5\xae\x8c\xe4\xba\x86\xe6\x99\x82\xe3\x81\xab\xe5\x91\xbc\xe3\x81\xb3\xe5\x87\xba\xe3\x81\x95\xe3\x82\x8c\xe3\x82\x8b\xe3\x83\x87\xe3\x83\xaa\xe3\x82\xb2\xe3\x83\xbc\xe3\x83\x88 */" },
		{ "ModuleRelativePath", "Classes/CriFsBinderComponent.h" },
		{ "ToolTip", "\xe3\x83\x90\xe3\x82\xa4\xe3\x83\xb3\xe3\x83\x89\xe5\xae\x8c\xe4\xba\x86\xe6\x99\x82\xe3\x81\xab\xe5\x91\xbc\xe3\x81\xb3\xe5\x87\xba\xe3\x81\x95\xe3\x82\x8c\xe3\x82\x8b\xe3\x83\x87\xe3\x83\xaa\xe3\x82\xb2\xe3\x83\xbc\xe3\x83\x88" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCriFsBinderComponent_Statics::NewProp_OnBindCompleted = { "OnBindCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCriFsBinderComponent, OnBindCompleted), Z_Construct_UDelegateFunction_UCriFsBinderComponent_OnBindCompleted__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UCriFsBinderComponent_Statics::NewProp_OnBindCompleted_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCriFsBinderComponent_Statics::NewProp_OnBindCompleted_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCriFsBinderComponent_Statics::NewProp_FilePath_MetaData[] = {
		{ "Category", "FilePath" },
		{ "Comment", "/* \xe3\x83\x95\xe3\x82\xa1\xe3\x82\xa4\xe3\x83\xab\xe3\x83\x91\xe3\x82\xb9 */" },
		{ "ModuleRelativePath", "Classes/CriFsBinderComponent.h" },
		{ "ToolTip", "\xe3\x83\x95\xe3\x82\xa1\xe3\x82\xa4\xe3\x83\xab\xe3\x83\x91\xe3\x82\xb9" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCriFsBinderComponent_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCriFsBinderComponent, FilePath), METADATA_PARAMS(Z_Construct_UClass_UCriFsBinderComponent_Statics::NewProp_FilePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCriFsBinderComponent_Statics::NewProp_FilePath_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCriFsBinderComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCriFsBinderComponent_Statics::NewProp_OnBindError,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCriFsBinderComponent_Statics::NewProp_OnBindCompleted,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCriFsBinderComponent_Statics::NewProp_FilePath,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCriFsBinderComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCriFsBinderComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCriFsBinderComponent_Statics::ClassParams = {
		&UCriFsBinderComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCriFsBinderComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCriFsBinderComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UCriFsBinderComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCriFsBinderComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCriFsBinderComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCriFsBinderComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCriFsBinderComponent, 129223065);
	template<> CRIWARERUNTIME_API UClass* StaticClass<UCriFsBinderComponent>()
	{
		return UCriFsBinderComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCriFsBinderComponent(Z_Construct_UClass_UCriFsBinderComponent, &UCriFsBinderComponent::StaticClass, TEXT("/Script/CriWareRuntime"), TEXT("UCriFsBinderComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCriFsBinderComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
