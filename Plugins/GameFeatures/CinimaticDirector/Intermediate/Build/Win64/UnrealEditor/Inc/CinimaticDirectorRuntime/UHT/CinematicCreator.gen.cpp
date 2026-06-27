// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CinimaticDirectorRuntime/CinematicCreator/CinematicCreator.h"
#include "UObject/Class.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCinematicCreator() {}

// ********** Begin Cross Module References ********************************************************
CINIMATICDIRECTORRUNTIME_API UClass* Z_Construct_UClass_UCinematicCreator();
CINIMATICDIRECTORRUNTIME_API UClass* Z_Construct_UClass_UCinematicCreator_NoRegister();
CINIMATICDIRECTORRUNTIME_API UEnum* Z_Construct_UEnum_CinimaticDirectorRuntime_ECinematicInterpType();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
LEVELSEQUENCE_API UClass* Z_Construct_UClass_ULevelSequence_NoRegister();
UPackage* Z_Construct_UPackage__Script_CinimaticDirectorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCinematicCreator Function AddBoolPropertyKey ****************************
struct Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics
{
	struct CinematicCreator_eventAddBoolPropertyKey_Parms
	{
		FName Alias;
		FName PropertyName;
		bool bValue;
		float Time;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic|Variables" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicCreator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddBoolPropertyKey constinit property declarations ********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Alias;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static void NewProp_bValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Time;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddBoolPropertyKey constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddBoolPropertyKey Property Definitions *******************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::NewProp_Alias = { "Alias", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddBoolPropertyKey_Parms, Alias), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddBoolPropertyKey_Parms, PropertyName), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::NewProp_bValue_SetBit(void* Obj)
{
	((CinematicCreator_eventAddBoolPropertyKey_Parms*)Obj)->bValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CinematicCreator_eventAddBoolPropertyKey_Parms), &Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::NewProp_Time = { "Time", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddBoolPropertyKey_Parms, Time), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::NewProp_Alias,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::NewProp_bValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::NewProp_Time,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::PropPointers) < 2048);
// ********** End Function AddBoolPropertyKey Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicCreator, nullptr, "AddBoolPropertyKey", 	Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::CinematicCreator_eventAddBoolPropertyKey_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::CinematicCreator_eventAddBoolPropertyKey_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicCreator::execAddBoolPropertyKey)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_Alias);
	P_GET_PROPERTY(FNameProperty,Z_Param_PropertyName);
	P_GET_UBOOL(Z_Param_bValue);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Time);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddBoolPropertyKey(Z_Param_Alias,Z_Param_PropertyName,Z_Param_bValue,Z_Param_Time);
	P_NATIVE_END;
}
// ********** End Class UCinematicCreator Function AddBoolPropertyKey ******************************

// ********** Begin Class UCinematicCreator Function AddFloatPropertyKey ***************************
struct Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics
{
	struct CinematicCreator_eventAddFloatPropertyKey_Parms
	{
		FName Alias;
		FName PropertyName;
		float Value;
		float Time;
		ECinematicInterpType Interp;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic|Variables" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicCreator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddFloatPropertyKey constinit property declarations *******************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Alias;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Time;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Interp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Interp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddFloatPropertyKey constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddFloatPropertyKey Property Definitions ******************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::NewProp_Alias = { "Alias", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddFloatPropertyKey_Parms, Alias), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddFloatPropertyKey_Parms, PropertyName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddFloatPropertyKey_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::NewProp_Time = { "Time", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddFloatPropertyKey_Parms, Time), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::NewProp_Interp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::NewProp_Interp = { "Interp", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddFloatPropertyKey_Parms, Interp), Z_Construct_UEnum_CinimaticDirectorRuntime_ECinematicInterpType, METADATA_PARAMS(0, nullptr) }; // 4291322744
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::NewProp_Alias,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::NewProp_Time,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::NewProp_Interp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::NewProp_Interp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::PropPointers) < 2048);
// ********** End Function AddFloatPropertyKey Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicCreator, nullptr, "AddFloatPropertyKey", 	Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::CinematicCreator_eventAddFloatPropertyKey_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::CinematicCreator_eventAddFloatPropertyKey_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicCreator::execAddFloatPropertyKey)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_Alias);
	P_GET_PROPERTY(FNameProperty,Z_Param_PropertyName);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Time);
	P_GET_ENUM(ECinematicInterpType,Z_Param_Interp);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddFloatPropertyKey(Z_Param_Alias,Z_Param_PropertyName,Z_Param_Value,Z_Param_Time,ECinematicInterpType(Z_Param_Interp));
	P_NATIVE_END;
}
// ********** End Class UCinematicCreator Function AddFloatPropertyKey *****************************

