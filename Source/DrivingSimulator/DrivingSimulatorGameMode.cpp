// Copyright Epic Games, Inc. All Rights Reserved.

#include "DrivingSimulatorGameMode.h"
#include "DrivingSimulatorPlayerController.h"

ADrivingSimulatorGameMode::ADrivingSimulatorGameMode()
{
	PlayerControllerClass = ADrivingSimulatorPlayerController::StaticClass();
}
