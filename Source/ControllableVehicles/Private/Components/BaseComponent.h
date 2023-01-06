// Copyright 2022 Danial Kamali. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CONTROLLABLEVEHICLES_API UBaseComponent : public UActorComponent
{
	GENERATED_BODY()

// Functions
public:
	UBaseComponent();
	
	UFUNCTION(BlueprintCallable, Category = "Components")
	void Initialize();

protected:
	virtual void SetupComponent() {}

// Variables
protected:
	TObjectPtr<AActor> Owner;
};
