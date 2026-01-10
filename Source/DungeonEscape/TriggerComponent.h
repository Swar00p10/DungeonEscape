// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Mover.h"
#include "TriggerComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), Meta= (BlueprintSpawnableComponent) )

class DUNGEONESCAPE_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	UTriggerComponent();
	// The door that this trigger will operate
	UPROPERTY(EditAnywhere)
	AActor* Door = nullptr;

	UMover* Mover = nullptr;

	// Is this component functioning as a trigger plate
	UPROPERTY(EditAnywhere)
	bool IsTriggerPlate = false;

	// Count of overlapping actors
	UPROPERTY(VisibleAnywhere)
	int32 OverlappingActorsCount = 0;
	
private:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Overlap event handlers
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);	

};
