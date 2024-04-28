// Copyright Mohsen Sadeghi

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();
	// tick
	virtual void Tick(float DeltaTime) override;

	// IEnemyInterface begin
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;
	// IEnemyInterface end
};
