// All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ControllableVehiclesTarget : TargetRules
{
	public ControllableVehiclesTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "ControllableVehicles" } );
	}
}
