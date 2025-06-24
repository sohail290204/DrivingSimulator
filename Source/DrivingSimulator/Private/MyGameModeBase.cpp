// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "BP_StraightRoadActor.h"
#include "Kismet/GameplayStatics.h"

void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	CreateRoad();
}
void AMyGameModeBase::CreateRoad()
{
	TArray<AActor*> FoundRoads;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABP_StraightRoadActor::StaticClass(), FoundRoads);

	if (FoundRoads.Num() > 0)
	{
		ABP_StraightRoadActor* RoadActor = Cast<ABP_StraightRoadActor>(FoundRoads[0]);
		if (RoadActor)
		{
			//	RoadActor -> LocationRef -> SetWorldLocation();
			
				FVector SpawnLocation = RoadActor->LocationRef->GetComponentLocation();
				FRotator SpawnRotation = RoadActor->LocationRef->GetComponentRotation();

			GetWorld()->SpawnActor<ABP_StraightRoadActor>(RoadActorClass, SpawnLocation, SpawnRotation);
			UE_LOG(LogTemp, Warning, TEXT("Spawned BP_StraightRoadActor!"));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("RoadActorClass is not set!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No BP_StraightRoadActor found in the level."));
	}

}

