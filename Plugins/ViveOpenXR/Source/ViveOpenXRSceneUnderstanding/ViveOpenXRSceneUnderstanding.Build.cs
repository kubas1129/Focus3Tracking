// Copyright (c) 2022 HTC Corporation. All Rights Reserved.

using UnrealBuildTool;

public class ViveOpenXRSceneUnderstanding : ModuleRules
{
	public ViveOpenXRSceneUnderstanding(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		//PrivatePCHHeaderFile = @"Private\OpenXRCommon.h";

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"OpenXRHMD",
				"OpenXRInput",
				"OpenXRAR",
				"AugmentedReality",
				"Slate",
				"SlateCore",
				"InputCore",
				"RHI",
				"RenderCore",
				"ViveOpenXRRuntimeSettings"
				// ... add private dependencies that you statically link with here ...	
			}
			);

		AddEngineThirdPartyPrivateStaticDependencies(Target, "OpenXR");
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
