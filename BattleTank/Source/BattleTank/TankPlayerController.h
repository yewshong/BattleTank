// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank*  GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	//adjust the barrel based on crosshair position
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool MyGetSightRayHitLocation(FVector & HitLocation);
};
