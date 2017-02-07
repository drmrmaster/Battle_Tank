// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"//must be last include


class ATank;
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

	UPROPERTY(EditAnywhere) 
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere) 
	float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	
};
