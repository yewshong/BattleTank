// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlyerController not possesing a tank"));
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *ControlledTank->GetName());
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("PlyerController ticked"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
	auto pawn = GetPawn();
	if (pawn)
		return Cast<ATank>(GetPawn());
	else
		return nullptr;
}

void ATankPlayerController::AimTowardsCrosshair()
{

	if (!GetControlledTank()) { return; }
	FVector HitLocation;//out parameter
	
	if(GetSightRayHitLocation(HitLocation))
		UE_LOG(LogTemp, Warning, TEXT("Hit Location : %s"), *HitLocation.ToString());
}


bool  ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("World Direction : %s"), *LookDirection.ToString());
	}
	
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector LookDirection) const
{
	FVector CameraWorldLocation;
	this->DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	return true;
}

bool  ATankPlayerController::MyGetSightRayHitLocation(FVector & HitLocation)
{
	FHitResult hitResult;
	FVector playerTankPosition = GetPawn()->GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("playerTankPosition : %s"), *playerTankPosition.ToString());
	FVector End;// = playerTankPosition + (GetPawn()->GetActorRotation().Vector.Normalize() * 5000);

	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	RV_TraceParams.bTraceComplex = true;
	RV_TraceParams.bTraceAsyncScene = true;
	RV_TraceParams.bReturnPhysicalMaterial = false;

	//Re-initialize hit info
	FHitResult RV_Hit(ForceInit);


	GetWorld()->LineTraceSingleByObjectType(hitResult, playerTankPosition, End, ECC_WorldStatic, RV_TraceParams);

	HitLocation = hitResult.ImpactPoint;
	if (hitResult.bBlockingHit)
	{
		return true;
	}
	return false;
}