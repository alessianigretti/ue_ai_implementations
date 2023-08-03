// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class StateMachine : ModuleRules
{
	public StateMachine(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
