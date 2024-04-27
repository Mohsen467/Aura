// Copyright Mohsen Sadeghi

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter();

	// spring arm
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	class USpringArmComponent* SpringArmComponent;

	// Camera
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* CameraComponent;
protected:
	virtual void BeginPlay() override;

	
};
