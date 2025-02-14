// Fill out your copyright notice in the Description page of Project Settings.


#include "MapObjects/AnimalCreatorActor.h"

#include "NavigationSystem.h"
#include "Character/BaseAnimalCharacter.h"
#include "Components/ArrowComponent.h"
#include "NavFilters/NavigationQueryFilter.h"

AAnimalCreatorActor::AAnimalCreatorActor()
{
	SpawnPoint = CreateDefaultSubobject<UArrowComponent>("SpawnPoint");
	SpawnPoint->SetupAttachment(GetRootComponent());
}

void AAnimalCreatorActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAnimalCreatorActor::Interact(ABaseCharacter* InteractionInstigator)
{
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
	GetWorld()->SpawnActor<ABaseAnimalCharacter>(BaseHorseCharacterClass, SpawnPoint->GetComponentLocation(), FRotator(0, 0, 0), SpawnParameters);
}
