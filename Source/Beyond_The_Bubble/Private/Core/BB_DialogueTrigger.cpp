// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/BB_DialogueTrigger.h"
#include "Core/BB_WidgetComponent.h"
#include "UI/BaseWidget.h"



void UBB_DialogueTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!DisplayWidget)
		return;

	if (UBB_WidgetComponent* WidgetComponent = OtherActor->GetComponentByClass<UBB_WidgetComponent>())
		WidgetComponent->AddDialogueWidget(DisplayWidget);
}

void UBB_DialogueTrigger::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UBB_DialogueTrigger::OnOverlapBegin);
}