// ********** Begin Class UCinematicCreator Function AddRotatorPropertyKey *************************
struct Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics
{
	struct CinematicCreator_eventAddRotatorPropertyKey_Parms
	{
		FName Alias;
		FName PropertyName;
		FRotator Value;
		float Time;
		ECinematicInterpType Interp;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic|Variables" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicCreator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddRotatorPropertyKey constinit property declarations *****************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Alias;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Time;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Interp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Interp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddRotatorPropertyKey constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddRotatorPropertyKey Property Definitions ****************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::NewProp_Alias = { "Alias", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddRotatorPropertyKey_Parms, Alias), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddRotatorPropertyKey_Parms, PropertyName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddRotatorPropertyKey_Parms, Value), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::NewProp_Time = { "Time", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddRotatorPropertyKey_Parms, Time), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::NewProp_Interp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::NewProp_Interp = { "Interp", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddRotatorPropertyKey_Parms, Interp), Z_Construct_UEnum_CinimaticDirectorRuntime_ECinematicInterpType, METADATA_PARAMS(0, nullptr) }; // 4291322744
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::NewProp_Alias,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::NewProp_Time,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::NewProp_Interp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::NewProp_Interp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::PropPointers) < 2048);
// ********** End Function AddRotatorPropertyKey Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicCreator, nullptr, "AddRotatorPropertyKey", 	Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::CinematicCreator_eventAddRotatorPropertyKey_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::CinematicCreator_eventAddRotatorPropertyKey_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicCreator::execAddRotatorPropertyKey)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_Alias);
	P_GET_PROPERTY(FNameProperty,Z_Param_PropertyName);
	P_GET_STRUCT(FRotator,Z_Param_Value);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Time);
	P_GET_ENUM(ECinematicInterpType,Z_Param_Interp);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddRotatorPropertyKey(Z_Param_Alias,Z_Param_PropertyName,Z_Param_Value,Z_Param_Time,ECinematicInterpType(Z_Param_Interp));
	P_NATIVE_END;
}
// ********** End Class UCinematicCreator Function AddRotatorPropertyKey ***************************

// ********** Begin Class UCinematicCreator Function AddStringPropertyKey **************************
struct Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics
{
	struct CinematicCreator_eventAddStringPropertyKey_Parms
	{
		FName Alias;
		FName PropertyName;
		FString Value;
		float Time;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic|Variables" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicCreator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddStringPropertyKey constinit property declarations ******************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Alias;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Time;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddStringPropertyKey constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddStringPropertyKey Property Definitions *****************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::NewProp_Alias = { "Alias", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddStringPropertyKey_Parms, Alias), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddStringPropertyKey_Parms, PropertyName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddStringPropertyKey_Parms, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::NewProp_Time = { "Time", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddStringPropertyKey_Parms, Time), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::NewProp_Alias,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::NewProp_Time,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::PropPointers) < 2048);
// ********** End Function AddStringPropertyKey Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicCreator, nullptr, "AddStringPropertyKey", 	Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::CinematicCreator_eventAddStringPropertyKey_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::CinematicCreator_eventAddStringPropertyKey_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicCreator::execAddStringPropertyKey)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_Alias);
	P_GET_PROPERTY(FNameProperty,Z_Param_PropertyName);
	P_GET_PROPERTY(FStrProperty,Z_Param_Value);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Time);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddStringPropertyKey(Z_Param_Alias,Z_Param_PropertyName,Z_Param_Value,Z_Param_Time);
	P_NATIVE_END;
}
// ********** End Class UCinematicCreator Function AddStringPropertyKey ****************************

