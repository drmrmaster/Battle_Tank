// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIPlayerController cant find Player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIPlayerController found player: %s"), *(PlayerTank->GetName()));
	}
}
	ATank* ATankAIController::GetControlledTank() const
	{
		return Cast<ATank>(GetPawn());
	}
	ATank* ATankAIController::GetPlayerTank() const
	{
		auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
		if (!PlayerPawn) 
		{ 
			return nullptr; 
		}
		return Cast<ATank>(PlayerPawn);
	}

	//called everyframe
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//TODO move toward the player
		
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//TODO fire when ready
	}
		
}