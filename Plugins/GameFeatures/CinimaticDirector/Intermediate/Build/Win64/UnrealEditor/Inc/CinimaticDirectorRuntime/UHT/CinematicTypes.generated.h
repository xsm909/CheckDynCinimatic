// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CinematicCreator/CinematicTypes.h"

#ifdef CINIMATICDIRECTORRUNTIME_CinematicTypes_generated_h
#error "CinematicTypes.generated.h already included, missing '#pragma once' in CinematicTypes.h"
#endif
#define CINIMATICDIRECTORRUNTIME_CinematicTypes_generated_h

#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/NoDestroy.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicTypes_h

// ********** Begin Enum ECinematicInterpType ******************************************************
#define FOREACH_ENUM_ECINEMATICINTERPTYPE(op) \
	op(ECinematicInterpType::Linear) \
	op(ECinematicInterpType::Constant) \
	op(ECinematicInterpType::Cubic) 

enum class ECinematicInterpType : uint8;
template<> struct TIsUEnumClass<ECinematicInterpType> { enum { Value = true }; };
template<> CINIMATICDIRECTORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<ECinematicInterpType>();
// ********** End Enum ECinematicInterpType ********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
