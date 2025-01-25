// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/BB_NPC.h"
#include "Components/SceneComponent.h"

// Sets default values
ABB_NPC::ABB_NPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	bShouldMove = true;
	MovementSpeed = 1;
}

// Called when the game starts or when spawned
void ABB_NPC::BeginPlay()
{
	Super::BeginPlay();
	
	if (!NavigationTarget.IsEmpty())
	{
		this->SetActorLocation(NavigationTarget[0]);
		LastIndex = 0;

		if (NavigationTarget.Num() > 1)
		{
			TargetIndex = 1;
			TravelDistance = FVector::Distance(NavigationTarget[LastIndex], NavigationTarget[TargetIndex]);
		}
	}
}

// Called every frame
void ABB_NPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!bShouldMove)
		return;

	if (NavigationTarget.Num() > 1)
	{
		FVector CurrentPosition = FMath::Lerp(NavigationTarget[LastIndex], NavigationTarget[TargetIndex], LerpPosition);
		SetActorLocation(CurrentPosition);

		LerpPosition += (DeltaTime * MovementSpeed) / TravelDistance;
		if (LerpPosition >= 1)
		{
			LerpPosition = 0;
			LastIndex = TargetIndex;
			TargetIndex = NavigationTarget.IsValidIndex(TargetIndex + 1) ? TargetIndex + 1 : 0;

			TravelDistance = FVector::Distance(NavigationTarget[LastIndex], NavigationTarget[TargetIndex]);
		}

	}

}

//void ABB_NPC::AddNavigationTarget()
//{
//	UActorComponent* NewComponent = AddComponentByClass(USceneComponent::StaticClass(), false, FTransform(), false);
//	NewComponent->RegisterComponent();
//	if (USceneComponent* NavTarget = Cast<USceneComponent>(NewComponent))
//	{
//		/*int32 NavIndex =*/ NavigationTarget.Add(NavTarget);
//	}
//}

