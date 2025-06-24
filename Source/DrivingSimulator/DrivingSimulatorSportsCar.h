// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DrivingSimulatorPawn.h"
#include "DrivingSimulatorSportsCar.generated.h"

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class DRIVINGSIMULATOR_API ADrivingSimulatorSportsCar : public ADrivingSimulatorPawn
{
	GENERATED_BODY()
	
public:

	ADrivingSimulatorSportsCar();
};
