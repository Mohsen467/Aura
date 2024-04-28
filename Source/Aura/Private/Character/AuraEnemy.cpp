// Copyright Mohsen Sadeghi


#include "Character/AuraEnemy.h"


AAuraEnemy::AAuraEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAuraEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bShouldHighlight)
	{
		//DrawDebugSphere on the enemy
		DrawDebugSphere(GetWorld(), GetActorLocation(), 30.f, 12, FColor::Red, false, 0.f, 0, 2.f);
	}
}

void AAuraEnemy::HighlightActor()
{
	bShouldHighlight = true;
}

void AAuraEnemy::UnhighlightActor()
{
	bShouldHighlight = false;
}

