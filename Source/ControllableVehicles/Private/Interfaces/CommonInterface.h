// Copyright 2022 Danial Kamali. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Enums/CharacterEnums.h"
#include "CommonInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCommonInterface : public UInterface
{
	GENERATED_BODY()
};

class CONTROLLABLEVEHICLES_API ICommonInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CommonInterface", meta = (ToolTip = "Call from player controller to handle interaction on current object"))
	void Interact();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CommonInterface", meta = (ToolTip = "Health component call it"))
	void SetHealthState(EHealthState HealthState);
};
