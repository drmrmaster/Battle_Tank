// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void  UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount the frame
	//Given a max elevation speed, and the frame time 
	UE_LOG(LogTemp, Warning, TEXT("Barrel-Elevate() called called at speed %f"), RelativeSpeed);
}

