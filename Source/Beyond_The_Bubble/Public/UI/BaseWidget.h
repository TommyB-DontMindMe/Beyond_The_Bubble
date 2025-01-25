// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseWidget.generated.h"

class UCanvasPanel;
/**
 * 
 */
UCLASS()
class BEYOND_THE_BUBBLE_API UBaseWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* ScreenDisplay;

	UPROPERTY(meta = (BindWidget))
	UNamedSlot* DialogueBox;

public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	UUserWidget* DisplayDialogue(TSubclassOf<UUserWidget> NewWidgetClass);
	
};