// ********** Begin Class UCinematicCreator Function AddTransformKey *******************************
struct Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics
{
	struct CinematicCreator_eventAddTransformKey_Parms
	{
		FName Alias;
		FTransform Transform;
		float Time;
		ECinematicInterpType Interp;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicCreator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddTransformKey constinit property declarations ***********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Alias;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Transform;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Time;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Interp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Interp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddTransformKey constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddTransformKey Property Definitions **********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::NewProp_Alias = { "Alias", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddTransformKey_Parms, Alias), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddTransformKey_Parms, Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::NewProp_Time = { "Time", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddTransformKey_Parms, Time), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::NewProp_Interp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::NewProp_Interp = { "Interp", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddTransformKey_Parms, Interp), Z_Construct_UEnum_CinimaticDirectorRuntime_ECinematicInterpType, METADATA_PARAMS(0, nullptr) }; // 4291322744
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::NewProp_Alias,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::NewProp_Transform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::NewProp_Time,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::NewProp_Interp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::NewProp_Interp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::PropPointers) < 2048);
// ********** End Function AddTransformKey Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicCreator, nullptr, "AddTransformKey", 	Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::CinematicCreator_eventAddTransformKey_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::CinematicCreator_eventAddTransformKey_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCinematicCreator_AddTransformKey()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicCreator_AddTransformKey_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicCreator::execAddTransformKey)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_Alias);
	P_GET_STRUCT(FTransform,Z_Param_Transform);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Time);
	P_GET_ENUM(ECinematicInterpType,Z_Param_Interp);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddTransformKey(Z_Param_Alias,Z_Param_Transform,Z_Param_Time,ECinematicInterpType(Z_Param_Interp));
	P_NATIVE_END;
}
// ********** End Class UCinematicCreator Function AddTransformKey *********************************

// ********** Begin Class UCinematicCreator Function AddVectorPropertyKey **************************
struct Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics
{
	struct CinematicCreator_eventAddVectorPropertyKey_Parms
	{
		FName Alias;
		FName PropertyName;
		FVector Value;
		float Time;
		ECinematicInterpType Interp;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic|Variables" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicCreator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddVectorPropertyKey constinit property declarations ******************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Alias;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Time;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Interp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Interp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddVectorPropertyKey constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddVectorPropertyKey Property Definitions *****************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::NewProp_Alias = { "Alias", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddVectorPropertyKey_Parms, Alias), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddVectorPropertyKey_Parms, PropertyName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddVectorPropertyKey_Parms, Value), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::NewProp_Time = { "Time", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddVectorPropertyKey_Parms, Time), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::NewProp_Interp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::NewProp_Interp = { "Interp", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventAddVectorPropertyKey_Parms, Interp), Z_Construct_UEnum_CinimaticDirectorRuntime_ECinematicInterpType, METADATA_PARAMS(0, nullptr) }; // 4291322744
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::NewProp_Alias,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::NewProp_Time,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::NewProp_Interp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::NewProp_Interp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::PropPointers) < 2048);
// ********** End Function AddVectorPropertyKey Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicCreator, nullptr, "AddVectorPropertyKey", 	Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::CinematicCreator_eventAddVectorPropertyKey_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::CinematicCreator_eventAddVectorPropertyKey_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicCreator::execAddVectorPropertyKey)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_Alias);
	P_GET_PROPERTY(FNameProperty,Z_Param_PropertyName);
	P_GET_STRUCT(FVector,Z_Param_Value);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Time);
	P_GET_ENUM(ECinematicInterpType,Z_Param_Interp);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddVectorPropertyKey(Z_Param_Alias,Z_Param_PropertyName,Z_Param_Value,Z_Param_Time,ECinematicInterpType(Z_Param_Interp));
	P_NATIVE_END;
}
// ********** End Class UCinematicCreator Function AddVectorPropertyKey ****************************

