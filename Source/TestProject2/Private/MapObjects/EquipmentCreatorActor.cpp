// Fill out your copyright notice in the Description page of Project Settings.


#include "MapObjects/EquipmentCreatorActor.h"

#include "Character/BaseCharacter.h"

AEquipmentCreatorActor::AEquipmentCreatorActor()
{

}

void AEquipmentCreatorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEquipmentCreatorActor::Interact(ABaseCharacter* InteractionInstigator)
{
	if(EquipmentClass)
	{
		AActor* EquipmentActor = GetWorld()->SpawnActor<AActor>(EquipmentClass);

		EquipmentActor->AttachToComponent(InteractionInstigator->GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), "EquipmentSocket");
	}
}
