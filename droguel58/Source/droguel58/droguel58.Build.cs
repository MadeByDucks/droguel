// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class droguel58 : ModuleRules
{
	public droguel58(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"droguel58",
			"droguel58/Droguel",
			"droguel58/Variant_Platforming",
			"droguel58/Variant_Platforming/Animation",
			"droguel58/Variant_Combat",
			"droguel58/Variant_Combat/AI",
			"droguel58/Variant_Combat/Animation",
			"droguel58/Variant_Combat/Gameplay",
			"droguel58/Variant_Combat/Interfaces",
			"droguel58/Variant_Combat/UI",
			"droguel58/Variant_SideScrolling",
			"droguel58/Variant_SideScrolling/AI",
			"droguel58/Variant_SideScrolling/Gameplay",
			"droguel58/Variant_SideScrolling/Interfaces",
			"droguel58/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
