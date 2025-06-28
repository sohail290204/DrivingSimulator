// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "Kismet/GameplayStatics.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DRIVINGSIMULATOR_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	void CreateRoad(); // Declare here
	
};
