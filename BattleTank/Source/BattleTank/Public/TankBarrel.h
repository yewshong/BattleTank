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
	//-1 is max downward speed, +1 is max upward speed
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category= Setup)
		float MaxDegreesPerSecond = 10;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = 0;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 40;
};