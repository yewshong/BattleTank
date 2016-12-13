// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not possesing a tank"));
	}
	else 
	  UE_LOG(LogTemp, Warning, TEXT("TankAIController possessing: %s"), *ControlledTank->GetName());

	auto playerTank = GetPlayerTank();
	if (!playerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController failed to get a player tank"));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("TankAIController get player tank: %s"), *playerTank->GetName());

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!playerPawn)
	{
		return nullptr;	
	}
	return Cast<ATank>(playerPawn);
}

