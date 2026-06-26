// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CinematicCreator/CinematicCreator.h"

#ifdef CINIMATICDIRECTORRUNTIME_CinematicCreator_generated_h
#error "CinematicCreator.generated.h already included, missing '#pragma once' in CinematicCreator.h"
#endif
#define CINIMATICDIRECTORRUNTIME_CinematicCreator_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UClass;
class ULevelSequence;
enum class ECinematicInterpType : uint8;

// ********** Begin Class UCinematicCreator ********************************************************
#define FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicCreator_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetSequence); \
	DECLARE_FUNCTION(execFlushChanges); \
	DECLARE_FUNCTION(execAddTransformKey); \
	DECLARE_FUNCTION(execSetCinematicDuration); \
	DECLARE_FUNCTION(execRegisterSpawnableActor); \
	DECLARE_FUNCTION(execRegisterPossessableActor);


struct Z_Construct_UClass_UCinematicCreator_Statics;
CINIMATICDIRECTORRUNTIME_API UClass* Z_Construct_UClass_UCinematicCreator_NoRegister();

#define FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicCreator_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCinematicCreator(); \
	friend struct ::Z_Construct_UClass_UCinematicCreator_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CINIMATICDIRECTORRUNTIME_API UClass* ::Z_Construct_UClass_UCinematicCreator_NoRegister(); \
public: \
	DECLARE_CLASS2(UCinematicCreator, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CinimaticDirectorRuntime"), Z_Construct_UClass_UCinematicCreator_NoRegister) \
	DECLARE_SERIALIZER(UCinematicCreator)


#define FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicCreator_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCinematicCreator(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCinematicCreator(UCinematicCreator&&) = delete; \
	UCinematicCreator(const UCinematicCreator&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCinematicCreator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCinematicCreator); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCinematicCreator) \
	NO_API virtual ~UCinematicCreator();


#define FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicCreator_h_8_PROLOG
#define FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicCreator_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicCreator_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicCreator_h_11_INCLASS_NO_PURE_DECLS \
	FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicCreator_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCinematicCreator;

// ********** End Class UCinematicCreator **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicCreator_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
