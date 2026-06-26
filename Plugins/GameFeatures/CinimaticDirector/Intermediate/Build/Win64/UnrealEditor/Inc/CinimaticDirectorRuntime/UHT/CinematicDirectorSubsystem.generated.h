// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CinematicCreator/CinematicDirectorSubsystem.h"

#ifdef CINIMATICDIRECTORRUNTIME_CinematicDirectorSubsystem_generated_h
#error "CinematicDirectorSubsystem.generated.h already included, missing '#pragma once' in CinematicDirectorSubsystem.h"
#endif
#define CINIMATICDIRECTORRUNTIME_CinematicDirectorSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ALevelSequenceActor;
class UCinematicCreator;

// ********** Begin Class UCinematicDirectorSubsystem **********************************************
#define FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicDirectorSubsystem_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSaveCinematicByIndex); \
	DECLARE_FUNCTION(execPlayCinematicByIndex); \
	DECLARE_FUNCTION(execDestroyCinematic); \
	DECLARE_FUNCTION(execCreateCinematic);


struct Z_Construct_UClass_UCinematicDirectorSubsystem_Statics;
CINIMATICDIRECTORRUNTIME_API UClass* Z_Construct_UClass_UCinematicDirectorSubsystem_NoRegister();

#define FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicDirectorSubsystem_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCinematicDirectorSubsystem(); \
	friend struct ::Z_Construct_UClass_UCinematicDirectorSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CINIMATICDIRECTORRUNTIME_API UClass* ::Z_Construct_UClass_UCinematicDirectorSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UCinematicDirectorSubsystem, UWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CinimaticDirectorRuntime"), Z_Construct_UClass_UCinematicDirectorSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UCinematicDirectorSubsystem)


#define FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicDirectorSubsystem_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCinematicDirectorSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCinematicDirectorSubsystem(UCinematicDirectorSubsystem&&) = delete; \
	UCinematicDirectorSubsystem(const UCinematicDirectorSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCinematicDirectorSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCinematicDirectorSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCinematicDirectorSubsystem) \
	NO_API virtual ~UCinematicDirectorSubsystem();


#define FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicDirectorSubsystem_h_8_PROLOG
#define FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicDirectorSubsystem_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicDirectorSubsystem_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicDirectorSubsystem_h_11_INCLASS_NO_PURE_DECLS \
	FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicDirectorSubsystem_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCinematicDirectorSubsystem;

// ********** End Class UCinematicDirectorSubsystem ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CheckDynCinimatic_Plugins_GameFeatures_CinimaticDirector_Source_CinimaticDirectorRuntime_CinematicCreator_CinematicDirectorSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
