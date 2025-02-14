// Fill out your copyright notice in the Description page of Project Settings.


#include "MapObjects/InformLampActor.h"

#include "Components/PointLightComponent.h"

AInformLampActor::AInformLampActor()
{
	Lamp = CreateDefaultSubobject<UPointLightComponent>("Lamp");
	Lamp->SetupAttachment(GetRootComponent());
}

void AInformLampActor::Interact(ABaseCharacter* InteractionInstigator)
{
	Lamp->SetIntensity(bIsActive ? 0.0f : ActiveIntensity);
	bIsActive = !bIsActive;
}
