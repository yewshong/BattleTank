// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;//forward Declaration

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	ATank*  GetControlledTank() const;

	virtual void BeginPlay() override;
	
	ATank* GetPlayerTank() const;

	virtual void Tick(float DeltaSeconds) override;

};
