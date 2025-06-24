#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "BP_StraightRoadActor.generated.h"

UCLASS()
class DRIVINGSIMULATOR_API ABP_StraightRoadActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABP_StraightRoadActor();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* StraightRoad;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	UArrowComponent* LocationRef;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
