// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

	//called everyframe
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{

		MoveToActor(PlayerTank, AcceptanceRadius);
		//TODO move toward the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		//TODO fire when ready
		ControlledTank->Fire(); //TODO limit firing rate
	}
		
}