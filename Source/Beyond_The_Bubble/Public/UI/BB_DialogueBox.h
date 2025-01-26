// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BB_DialogueBox.generated.h"

class UButton;
class UTextBlock;

/**
 * 
 */
UCLASS()
class BEYOND_THE_BUBBLE_API UBB_DialogueBox : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* DisplayedText;
	
	UPROPERTY(meta = (BindWidget))
	UButton* CloseButton;

public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "UI")
	void SetText(FText NewText);

	UFUNCTION()
	void CloseWidget();
};
