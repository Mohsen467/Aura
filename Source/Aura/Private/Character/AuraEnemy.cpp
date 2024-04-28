// Copyright Mohsen Sadeghi


#include "Character/AuraEnemy.h"

constexpr int32 GCustom_Depth_Red = 250;

AAuraEnemy::AAuraEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAuraEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAuraEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->CustomDepthStencilValue = GCustom_Depth_Red;
	GetWeapon()->SetRenderCustomDepth(true);
	GetWeapon()->CustomDepthStencilValue = GCustom_Depth_Red;
}

void AAuraEnemy::UnhighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	GetMesh()->CustomDepthStencilValue = 0;
	GetWeapon()->SetRenderCustomDepth(false);
	GetWeapon()->CustomDepthStencilValue = 0;
}

