// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "InteractionInterface.generated.h"

class ABaseCharacter;

UINTERFACE(MinimalAPI)
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

class TESTPROJECT2_API IInteractionInterface
{
	GENERATED_IINTERFACE_BODY()

public:
	virtual void Interact(ABaseCharacter* InteractionInstigator);
};