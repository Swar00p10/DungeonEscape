// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONESCAPE_API UMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMover();

	FVector StartLocation{}, TargetLocation{}; // Start and Target Locations

	// Properties to adjust the movement in the editor
	UPROPERTY(EditAnywhere, Category = "CustomProperties")
	FVector MoveOffset{0,0,350.0f};

	UPROPERTY(EditAnywhere, Category = "CustomProperties")
	float MoveTime{ 4.f };

	UPROPERTY(EditAnywhere, Category = "CustomProperties")

	bool ShouldMove{ false };

	UPROPERTY(EditAnywhere, Category = "CustomProperties")

	bool TargetReached{ false };


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
