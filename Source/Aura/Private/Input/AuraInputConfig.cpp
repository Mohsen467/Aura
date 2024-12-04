// Copyright Mohsen Sadeghi


#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag,
	const bool bLogNotFound) const
{
	// for (const FAuraInputAction& Action: AbilityInputActions)
	// {
	// 	if (Action.InputAction && Action.InputTag == InputTag)
	// 	{
	// 		return Action.InputAction;
	// 	}
	// }
	// if (bLogNotFound)
	// {
	// 	UE_LOG(LogTemp, Error, TEXT("Can't find AbilityInputAction for InputTag [%s], on InputConfig [%s]"), *InputTag.ToString(), *GetNameSafe(this));
	// }
	// return nullptr;
	
	const FAuraInputAction* InputAction = AbilityInputActions.FindByPredicate([&](const FAuraInputAction& Action)
	{
		return Action.InputTag.MatchesTagExact(InputTag);
	});

	if (InputAction)
	{
		return InputAction->InputAction;
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ability Input Action for tag %s was not found"), *InputTag.ToString());
	}
	return nullptr;
}
