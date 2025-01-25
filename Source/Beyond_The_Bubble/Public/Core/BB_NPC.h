// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BB_NPC.generated.h"

UCLASS()
class BEYOND_THE_BUBBLE_API ABB_NPC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABB_NPC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "AI")
	TArray<FVector> NavigationTarget;

	UPROPERTY(EditAnywhere, Category = "AI")
	bool bShouldMove;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementSpeed;

	UPROPERTY()
	float LerpPosition;
	UPROPERTY()
	float TravelDistance;
	UPROPERTY()
	int LastIndex;
	UPROPERTY()
	int TargetIndex;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	/*UFUNCTION(CallInEditor, Category = "AI")
	void AddNavigationTarget();*/
};
