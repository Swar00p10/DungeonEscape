// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}	

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	/* Overlap and other triggers are triggered only if the functions are binded like below */
	if (IsTriggerPlate)
	{
		OnComponentBeginOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapBegin);
		OnComponentEndOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapEnd);
	}
	if (Door) // Make sure Door is assigned
	{
		Mover = Door->FindComponentByClass<UMover>();
		
		UE_LOG(LogTemp, Display, TEXT("Moving component	found..."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No moving component	"));
	}
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

// Move the assigned actor when overlap begins or ends
void UTriggerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OverlappingActorsCount++;
	if(Mover && OtherActor->ActorHasTag("CanTriggerDoor"))
	Mover->ShouldMove = true;
}

void UTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	OverlappingActorsCount--;
	if(Mover && OtherActor->ActorHasTag("CanTriggerDoor") && (OverlappingActorsCount == 0))
	Mover->ShouldMove = false;
}
