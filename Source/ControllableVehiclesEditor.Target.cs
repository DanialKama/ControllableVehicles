// All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ControllableVehiclesEditorTarget : TargetRules
{
	public ControllableVehiclesEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "ControllableVehicles" } );
	}
}
