// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerCar.h"
#include "Components/SceneComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AMyPlayerCar::AMyPlayerCar()  // Make sure this matches the header
{
	PrimaryActorTick.bCanEverTick = true;

	// Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	// RootComponent = Root;

	CarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CarMesh"));
	CarMesh->SetupAttachment(RootComponent);
	CarMesh->SetRelativeLocation(FVector(0, 0, 0));
	
	SpringArm1 = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm1"));
	SpringArm1->SetupAttachment(RootComponent);
	SpringArm1->SetRelativeLocation(FVector(0, 0, 0));
	
	Camera1 = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera1"));
	Camera1->SetupAttachment(SpringArm1);

	SpringArm2 = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm2"));
	SpringArm2->SetupAttachment(RootComponent);
	SpringArm2->SetRelativeLocation(FVector(0, 0, 0));
	
	Camera2 = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera2"));
	Camera2->SetupAttachment(SpringArm2);

	SpringArm1->TargetArmLength = 300.f;
	SpringArm1->bEnableCameraLag = true;
	SpringArm1->CameraLagSpeed = 3.0f;

	SpringArm2->TargetArmLength = 300.f;
	SpringArm2->bEnableCameraLag = true;
	SpringArm2->CameraLagSpeed = 3.0f;
}


// Begin play event
void AMyPlayerCar::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("MyPlayerCar has spawned and BeginPlay() was called."));

	// Setting camera active
	Camera1->SetActive(false);
	Camera2->SetActive(true);
	bIsUsingCamera1 = false;
}


// Event tick
void AMyPlayerCar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Switching camera
void AMyPlayerCar::CameraSwitch()
{
	if (bIsUsingCamera1)
	{
		Camera1->SetActive(false);
		Camera2->SetActive(true);
		//UE_LOG(LogTemp, Warning, TEXT("Camera2"));
		bIsUsingCamera1=false;
	}
	else 
	{
		Camera2->SetActive(false);
		Camera1->SetActive(true);
		//UE_LOG(LogTemp, Warning, TEXT("Camera1"));
		bIsUsingCamera1=true;
	}
}

void AMyPlayerCar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Direct key binding (no need for input mappings)
	PlayerInputComponent->BindKey(EKeys::V, IE_Pressed, this, &AMyPlayerCar::CameraSwitch);
}