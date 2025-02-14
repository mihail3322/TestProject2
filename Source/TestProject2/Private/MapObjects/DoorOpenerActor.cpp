// Fill out your copyright notice in the Description page of Project Settings.


#include "MapObjects/DoorOpenerActor.h"

ADoorOpenerActor::ADoorOpenerActor()
{
}

void ADoorOpenerActor::BeginPlay()
{
	Super::BeginPlay();
}

void ADoorOpenerActor::Interact(ABaseCharacter* InteractionInstigator)
{
	if(DoorActor && !UpdateDoorPositionTimer.IsValid())
	{
		GetWorld()->GetTimerManager().SetTimer(UpdateDoorPositionTimer, this, &ThisClass::UpdateDoorPosition, 0.02f, true);

		//Calculate max Z position in the world
		DoorHighestPoint += DoorActor->GetActorLocation().Z;
	}
}

void ADoorOpenerActor::UpdateDoorPosition()
{
	if(!DoorActor)
	{
		return;
	}

	DoorActor->AddActorLocalOffset(FVector(0.0f, 0.0f, SpeedRate));

	if(DoorActor->GetActorLocation().Z >= DoorHighestPoint)
	{
		GetWorld()->GetTimerManager().ClearTimer(UpdateDoorPositionTimer);
	}
}
