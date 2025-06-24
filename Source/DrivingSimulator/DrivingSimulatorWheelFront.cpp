// Copyright Epic Games, Inc. All Rights Reserved.

#include "DrivingSimulatorWheelFront.h"
#include "UObject/ConstructorHelpers.h"

UDrivingSimulatorWheelFront::UDrivingSimulatorWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	MaxSteerAngle = 40.f;
}