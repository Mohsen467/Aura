// Copyright Mohsen Sadeghi


#include "AuraAssetManager.h"
#include "AuraGameplayTags.h"

const UAuraAssetManager& UAuraAssetManager::Get()
{
	return *Cast<UAuraAssetManager>(GEngine->AssetManager);
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FAuraGameplayTags::InitializeNativeGameplayTags();
}
