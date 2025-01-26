// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Destructable_Glass.generated.h"

UCLASS()
class BEYOND_THE_BUBBLE_API ADestructable_Glass : public AActor
{
	GENERATED_BODY()

	
public:	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* MeshComponent;
	// Sets default values for this actor's properties
	ADestructable_Glass();

	// Get mesh component
	UFUNCTION()
	UStaticMeshComponent* GetStaticMeshComponent() const;

};
