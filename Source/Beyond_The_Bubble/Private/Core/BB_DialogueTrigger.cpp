// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/BB_DialogueTrigger.h"
#include "Core/BB_WidgetComponent.h"
#include "UI/BB_DialogueBox.h"
#include "UI/BaseWidget.h"
#include "GameFramework/Character.h"



void UBB_DialogueTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!DisplayWidget)
		return;

	if (UBB_WidgetComponent* WidgetComponent = OtherActor->GetComponentByClass<UBB_WidgetComponent>())
	{
		UUserWidget* WidgetInstance = WidgetComponent->AddDialogueWidget(DisplayWidget);
		if (UBB_DialogueBox* DialogueInstance = Cast<UBB_DialogueBox>(WidgetInstance))
		{
			DialogueInstance->SetText(TextToDisplay);
		}

		if (ACharacter* OtherCharacter = Cast<ACharacter>(OtherActor); APlayerController* ActiveController = OtherCharacter->GetController<APlayerController>())
		{
			ActiveController->SetInputMode(FInputModeGameAndUI::FInputModeGameAndUI());
			ActiveController->SetShowMouseCursor(true);
		}
	}

}

void UBB_DialogueTrigger::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UBB_DialogueTrigger::OnOverlapBegin);
}
