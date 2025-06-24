// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_StraightRoadActor.h"
#include "Components/ArrowComponent.h"   
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ABP_StraightRoadActor::ABP_StraightRoadActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	StraightRoad = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StraightRoad"));
	RootComponent = StraightRoad;

	LocationRef = CreateDefaultSubobject<UArrowComponent>(TEXT("Location"));
	LocationRef->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("")); // Replace with your asset
	if (MeshAsset.Succeeded())
	{
		StraightRoad->SetStaticMesh(MeshAsset.Object);
		//StraightRoad->SetWorldScale3D(FVector(7.0f, 7.0f, 7.0f));
	}
	
}

// Called when the game starts or when spawned
void ABP_StraightRoadActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_StraightRoadActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

