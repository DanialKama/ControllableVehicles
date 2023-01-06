// Copyright 2022 Danial Kamali. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Enums/CharacterEnums.h"
#include "UObject/Interface.h"
#include "CharacterAnimationInterface.generated.h"

class APickup;
class APickupWeapon;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCharacterAnimationInterface : public UInterface
{
	GENERATED_BODY()
};

class CONTROLLABLEVEHICLES_API ICharacterAnimationInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CharacterAnimationInterface", meta = (ToolTip = "True when character is dead and mesh is not moving anymore"))
	void SetCompletelyStopMoving(bool bCompletelyStop);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CharacterAnimationInterface")
	void SetInVehicleState(bool bInVehicle, EInVehicleState InVehicleState);
};
