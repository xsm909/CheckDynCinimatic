// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CinimaticDirectorRuntime/CinematicCreator/CinematicDirectorSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCinematicDirectorSubsystem() {}

// ********** Begin Cross Module References ********************************************************
CINIMATICDIRECTORRUNTIME_API UClass* Z_Construct_UClass_UCinematicCreator_NoRegister();
CINIMATICDIRECTORRUNTIME_API UClass* Z_Construct_UClass_UCinematicDirectorSubsystem();
CINIMATICDIRECTORRUNTIME_API UClass* Z_Construct_UClass_UCinematicDirectorSubsystem_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
LEVELSEQUENCE_API UClass* Z_Construct_UClass_ALevelSequenceActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_CinimaticDirectorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCinematicDirectorSubsystem Function CreateCinematic *********************
struct Z_Construct_UFunction_UCinematicDirectorSubsystem_CreateCinematic_Statics
{
	struct CinematicDirectorSubsystem_eventCreateCinematic_Parms
	{
		UCinematicCreator* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicDirectorSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CreateCinematic constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreateCinematic constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreateCinematic Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCinematicDirectorSubsystem_CreateCinematic_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirectorSubsystem_eventCreateCinematic_Parms, ReturnValue), Z_Construct_UClass_UCinematicCreator_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCinematicDirectorSubsystem_CreateCinematic_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicDirectorSubsystem_CreateCinematic_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicDirectorSubsystem_CreateCinematic_Statics::PropPointers) < 2048);
// ********** End Function CreateCinematic Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicDirectorSubsystem_CreateCinematic_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicDirectorSubsystem, nullptr, "CreateCinematic", 	Z_Construct_UFunction_UCinematicDirectorSubsystem_CreateCinematic_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicDirectorSubsystem_CreateCinematic_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCinematicDirectorSubsystem_CreateCinematic_Statics::CinematicDirectorSubsystem_eventCreateCinematic_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicDirectorSubsystem_CreateCinematic_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicDirectorSubsystem_CreateCinematic_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCinematicDirectorSubsystem_CreateCinematic_Statics::CinematicDirectorSubsystem_eventCreateCinematic_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCinematicDirectorSubsystem_CreateCinematic()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicDirectorSubsystem_CreateCinematic_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicDirectorSubsystem::execCreateCinematic)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCinematicCreator**)Z_Param__Result=P_THIS->CreateCinematic();
	P_NATIVE_END;
}
// ********** End Class UCinematicDirectorSubsystem Function CreateCinematic ***********************

