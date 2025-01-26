// Fill out your copyright notice in the Description page of Project Settings.


#include "Bollboard_text_Switcher.h"

// Sets default values
ABollboard_text_Switcher::ABollboard_text_Switcher()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	//Create text render
	TextRender = CreateDefaultSubobject<UTextRenderComponent>("TextComponent");
	TextRender->SetTextRenderColor(FColor::Black);

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");

	RootComponent = SceneComponent;

	TextRender->SetupAttachment(SceneComponent);

}

void ABollboard_text_Switcher::BeginPlay()
{
	Super::BeginPlay();
	if (ListOFOneLiners.IsValidIndex(0))
	{
		TextRender->SetText(FText::FromString(ListOFOneLiners[0]));
		
	}
	//Starts timer, currently set to fire the function once after 3s
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ABollboard_text_Switcher::ChangeTextOnTextRender, Timer, true, 1.5f);
}

void ABollboard_text_Switcher::ChangeTextOnTextRender()
{
	if (pos == ListOFOneLiners.Num()-1)
	{
		pos = 0;
	}
	pos += 1;

	TextRender->SetText(FText::FromString(ListOFOneLiners[pos]));
	 
}



