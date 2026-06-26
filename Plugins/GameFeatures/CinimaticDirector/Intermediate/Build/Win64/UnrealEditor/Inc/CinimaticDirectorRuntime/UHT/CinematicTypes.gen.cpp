// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CinimaticDirectorRuntime/CinematicCreator/CinematicTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCinematicTypes() {}

// ********** Begin Cross Module References ********************************************************
CINIMATICDIRECTORRUNTIME_API UEnum* Z_Construct_UEnum_CinimaticDirectorRuntime_ECinematicInterpType();
UPackage* Z_Construct_UPackage__Script_CinimaticDirectorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum ECinematicInterpType ******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECinematicInterpType;
static UEnum* ECinematicInterpType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECinematicInterpType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECinematicInterpType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CinimaticDirectorRuntime_ECinematicInterpType, (UObject*)Z_Construct_UPackage__Script_CinimaticDirectorRuntime(), TEXT("ECinematicInterpType"));
	}
	return Z_Registration_Info_UEnum_ECinematicInterpType.OuterSingleton;
}
template<> CINIMATICDIRECTORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<ECinematicInterpType>()
{
	return ECinematicInterpType_StaticEnum();
}
struct Z_Construct_UEnum_CinimaticDirectorRuntime_ECinematicInterpType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Constant.Name", "ECinematicInterpType::Constant" },
		{ "Cubic.Name", "ECinematicInterpType::Cubic" },
		{ "Linear.Name", "ECinematicInterpType::Linear" },
		{ "ModuleRelativePath", "CinematicCreator/CinematicTypes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECinematicInterpType::Linear", (int64)ECinematicInterpType::Linear },
		{ "ECinematicInterpType::Constant", (int64)ECinematicInterpType::Constant },
		{ "ECinematicInterpType::Cubic", (int64)ECinematicInterpType::Cubic },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_CinimaticDirectorRuntime_ECinematicInterpType_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CinimaticDirectorRuntime_ECinematicInterpType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_CinimaticDirectorRuntime,
	nullptr,
	"ECinematicInterpType",
	"ECinematicInterpType",
	Z_Construct_UEnum_CinimaticDirectorRuntime_ECinematicInterpType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_CinimaticDirectorRuntime_ECinematicInterpType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_CinimaticDirectorRuntime_ECinematicInterpType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_CinimaticDirectorRuntime_ECinematicInterpType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_CinimaticDirectorRuntime_ECinematicInterpType()
{
	if (!Z_Registration_Info_UEnum_ECinematicInterpType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECinematicInterpType.InnerSingleton, Z_Construct_UEnum_CinimaticDirectorRuntime_ECinematicInterpType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECinematicInterpType.InnerSingleton;
}
// ********** End Enum ECinematicInterpType ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicTypes_h__Script_CinimaticDirectorRuntime_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ECinematicInterpType_StaticEnum, TEXT("ECinematicInterpType"), &Z_Registration_Info_UEnum_ECinematicInterpType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4291322744U) },
	};
}; // Z_CompiledInDeferFile_FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicTypes_h__Script_CinimaticDirectorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicTypes_h__Script_CinimaticDirectorRuntime_2274161659{
	TEXT("/Script/CinimaticDirectorRuntime"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicTypes_h__Script_CinimaticDirectorRuntime_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicTypes_h__Script_CinimaticDirectorRuntime_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
