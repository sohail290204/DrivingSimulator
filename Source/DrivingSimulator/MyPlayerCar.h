// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "MyPlayerCar.generated.h"

class USpringArmComponent;
class UCameraComponent;
/**
 * 
 */
UCLASS()
class DRIVINGSIMULATOR_API AMyPlayerCar : public AWheeledVehiclePawn
{
	GENERATED_BODY()

public:
	AMyPlayerCar(); // Declaration of constructor

protected:
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
public:
	virtual void Tick(float DeltaTime) override;
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// UPROPERTY(VisibleAnywhere)
	// USceneComponent* Root;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	class USpringArmComponent* SpringArm1;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	class UCameraComponent* Camera1;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	class USpringArmComponent* SpringArm2;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	class UCameraComponent* Camera2;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UMeshComponent* CarMesh;

	//UFUNCTION(BlueprintImplementableEvent, Category = "CameraSwitch")
	void CameraSwitch();

	UFUNCTION(BlueprintCallable, Category="CAMERASWITCH")
	void cameraswitchfunction();
	
	// for flip flop
	bool bIsUsingCamera1;
};
