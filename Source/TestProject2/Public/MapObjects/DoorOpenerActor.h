// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseInteractiveActor.h"

#include "DoorOpenerActor.generated.h"

UCLASS()
class TESTPROJECT2_API ADoorOpenerActor : public ABaseInteractiveActor
{
	GENERATED_BODY()

protected:
	ADoorOpenerActor();
	virtual void BeginPlay() override;
	virtual void Interact(ABaseCharacter* InteractionInstigator) override;

	UFUNCTION()
	void UpdateDoorPosition();

	UPROPERTY(EditInstanceOnly, Category= "Door Settings")
	AActor* DoorActor;

	UPROPERTY(EditAnywhere, Category = "Door Settings")
	float DoorHighestPoint = 500.0f;

	UPROPERTY(EditAnywhere, Category = "Door Settings")
	float SpeedRate = 2.0f;

	FTimerHandle UpdateDoorPositionTimer;
};