// ********** Begin Class UCinematicCreator Function FlushChanges **********************************
struct Z_Construct_UFunction_UCinematicCreator_FlushChanges_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicCreator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function FlushChanges constinit property declarations **************************
// ********** End Function FlushChanges constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicCreator_FlushChanges_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicCreator, nullptr, "FlushChanges", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_FlushChanges_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicCreator_FlushChanges_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UCinematicCreator_FlushChanges()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicCreator_FlushChanges_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicCreator::execFlushChanges)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FlushChanges();
	P_NATIVE_END;
}
// ********** End Class UCinematicCreator Function FlushChanges ************************************

// ********** Begin Class UCinematicCreator Function GetSequence ***********************************
struct Z_Construct_UFunction_UCinematicCreator_GetSequence_Statics
{
	struct CinematicCreator_eventGetSequence_Parms
	{
		ULevelSequence* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicCreator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSequence constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSequence constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSequence Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCinematicCreator_GetSequence_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventGetSequence_Parms, ReturnValue), Z_Construct_UClass_ULevelSequence_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCinematicCreator_GetSequence_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_GetSequence_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_GetSequence_Statics::PropPointers) < 2048);
// ********** End Function GetSequence Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicCreator_GetSequence_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicCreator, nullptr, "GetSequence", 	Z_Construct_UFunction_UCinematicCreator_GetSequence_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_GetSequence_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCinematicCreator_GetSequence_Statics::CinematicCreator_eventGetSequence_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_GetSequence_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicCreator_GetSequence_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCinematicCreator_GetSequence_Statics::CinematicCreator_eventGetSequence_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCinematicCreator_GetSequence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicCreator_GetSequence_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicCreator::execGetSequence)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ULevelSequence**)Z_Param__Result=P_THIS->GetSequence();
	P_NATIVE_END;
}
// ********** End Class UCinematicCreator Function GetSequence *************************************

