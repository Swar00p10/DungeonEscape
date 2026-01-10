// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	// ...
	// Initialize StartLocation and TargetLocation
	StartLocation = GetOwner()->GetActorLocation();
	TargetLocation = StartLocation + MoveOffset;

	//UE_LOG(LogTemp, Display, TEXT("Mover reporting for duty for %s and StartLocation = %s "), *GetOwner()->GetActorNameOrLabel(), *(GetOwner()->GetActorLocation()).ToCompactString());

}


// Called every frame

// Move the actor towards TargetLocation or back to StartLocation based on ShouldMove flag
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	float speed = MoveOffset.Length() / MoveTime;

	if (ShouldMove)
	{
		TargetLocation = StartLocation + MoveOffset;	
	}
	else
	{			
		TargetLocation = StartLocation;
	}
	TargetReached = GetOwner()->GetActorLocation().Equals(TargetLocation, 1.f);
	if (!TargetReached)
	{
		GetOwner()->SetActorLocation(FMath::VInterpConstantTo(GetOwner()->GetActorLocation(), TargetLocation, DeltaTime, speed));
		UE_LOG(LogTemp, Display, TEXT("Mover moving "));
	}
}

	