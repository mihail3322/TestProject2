// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestProject2 : ModuleRules
{
	public TestProject2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "NavigationSystem" });
	}
}
