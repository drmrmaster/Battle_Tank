// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"//must be last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	void Tick(float DeltaSeconds) override;
	void BeginPlay() override;

	ATank* GetControlledTank() const;
	
	// start the tank moving the barrel so that a shot would hit where
	// the crosshair intersects the world

	void AimTowardCrosshair();

	//return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& Hitlocation) const;
};
