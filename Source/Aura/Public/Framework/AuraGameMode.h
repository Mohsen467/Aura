// Copyright Mohsen Sadeghi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "AuraGameMode.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraGameMode : public AGameMode
{
	GENERATED_BODY()

	// constructor
	AAuraGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
};