// ********** Begin Class UCinematicDirectorSubsystem Function DestroyCinematic ********************
struct Z_Construct_UFunction_UCinematicDirectorSubsystem_DestroyCinematic_Statics
{
	struct CinematicDirectorSubsystem_eventDestroyCinematic_Parms
	{
		UCinematicCreator* Creator;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicDirectorSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DestroyCinematic constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Creator;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DestroyCinematic constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DestroyCinematic Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCinematicDirectorSubsystem_DestroyCinematic_Statics::NewProp_Creator = { "Creator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirectorSubsystem_eventDestroyCinematic_Parms, Creator), Z_Construct_UClass_UCinematicCreator_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCinematicDirectorSubsystem_DestroyCinematic_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicDirectorSubsystem_DestroyCinematic_Statics::NewProp_Creator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicDirectorSubsystem_DestroyCinematic_Statics::PropPointers) < 2048);
// ********** End Function DestroyCinematic Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicDirectorSubsystem_DestroyCinematic_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicDirectorSubsystem, nullptr, "DestroyCinematic", 	Z_Construct_UFunction_UCinematicDirectorSubsystem_DestroyCinematic_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicDirectorSubsystem_DestroyCinematic_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCinematicDirectorSubsystem_DestroyCinematic_Statics::CinematicDirectorSubsystem_eventDestroyCinematic_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicDirectorSubsystem_DestroyCinematic_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicDirectorSubsystem_DestroyCinematic_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCinematicDirectorSubsystem_DestroyCinematic_Statics::CinematicDirectorSubsystem_eventDestroyCinematic_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCinematicDirectorSubsystem_DestroyCinematic()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicDirectorSubsystem_DestroyCinematic_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicDirectorSubsystem::execDestroyCinematic)
{
	P_GET_OBJECT(UCinematicCreator,Z_Param_Creator);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DestroyCinematic(Z_Param_Creator);
	P_NATIVE_END;
}
// ********** End Class UCinematicDirectorSubsystem Function DestroyCinematic **********************

// ********** Begin Class UCinematicDirectorSubsystem Function PlayCinematicByIndex ****************
struct Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics
{
	struct CinematicDirectorSubsystem_eventPlayCinematicByIndex_Parms
	{
		int32 Index;
		FTransform SpawnTransform;
		ALevelSequenceActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicDirectorSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function PlayCinematicByIndex constinit property declarations ******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnTransform;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function PlayCinematicByIndex constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function PlayCinematicByIndex Property Definitions *****************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirectorSubsystem_eventPlayCinematicByIndex_Parms, Index), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics::NewProp_SpawnTransform = { "SpawnTransform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirectorSubsystem_eventPlayCinematicByIndex_Parms, SpawnTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirectorSubsystem_eventPlayCinematicByIndex_Parms, ReturnValue), Z_Construct_UClass_ALevelSequenceActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics::NewProp_Index,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics::NewProp_SpawnTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics::PropPointers) < 2048);
// ********** End Function PlayCinematicByIndex Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicDirectorSubsystem, nullptr, "PlayCinematicByIndex", 	Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics::CinematicDirectorSubsystem_eventPlayCinematicByIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics::CinematicDirectorSubsystem_eventPlayCinematicByIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicDirectorSubsystem::execPlayCinematicByIndex)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Index);
	P_GET_STRUCT(FTransform,Z_Param_SpawnTransform);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ALevelSequenceActor**)Z_Param__Result=P_THIS->PlayCinematicByIndex(Z_Param_Index,Z_Param_SpawnTransform);
	P_NATIVE_END;
}
// ********** End Class UCinematicDirectorSubsystem Function PlayCinematicByIndex ******************

// ********** Begin Class UCinematicDirectorSubsystem Function SaveCinematicByIndex ****************
struct Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics
{
	struct CinematicDirectorSubsystem_eventSaveCinematicByIndex_Parms
	{
		int32 Index;
		FString AssetName;
		FString PackagePath;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicDirectorSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SaveCinematicByIndex constinit property declarations ******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AssetName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PackagePath;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SaveCinematicByIndex constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SaveCinematicByIndex Property Definitions *****************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirectorSubsystem_eventSaveCinematicByIndex_Parms, Index), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::NewProp_AssetName = { "AssetName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirectorSubsystem_eventSaveCinematicByIndex_Parms, AssetName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::NewProp_PackagePath = { "PackagePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirectorSubsystem_eventSaveCinematicByIndex_Parms, PackagePath), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CinematicDirectorSubsystem_eventSaveCinematicByIndex_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CinematicDirectorSubsystem_eventSaveCinematicByIndex_Parms), &Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::NewProp_Index,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::NewProp_AssetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::NewProp_PackagePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::PropPointers) < 2048);
// ********** End Function SaveCinematicByIndex Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicDirectorSubsystem, nullptr, "SaveCinematicByIndex", 	Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::CinematicDirectorSubsystem_eventSaveCinematicByIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::CinematicDirectorSubsystem_eventSaveCinematicByIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicDirectorSubsystem::execSaveCinematicByIndex)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Index);
	P_GET_PROPERTY(FStrProperty,Z_Param_AssetName);
	P_GET_PROPERTY(FStrProperty,Z_Param_PackagePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SaveCinematicByIndex(Z_Param_Index,Z_Param_AssetName,Z_Param_PackagePath);
	P_NATIVE_END;
}
// ********** End Class UCinematicDirectorSubsystem Function SaveCinematicByIndex ******************

// ********** Begin Class UCinematicDirectorSubsystem **********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCinematicDirectorSubsystem;
UClass* UCinematicDirectorSubsystem::GetPrivateStaticClass()
{
	using TClass = UCinematicDirectorSubsystem;
	if (!Z_Registration_Info_UClass_UCinematicDirectorSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CinematicDirectorSubsystem"),
			Z_Registration_Info_UClass_UCinematicDirectorSubsystem.InnerSingleton,
			StaticRegisterNativesUCinematicDirectorSubsystem,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UCinematicDirectorSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UCinematicDirectorSubsystem_NoRegister()
{
	return UCinematicDirectorSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCinematicDirectorSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "CinematicCreator/CinematicDirectorSubsystem.h" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicDirectorSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveCinematics_MetaData[] = {
		{ "ModuleRelativePath", "CinematicCreator/CinematicDirectorSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCinematicDirectorSubsystem constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveCinematics_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ActiveCinematics;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCinematicDirectorSubsystem constinit property declarations ****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CreateCinematic"), .Pointer = &UCinematicDirectorSubsystem::execCreateCinematic },
		{ .NameUTF8 = UTF8TEXT("DestroyCinematic"), .Pointer = &UCinematicDirectorSubsystem::execDestroyCinematic },
		{ .NameUTF8 = UTF8TEXT("PlayCinematicByIndex"), .Pointer = &UCinematicDirectorSubsystem::execPlayCinematicByIndex },
		{ .NameUTF8 = UTF8TEXT("SaveCinematicByIndex"), .Pointer = &UCinematicDirectorSubsystem::execSaveCinematicByIndex },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCinematicDirectorSubsystem_CreateCinematic, "CreateCinematic" }, // 3682278034
		{ &Z_Construct_UFunction_UCinematicDirectorSubsystem_DestroyCinematic, "DestroyCinematic" }, // 973374745
		{ &Z_Construct_UFunction_UCinematicDirectorSubsystem_PlayCinematicByIndex, "PlayCinematicByIndex" }, // 2922845751
		{ &Z_Construct_UFunction_UCinematicDirectorSubsystem_SaveCinematicByIndex, "SaveCinematicByIndex" }, // 2064102490
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCinematicDirectorSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCinematicDirectorSubsystem_Statics

// ********** Begin Class UCinematicDirectorSubsystem Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCinematicDirectorSubsystem_Statics::NewProp_ActiveCinematics_Inner = { "ActiveCinematics", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UCinematicCreator_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCinematicDirectorSubsystem_Statics::NewProp_ActiveCinematics = { "ActiveCinematics", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCinematicDirectorSubsystem, ActiveCinematics), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveCinematics_MetaData), NewProp_ActiveCinematics_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCinematicDirectorSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCinematicDirectorSubsystem_Statics::NewProp_ActiveCinematics_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCinematicDirectorSubsystem_Statics::NewProp_ActiveCinematics,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCinematicDirectorSubsystem_Statics::PropPointers) < 2048);
// ********** End Class UCinematicDirectorSubsystem Property Definitions ***************************
UObject* (*const Z_Construct_UClass_UCinematicDirectorSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_CinimaticDirectorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCinematicDirectorSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCinematicDirectorSubsystem_Statics::ClassParams = {
	&UCinematicDirectorSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCinematicDirectorSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCinematicDirectorSubsystem_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCinematicDirectorSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UCinematicDirectorSubsystem_Statics::Class_MetaDataParams)
};
void UCinematicDirectorSubsystem::StaticRegisterNativesUCinematicDirectorSubsystem()
{
	UClass* Class = UCinematicDirectorSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCinematicDirectorSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCinematicDirectorSubsystem()
{
	if (!Z_Registration_Info_UClass_UCinematicDirectorSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCinematicDirectorSubsystem.OuterSingleton, Z_Construct_UClass_UCinematicDirectorSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCinematicDirectorSubsystem.OuterSingleton;
}
UCinematicDirectorSubsystem::UCinematicDirectorSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCinematicDirectorSubsystem);
UCinematicDirectorSubsystem::~UCinematicDirectorSubsystem() {}
// ********** End Class UCinematicDirectorSubsystem ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicDirectorSubsystem_h__Script_CinimaticDirectorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCinematicDirectorSubsystem, UCinematicDirectorSubsystem::StaticClass, TEXT("UCinematicDirectorSubsystem"), &Z_Registration_Info_UClass_UCinematicDirectorSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCinematicDirectorSubsystem), 3966385764U) },
	};
}; // Z_CompiledInDeferFile_FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicDirectorSubsystem_h__Script_CinimaticDirectorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicDirectorSubsystem_h__Script_CinimaticDirectorRuntime_1409200273{
	TEXT("/Script/CinimaticDirectorRuntime"),
	Z_CompiledInDeferFile_FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicDirectorSubsystem_h__Script_CinimaticDirectorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicDirectorSubsystem_h__Script_CinimaticDirectorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
