// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CinimaticDirectorRuntime : ModuleRules
{
	public CinimaticDirectorRuntime(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[]
			{


			}
		);


		PrivateIncludePaths.AddRange(
			new string[]
			{
				// ... add other private include paths required here ...
			}
		);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				
			}
		);

		PrivateDependencyModuleNames.AddRange(new string[] {
			"CoreUObject",
			"Engine",
			"MovieScene",
			"MovieSceneTracks",
			"Slate",
			"SlateCore",
			"LevelSequence",
			"StructUtils",
			"Json",
			"JsonUtilities"
		});

		if (Target.bBuildEditor == true)
		{
			PrivateDependencyModuleNames.AddRange(new string[] {
				"AssetTools",
				"LevelSequenceEditor",
				"UnrealEd" // Если нужно
			});
		}

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);
	}
}
