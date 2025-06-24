// Copyright Epic Games, Inc. All Rights Reserved.

#include "DrivingSimulatorWheelRear.h"
#include "UObject/ConstructorHelpers.h"

UDrivingSimulatorWheelRear::UDrivingSimulatorWheelRear()
{
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}