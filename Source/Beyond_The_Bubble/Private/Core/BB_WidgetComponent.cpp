// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/BB_WidgetComponent.h"
#include "UI/BaseWidget.h"

// Sets default values for this component's properties
UBB_WidgetComponent::UBB_WidgetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBB_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	if (!CurrentPlayer)
	{
		CurrentPlayer = GetWorld()->GetFirstPlayerController();
	}

	if (!BaseWidgetInstance)
	{
		BaseWidgetInstance = CreateWidget<UBaseWidget>(CurrentPlayer, WidgetBaseClass);
		if (BaseWidgetInstance)
			BaseWidgetInstance->AddToViewport();
	}
	
}


// Called every frame
void UBB_WidgetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UUserWidget* UBB_WidgetComponent::AddDialogueWidget(TSubclassOf<UUserWidget> NewWidget)
{
	if (BaseWidgetInstance)
		return BaseWidgetInstance->DisplayDialogue(NewWidget);

	return nullptr;
}

