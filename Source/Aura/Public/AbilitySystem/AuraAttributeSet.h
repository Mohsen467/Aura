// Copyright Mohsen Sadeghi

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "AuraAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties() {};

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceAsc{nullptr};

	UPROPERTY()
	AActor* SourceAvatarActor{nullptr};

	UPROPERTY()
	AController* SourceController{nullptr};

	UPROPERTY()
	ACharacter* SourceCharacter{nullptr};
	
	UPROPERTY()
	UAbilitySystemComponent* TargetAsc{nullptr};

	UPROPERTY()
	AActor* TargetAvatarActor{nullptr};

	UPROPERTY()
	AController* TargetController{nullptr};

	UPROPERTY()
	ACharacter* TargetCharacter{nullptr};
};

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
    UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// PreAttributesChange
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	/**
	 * Primary Attributes
	 */
	
	UPROPERTY(BlueprintReadOnly, Category = "Primary Attributes", ReplicatedUsing = OnRep_Strength)
		FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Strength)

	UPROPERTY(BlueprintReadOnly, Category = "Primary Attributes", ReplicatedUsing = OnRep_Intelligence)
		FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Intelligence)

	UPROPERTY(BlueprintReadOnly, Category = "Primary Attributes", ReplicatedUsing = OnRep_Resilience)
		FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Resilience)

	UPROPERTY(BlueprintReadOnly, Category = "Primary Attributes", ReplicatedUsing = OnRep_Vigor)
		FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Vigor)

	/**
	 * Secondary Attributes
	 */

	// Reduces damage taken, improves block chance
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attributes", ReplicatedUsing = OnRep_Armor)
		FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Armor)

	// Ignores percentage of enemy armor, increases critical hit chance
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attributes", ReplicatedUsing = OnRep_ArmorPenetration)
		FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ArmorPenetration)

	// chance to cut incoming damage in half
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attributes", ReplicatedUsing = OnRep_BlockChance)
		FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, BlockChance)
	
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attributes", ReplicatedUsing = OnRep_CriticalHitChance)
		FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitChance)

	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attributes", ReplicatedUsing = OnRep_CriticalHitDamage)
		FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitDamage)

	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attributes", ReplicatedUsing = OnRep_CriticalHitResistance)
		FGameplayAttributeData CriticalHitResistance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitResistance)

	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attributes", ReplicatedUsing = OnRep_HealthRegeneration)
		FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, HealthRegeneration)

	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attributes", ReplicatedUsing = OnRep_ManaRegeneration)
		FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ManaRegeneration)

	/*
	 * Vital Attributes
	 */
	
	UPROPERTY( BlueprintReadOnly, Category = "Vital Attributes", ReplicatedUsing = OnRep_Health)
		FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health)
	
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes", ReplicatedUsing = OnRep_MaxHealth)
		FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth)
	
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes", ReplicatedUsing = OnRep_Mana)
		FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana)
	
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes", ReplicatedUsing = OnRep_MaxMana)
		FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana)

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;

	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;


	/**
	 * Secondary Attributes on replication
	 */

	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;

	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const;

	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;

	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;

	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const;

	UFUNCTION()
	void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance) const;

	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const;

	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration) const;
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};
