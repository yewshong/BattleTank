// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::RotateTowards(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	//	UE_LOG(LogTemp, Warning, TEXT("Barrel elevates: %f"), RelativeSpeed);
	auto RotationChange = RelativeSpeed *MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));
	//UE_LOG(LogTemp, Warning, TEXT("yaw Rotation :%f"), Rotation);
	//UE_LOG(LogTemp, Warning, TEXT("%f"),RelativeRotation.Yaw);
}


