// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseWidget.h"
#include "Components/NamedSlot.h"

UUserWidget* UBaseWidget::DisplayDialogue(TSubclassOf<UUserWidget> NewWidgetClass)
{
    UUserWidget* NewWidget = CreateWidget<UUserWidget>(this, NewWidgetClass);
    DialogueBox->SetContent(NewWidget);

    return NewWidget;
}
