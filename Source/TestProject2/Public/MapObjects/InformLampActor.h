// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseInteractiveActor.h"
#include "Core/InteractionInterface.h"

#include "InformLampActor.generated.h"

class UPointLightComponent;

UCLASS()
class TESTPROJECT2_API AInformLampActor : public ABaseInteractiveActor
{
	GENERATED_BODY()

protected:
	AInformLampActor();

	virtual void Interact(ABaseCharacter* InteractionInstigator) override;

	UPROPERTY(EditAnywhere)
	UPointLightComponent* Lamp;

	UPROPERTY(EditAnywhere)
	float ActiveIntensity = 5000.0f;

	bool bIsActive = false;
};
