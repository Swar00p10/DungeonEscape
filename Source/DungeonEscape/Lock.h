// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
// Add the headers for the components to be used
#include "TriggerComponent.h"
#include "Components/StaticMeshComponent.h"

#include "Lock.generated.h"

UCLASS()
class DUNGEONESCAPE_API ALock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnyWhere)
	USceneComponent* RootComp;

	UPROPERTY(VisibleAnywhere)
	UTriggerComponent* TriggerComp;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* KeyItemMesh;

	UPROPERTY(EditAnywhere);
	FString KeyItemName;

private:
	bool IsKeyPlaced = true;
public:
	void SetIsKeyPlaced(bool);
	bool GetIsKeyPlaced() const;
};
