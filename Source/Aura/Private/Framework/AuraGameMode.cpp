// Copyright Mohsen Sadeghi

#include "Player/AuraPlayerController.h"
#include "Framework/AuraGameMode.h"


AAuraGameMode::AAuraGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PlayerControllerClass = AAuraPlayerController::StaticClass();
}
