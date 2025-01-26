// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Actor.h"
#include "Bollboard_text_Switcher.generated.h"

UCLASS()
class BEYOND_THE_BUBBLE_API ABollboard_text_Switcher : public AActor
{
	GENERATED_BODY()

private:
	//For control over timer, start and end.
	UPROPERTY()
	FTimerHandle TimerHandle;

public:	
	// Sets default values for this actor's properties
	ABollboard_text_Switcher();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//Text Render
	UTextRenderComponent* TextRender;
	USceneComponent* SceneComponent;
	
	
	UPROPERTY(EditAnywhere)
	TArray<FString> ListOFOneLiners;

	
	/**
	 * Changes text on the Text Renderer, text comes from an array
	 */
	void ChangeTextOnTextRender();

	//Time for timer
	UPROPERTY(EditAnywhere)
	float Timer = 3.0f;

	UPROPERTY()
	int pos = 0;

};
