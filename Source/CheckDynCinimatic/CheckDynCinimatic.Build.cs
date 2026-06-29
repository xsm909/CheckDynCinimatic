// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CheckDynCinimatic : ModuleRules
{
	public CheckDynCinimatic(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"NavigationSystem",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"Niagara",
			"UMG",
			"Slate",
			"LevelSequence",
			"MovieScene",
			"MovieSceneTracks",
			"MotionWarping",
			// "AssetTools" и "LevelSequenceEditor" УДАЛЕНЫ отсюда
		});


		if (Target.bBuildEditor == true)
		{
			PublicDependencyModuleNames.AddRange(new string[] {
				"AssetTools",
				"LevelSequenceEditor",
				"UnrealEd"
			});
		}
		
		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"CheckDynCinimatic",
			"CheckDynCinimatic/Variant_Strategy",
			"CheckDynCinimatic/Variant_Strategy/UI",
			"CheckDynCinimatic/Variant_TwinStick",
			"CheckDynCinimatic/Variant_TwinStick/AI",
			"CheckDynCinimatic/Variant_TwinStick/Gameplay",
			"CheckDynCinimatic/Variant_TwinStick/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
