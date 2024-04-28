// Copyright Mohsen Sadeghi

#include "Framework/AuraGameMode.h"
#include "Player/AuraPlayerController.h"


AAuraGameMode::AAuraGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PlayerControllerClass = AAuraPlayerController::StaticClass();
}
