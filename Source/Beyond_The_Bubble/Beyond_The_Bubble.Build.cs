// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Beyond_The_Bubble : ModuleRules
{
	public Beyond_The_Bubble(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
