// Copyright Mohsen Sadeghi

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

	// IAbilitySystemInterface begin
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	// IAbilitySystemInterface end
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
	
	USkeletalMeshComponent* GetWeapon() const { return Weapon; }
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	/** Ability System Component
	 * For Enemy it is implements in EnemyCharacter
	 * For Player it is implements in PlayerState
	 */
	UPROPERTY(VisibleAnywhere, Category = "AbilitySystem")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	/** AttributeSet
	 * For Player it is implements in PlayerState
	 * For Enemy it is implements in EnemyCharacter
	 */
	UPROPERTY(VisibleAnywhere, Category = "AbilitySystem")
	TObjectPtr<UAttributeSet> AttributeSet;
};