// ********** Begin Class UCinematicCreator Function RegisterPossessableActor **********************
struct Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics
{
	struct CinematicCreator_eventRegisterPossessableActor_Parms
	{
		AActor* Actor;
		FName Alias;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xd0\xa0\xd0\xb5\xd0\xb3\xd0\xb8\xd1\x81\xd1\x82\xd1\x80\xd0\xb0\xd1\x86\xd0\xb8\xd1\x8f \xd1\x83\xd0\xb6\xd0\xb5 \xd1\x81\xd1\x83\xd1\x89\xd0\xb5\xd1\x81\xd1\x82\xd0\xb2\xd1\x83\xd1\x8e\xd1\x89\xd0\xb5\xd0\xb3\xd0\xbe \xd0\xb0\xd0\xba\xd1\x82\xd0\xbe\xd1\x80\xd0\xb0 (Possessable)\n" },
#endif
		{ "ModuleRelativePath", "CinematicCreator/CinematicCreator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xd0\xa0\xd0\xb5\xd0\xb3\xd0\xb8\xd1\x81\xd1\x82\xd1\x80\xd0\xb0\xd1\x86\xd0\xb8\xd1\x8f \xd1\x83\xd0\xb6\xd0\xb5 \xd1\x81\xd1\x83\xd1\x89\xd0\xb5\xd1\x81\xd1\x82\xd0\xb2\xd1\x83\xd1\x8e\xd1\x89\xd0\xb5\xd0\xb3\xd0\xbe \xd0\xb0\xd0\xba\xd1\x82\xd0\xbe\xd1\x80\xd0\xb0 (Possessable)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RegisterPossessableActor constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Alias;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RegisterPossessableActor constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RegisterPossessableActor Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventRegisterPossessableActor_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::NewProp_Alias = { "Alias", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventRegisterPossessableActor_Parms, Alias), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CinematicCreator_eventRegisterPossessableActor_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CinematicCreator_eventRegisterPossessableActor_Parms), &Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::NewProp_Actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::NewProp_Alias,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::PropPointers) < 2048);
// ********** End Function RegisterPossessableActor Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicCreator, nullptr, "RegisterPossessableActor", 	Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::CinematicCreator_eventRegisterPossessableActor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::CinematicCreator_eventRegisterPossessableActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicCreator::execRegisterPossessableActor)
{
	P_GET_OBJECT(AActor,Z_Param_Actor);
	P_GET_PROPERTY(FNameProperty,Z_Param_Alias);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RegisterPossessableActor(Z_Param_Actor,Z_Param_Alias);
	P_NATIVE_END;
}
// ********** End Class UCinematicCreator Function RegisterPossessableActor ************************

// ********** Begin Class UCinematicCreator Function RegisterSpawnableActor ************************
struct Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics
{
	struct CinematicCreator_eventRegisterSpawnableActor_Parms
	{
		TSubclassOf<AActor> ActorClass;
		FName Alias;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xd0\xa0\xd0\xb5\xd0\xb3\xd0\xb8\xd1\x81\xd1\x82\xd1\x80\xd0\xb0\xd1\x86\xd0\xb8\xd1\x8f \xd0\xb0\xd0\xba\xd1\x82\xd0\xbe\xd1\x80\xd0\xb0, \xd0\xba\xd0\xbe\xd1\x82\xd0\xbe\xd1\x80\xd1\x8b\xd0\xb9 \xd0\xb1\xd1\x83\xd0\xb4\xd0\xb5\xd1\x82 \xd1\x81\xd0\xbe\xd0\xb7\xd0\xb4\xd0\xb0\xd0\xbd \xd1\x81\xd0\xb8\xd0\xbd\xd0\xb5\xd0\xbc\xd0\xb0\xd1\x82\xd0\xb8\xd0\xba\xd0\xbe\xd0\xbc (Spawnable)\n" },
#endif
		{ "ModuleRelativePath", "CinematicCreator/CinematicCreator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xd0\xa0\xd0\xb5\xd0\xb3\xd0\xb8\xd1\x81\xd1\x82\xd1\x80\xd0\xb0\xd1\x86\xd0\xb8\xd1\x8f \xd0\xb0\xd0\xba\xd1\x82\xd0\xbe\xd1\x80\xd0\xb0, \xd0\xba\xd0\xbe\xd1\x82\xd0\xbe\xd1\x80\xd1\x8b\xd0\xb9 \xd0\xb1\xd1\x83\xd0\xb4\xd0\xb5\xd1\x82 \xd1\x81\xd0\xbe\xd0\xb7\xd0\xb4\xd0\xb0\xd0\xbd \xd1\x81\xd0\xb8\xd0\xbd\xd0\xb5\xd0\xbc\xd0\xb0\xd1\x82\xd0\xb8\xd0\xba\xd0\xbe\xd0\xbc (Spawnable)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RegisterSpawnableActor constinit property declarations ****************
	static const UECodeGen_Private::FClassPropertyParams NewProp_ActorClass;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Alias;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RegisterSpawnableActor constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RegisterSpawnableActor Property Definitions ***************************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::NewProp_ActorClass = { "ActorClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventRegisterSpawnableActor_Parms, ActorClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::NewProp_Alias = { "Alias", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventRegisterSpawnableActor_Parms, Alias), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CinematicCreator_eventRegisterSpawnableActor_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CinematicCreator_eventRegisterSpawnableActor_Parms), &Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::NewProp_ActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::NewProp_Alias,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::PropPointers) < 2048);
// ********** End Function RegisterSpawnableActor Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicCreator, nullptr, "RegisterSpawnableActor", 	Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::CinematicCreator_eventRegisterSpawnableActor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::CinematicCreator_eventRegisterSpawnableActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicCreator::execRegisterSpawnableActor)
{
	P_GET_OBJECT(UClass,Z_Param_ActorClass);
	P_GET_PROPERTY(FNameProperty,Z_Param_Alias);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RegisterSpawnableActor(Z_Param_ActorClass,Z_Param_Alias);
	P_NATIVE_END;
}
// ********** End Class UCinematicCreator Function RegisterSpawnableActor **************************

// ********** Begin Class UCinematicCreator Function RegisterSpawnableSkeletalMeshActor ************
struct Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics
{
	struct CinematicCreator_eventRegisterSpawnableSkeletalMeshActor_Parms
	{
		USkeletalMesh* Mesh;
		FName Alias;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicCreator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RegisterSpawnableSkeletalMeshActor constinit property declarations ****
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Alias;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RegisterSpawnableSkeletalMeshActor constinit property declarations ******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RegisterSpawnableSkeletalMeshActor Property Definitions ***************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventRegisterSpawnableSkeletalMeshActor_Parms, Mesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::NewProp_Alias = { "Alias", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventRegisterSpawnableSkeletalMeshActor_Parms, Alias), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CinematicCreator_eventRegisterSpawnableSkeletalMeshActor_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CinematicCreator_eventRegisterSpawnableSkeletalMeshActor_Parms), &Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::NewProp_Mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::NewProp_Alias,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::PropPointers) < 2048);
// ********** End Function RegisterSpawnableSkeletalMeshActor Property Definitions *****************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicCreator, nullptr, "RegisterSpawnableSkeletalMeshActor", 	Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::CinematicCreator_eventRegisterSpawnableSkeletalMeshActor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::CinematicCreator_eventRegisterSpawnableSkeletalMeshActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicCreator::execRegisterSpawnableSkeletalMeshActor)
{
	P_GET_OBJECT(USkeletalMesh,Z_Param_Mesh);
	P_GET_PROPERTY(FNameProperty,Z_Param_Alias);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RegisterSpawnableSkeletalMeshActor(Z_Param_Mesh,Z_Param_Alias);
	P_NATIVE_END;
}
// ********** End Class UCinematicCreator Function RegisterSpawnableSkeletalMeshActor **************

// ********** Begin Class UCinematicCreator Function RegisterSpawnableStaticMeshActor **************
struct Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics
{
	struct CinematicCreator_eventRegisterSpawnableStaticMeshActor_Parms
	{
		UStaticMesh* Mesh;
		FName Alias;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicCreator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RegisterSpawnableStaticMeshActor constinit property declarations ******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Alias;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RegisterSpawnableStaticMeshActor constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RegisterSpawnableStaticMeshActor Property Definitions *****************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventRegisterSpawnableStaticMeshActor_Parms, Mesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::NewProp_Alias = { "Alias", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventRegisterSpawnableStaticMeshActor_Parms, Alias), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CinematicCreator_eventRegisterSpawnableStaticMeshActor_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CinematicCreator_eventRegisterSpawnableStaticMeshActor_Parms), &Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::NewProp_Mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::NewProp_Alias,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::PropPointers) < 2048);
// ********** End Function RegisterSpawnableStaticMeshActor Property Definitions *******************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicCreator, nullptr, "RegisterSpawnableStaticMeshActor", 	Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::CinematicCreator_eventRegisterSpawnableStaticMeshActor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::CinematicCreator_eventRegisterSpawnableStaticMeshActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicCreator::execRegisterSpawnableStaticMeshActor)
{
	P_GET_OBJECT(UStaticMesh,Z_Param_Mesh);
	P_GET_PROPERTY(FNameProperty,Z_Param_Alias);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RegisterSpawnableStaticMeshActor(Z_Param_Mesh,Z_Param_Alias);
	P_NATIVE_END;
}
// ********** End Class UCinematicCreator Function RegisterSpawnableStaticMeshActor ****************

// ********** Begin Class UCinematicCreator Function SetCinematicDuration **************************
struct Z_Construct_UFunction_UCinematicCreator_SetCinematicDuration_Statics
{
	struct CinematicCreator_eventSetCinematicDuration_Parms
	{
		float DurationInSeconds;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicCreator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCinematicDuration constinit property declarations ******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DurationInSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCinematicDuration constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCinematicDuration Property Definitions *****************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCinematicCreator_SetCinematicDuration_Statics::NewProp_DurationInSeconds = { "DurationInSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicCreator_eventSetCinematicDuration_Parms, DurationInSeconds), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCinematicCreator_SetCinematicDuration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCinematicCreator_SetCinematicDuration_Statics::NewProp_DurationInSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_SetCinematicDuration_Statics::PropPointers) < 2048);
// ********** End Function SetCinematicDuration Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCinematicCreator_SetCinematicDuration_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCinematicCreator, nullptr, "SetCinematicDuration", 	Z_Construct_UFunction_UCinematicCreator_SetCinematicDuration_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_SetCinematicDuration_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCinematicCreator_SetCinematicDuration_Statics::CinematicCreator_eventSetCinematicDuration_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCinematicCreator_SetCinematicDuration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCinematicCreator_SetCinematicDuration_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCinematicCreator_SetCinematicDuration_Statics::CinematicCreator_eventSetCinematicDuration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCinematicCreator_SetCinematicDuration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCinematicCreator_SetCinematicDuration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCinematicCreator::execSetCinematicDuration)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_DurationInSeconds);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCinematicDuration(Z_Param_DurationInSeconds);
	P_NATIVE_END;
}
// ********** End Class UCinematicCreator Function SetCinematicDuration ****************************

// ********** Begin Class UCinematicCreator ********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCinematicCreator;
UClass* UCinematicCreator::GetPrivateStaticClass()
{
	using TClass = UCinematicCreator;
	if (!Z_Registration_Info_UClass_UCinematicCreator.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CinematicCreator"),
			Z_Registration_Info_UClass_UCinematicCreator.InnerSingleton,
			StaticRegisterNativesUCinematicCreator,
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
	return Z_Registration_Info_UClass_UCinematicCreator.InnerSingleton;
}
UClass* Z_Construct_UClass_UCinematicCreator_NoRegister()
{
	return UCinematicCreator::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCinematicCreator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "CinematicCreator/CinematicCreator.h" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicCreator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sequence_MetaData[] = {
		{ "ModuleRelativePath", "CinematicCreator/CinematicCreator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCinematicCreator constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sequence;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCinematicCreator constinit property declarations **************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddBoolPropertyKey"), .Pointer = &UCinematicCreator::execAddBoolPropertyKey },
		{ .NameUTF8 = UTF8TEXT("AddFloatPropertyKey"), .Pointer = &UCinematicCreator::execAddFloatPropertyKey },
		{ .NameUTF8 = UTF8TEXT("AddRotatorPropertyKey"), .Pointer = &UCinematicCreator::execAddRotatorPropertyKey },
		{ .NameUTF8 = UTF8TEXT("AddStringPropertyKey"), .Pointer = &UCinematicCreator::execAddStringPropertyKey },
		{ .NameUTF8 = UTF8TEXT("AddTransformKey"), .Pointer = &UCinematicCreator::execAddTransformKey },
		{ .NameUTF8 = UTF8TEXT("AddVectorPropertyKey"), .Pointer = &UCinematicCreator::execAddVectorPropertyKey },
		{ .NameUTF8 = UTF8TEXT("FlushChanges"), .Pointer = &UCinematicCreator::execFlushChanges },
		{ .NameUTF8 = UTF8TEXT("GetSequence"), .Pointer = &UCinematicCreator::execGetSequence },
		{ .NameUTF8 = UTF8TEXT("RegisterPossessableActor"), .Pointer = &UCinematicCreator::execRegisterPossessableActor },
		{ .NameUTF8 = UTF8TEXT("RegisterSpawnableActor"), .Pointer = &UCinematicCreator::execRegisterSpawnableActor },
		{ .NameUTF8 = UTF8TEXT("RegisterSpawnableSkeletalMeshActor"), .Pointer = &UCinematicCreator::execRegisterSpawnableSkeletalMeshActor },
		{ .NameUTF8 = UTF8TEXT("RegisterSpawnableStaticMeshActor"), .Pointer = &UCinematicCreator::execRegisterSpawnableStaticMeshActor },
		{ .NameUTF8 = UTF8TEXT("SetCinematicDuration"), .Pointer = &UCinematicCreator::execSetCinematicDuration },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCinematicCreator_AddBoolPropertyKey, "AddBoolPropertyKey" }, // 3844017806
		{ &Z_Construct_UFunction_UCinematicCreator_AddFloatPropertyKey, "AddFloatPropertyKey" }, // 3734081569
		{ &Z_Construct_UFunction_UCinematicCreator_AddRotatorPropertyKey, "AddRotatorPropertyKey" }, // 916086471
		{ &Z_Construct_UFunction_UCinematicCreator_AddStringPropertyKey, "AddStringPropertyKey" }, // 344020825
		{ &Z_Construct_UFunction_UCinematicCreator_AddTransformKey, "AddTransformKey" }, // 4120311067
		{ &Z_Construct_UFunction_UCinematicCreator_AddVectorPropertyKey, "AddVectorPropertyKey" }, // 2407313384
		{ &Z_Construct_UFunction_UCinematicCreator_FlushChanges, "FlushChanges" }, // 3802193288
		{ &Z_Construct_UFunction_UCinematicCreator_GetSequence, "GetSequence" }, // 3198733038
		{ &Z_Construct_UFunction_UCinematicCreator_RegisterPossessableActor, "RegisterPossessableActor" }, // 3591746497
		{ &Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableActor, "RegisterSpawnableActor" }, // 14723223
		{ &Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableSkeletalMeshActor, "RegisterSpawnableSkeletalMeshActor" }, // 3529530703
		{ &Z_Construct_UFunction_UCinematicCreator_RegisterSpawnableStaticMeshActor, "RegisterSpawnableStaticMeshActor" }, // 1091808019
		{ &Z_Construct_UFunction_UCinematicCreator_SetCinematicDuration, "SetCinematicDuration" }, // 2866084287
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCinematicCreator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCinematicCreator_Statics

// ********** Begin Class UCinematicCreator Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCinematicCreator_Statics::NewProp_Sequence = { "Sequence", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCinematicCreator, Sequence), Z_Construct_UClass_ULevelSequence_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sequence_MetaData), NewProp_Sequence_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCinematicCreator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCinematicCreator_Statics::NewProp_Sequence,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCinematicCreator_Statics::PropPointers) < 2048);
// ********** End Class UCinematicCreator Property Definitions *************************************
UObject* (*const Z_Construct_UClass_UCinematicCreator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_CinimaticDirectorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCinematicCreator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCinematicCreator_Statics::ClassParams = {
	&UCinematicCreator::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCinematicCreator_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCinematicCreator_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCinematicCreator_Statics::Class_MetaDataParams), Z_Construct_UClass_UCinematicCreator_Statics::Class_MetaDataParams)
};
void UCinematicCreator::StaticRegisterNativesUCinematicCreator()
{
	UClass* Class = UCinematicCreator::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCinematicCreator_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCinematicCreator()
{
	if (!Z_Registration_Info_UClass_UCinematicCreator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCinematicCreator.OuterSingleton, Z_Construct_UClass_UCinematicCreator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCinematicCreator.OuterSingleton;
}
UCinematicCreator::UCinematicCreator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCinematicCreator);
UCinematicCreator::~UCinematicCreator() {}
// ********** End Class UCinematicCreator **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicCreator_h__Script_CinimaticDirectorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCinematicCreator, UCinematicCreator::StaticClass, TEXT("UCinematicCreator"), &Z_Registration_Info_UClass_UCinematicCreator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCinematicCreator), 1562974984U) },
	};
}; // Z_CompiledInDeferFile_FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicCreator_h__Script_CinimaticDirectorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicCreator_h__Script_CinimaticDirectorRuntime_3281125995{
	TEXT("/Script/CinimaticDirectorRuntime"),
	Z_CompiledInDeferFile_FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicCreator_h__Script_CinimaticDirectorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicCreator_h__Script_CinimaticDirectorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
