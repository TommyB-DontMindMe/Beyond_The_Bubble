// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BB_DialogueBox.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UBB_DialogueBox::NativeConstruct()
{
	Super::NativeConstruct();

	if (CloseButton)
	{
		CloseButton->OnClicked.AddDynamic(this, &UBB_DialogueBox::CloseWidget);
	}
}

void UBB_DialogueBox::SetText(FText NewText)
{
	if (!DisplayedText)
		return;

	DisplayedText->SetText(NewText);
}

void UBB_DialogueBox::CloseWidget()
{
	APlayerController* CurrentPlayer = GetOwningPlayer();
	CurrentPlayer->SetInputMode(FInputModeGameOnly::FInputModeGameOnly());
	CurrentPlayer->SetShowMouseCursor(false);
	RemoveFromParent();
	Destruct();
}
