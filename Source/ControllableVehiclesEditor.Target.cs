// Copyright 2022 Danial Kamali. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ControllableVehiclesEditorTarget : TargetRules
{
	public ControllableVehiclesEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest; 
		
		ExtraModuleNames.AddRange( new string[] { "ControllableVehicles" } );
	}
}
