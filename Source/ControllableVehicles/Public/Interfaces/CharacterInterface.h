// All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Enums/CharacterEnums.h"
#include "UObject/Interface.h"
#include "CharacterInterface.generated.h"

class APickup;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCharacterInterface : public UInterface
{
	GENERATED_BODY()
};

class CONTROLLABLEVEHICLES_API ICharacterInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// With Output
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CharacterInterface")
	bool CanUseVehicle();
	
	// Without Output
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CharacterInterface")
	void SetHealthLevel(float Health);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CharacterInterface")
	void SetInteractable(AActor* NewInteractable);
};