// Copyright 2022 Danial Kamali. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseComponent.h"
#include "HealthComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CONTROLLABLEVEHICLES_API UHealthComponent : public UBaseComponent
{
	GENERATED_BODY()

// Functions
public:
	UHealthComponent();
	
	/** Only start when stamina is full */
	UFUNCTION(BlueprintCallable, Category = "HealthComponent")
	void StartHealthRecovery();

	/** Stop when stamina is not full */
	UFUNCTION(BlueprintCallable, Category = "HealthComponent")
	void StopHealthRecovery();
	
	UFUNCTION(BlueprintCallable, Category = "HealthComponent")
	void Healing(float HealthDifference);

protected:
	virtual void SetupComponent() override;

private:
	UFUNCTION()
	void TakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION()
	void TakePointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection, const UDamageType* DamageType, AActor* DamageCauser);

	UFUNCTION()
	void TakeRadialDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, FVector Origin, FHitResult HitInfo, AController* InstigatedBy, AActor* DamageCauser);

	void UpdateHealthOnDamage(float Damage, FName BoneName, FVector ShotFromDirection);

	UFUNCTION()
	void RecoverHealth();

// Variables
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Defaults")
	uint8 bCanRecoverHealth : 1;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Defaults", meta = (ClampMin = "0.0", UIMin = "0.0"))
	float MaxHealth = 100.0f;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Defaults", meta = (ClampMin = "0.0", UIMin = "0.0"))
	float DefaultHealth = 100.0f;
	
	UPROPERTY(BlueprintReadOnly, Category = "HealthComponent")
	FName HitBoneName = TEXT("None");

	/** Direction of the shot */
	UPROPERTY(BlueprintReadOnly, Category = "HealthComponent")
	FVector ShotOrigin = FVector::ZeroVector;
	
private:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Defaults", meta = (ToolTip = "If health goes lower than this value health component start notifying the owner", ClampMin = "0.0", UIMin = "0.0", AllowPrivateAccess = true))
	float LowHealth = 25.0f;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Defaults", meta = (ClampMin = "0.0", UIMin = "0.0", AllowPrivateAccess = true))
	float HealingAmount = 10.0f;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Defaults", meta = (ToolTip = "Per Second", ClampMin = "0.0", UIMin = "0.0", AllowPrivateAccess = true))
	float HealthRecoveryRate = 0.25f;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Defaults", meta = (ClampMin = "0.0", UIMin = "0.0", AllowPrivateAccess = true))
	float StartHealthRecoveryDelay = 3.0f;
	
	uint8 bCommonInterface : 1, bCharacterInterface : 1;

	/** At begin play Current Health is equal to Default Health */
	float CurrentHealth = 0.0f;
	
	FTimerHandle HealthRecoveryTimer;
};
