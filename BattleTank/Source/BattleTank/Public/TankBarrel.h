#pragma once

#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hideCategories =("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category= Setup)
		float MaxDegreesPerSecond = 20;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = 0;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 40;
};