// Fill out your copyright notice in the Description page of Project Settings.


#include "Destructable_Glass.h"

// Sets default values
ADestructable_Glass::ADestructable_Glass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetSimulatePhysics(true); // Enable physics simulation
	RootComponent = MeshComponent;
	
}

UStaticMeshComponent* ADestructable_Glass::GetStaticMeshComponent() const
{
	return MeshComponent;
}




