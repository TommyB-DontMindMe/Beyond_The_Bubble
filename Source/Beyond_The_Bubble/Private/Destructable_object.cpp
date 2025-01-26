// Fill out your copyright notice in the Description page of Project Settings.


#include "Destructable_object.h"

#include "Beyond_The_Bubble/Beyond_The_BubbleCharacter.h"

// Sets default values
ADestructable_object::ADestructable_object()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADestructable_object::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestructable_object::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADestructable_object::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	//Checks if the player is overlapping
	if (ABeyond_The_BubbleCharacter* PlayerCharacter = Cast<ABeyond_The_BubbleCharacter>(OtherActor))
	{
		PlayerCharacter->bAtBreakableObject = true;
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Error in casting to playercharacter"))
	}
}

void ADestructable_object::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	//Checks if the player is not overlapping
	if (ABeyond_The_BubbleCharacter* PlayerCharacter = Cast<ABeyond_The_BubbleCharacter>(OtherActor))
	{
		PlayerCharacter->bAtBreakableObject = false;
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Error in casting to playercharacter"))
	}
}

