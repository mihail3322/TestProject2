// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseInteractiveActor.h"
#include "Core/InteractionInterface.h"

#include "AnimalCreatorActor.generated.h"

class ABaseAnimalCharacter;
class UArrowComponent;

UCLASS()
class TESTPROJECT2_API AAnimalCreatorActor : public ABaseInteractiveActor
{
	GENERATED_BODY()

protected:
	AAnimalCreatorActor();
	virtual void BeginPlay() override;
	virtual void Interact(ABaseCharacter* InteractionInstigator) override;

	UPROPERTY(EditAnywhere)
	UArrowComponent* SpawnPoint;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABaseAnimalCharacter> BaseHorseCharacterClass;
};
