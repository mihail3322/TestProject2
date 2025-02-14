// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseInteractiveActor.h"

#include "EquipmentCreatorActor.generated.h"

UCLASS()
class TESTPROJECT2_API AEquipmentCreatorActor : public ABaseInteractiveActor
{
	GENERATED_BODY()

protected:
	AEquipmentCreatorActor();
	virtual void BeginPlay() override;
	virtual void Interact(ABaseCharacter* InteractionInstigator) override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> EquipmentClass;
};
