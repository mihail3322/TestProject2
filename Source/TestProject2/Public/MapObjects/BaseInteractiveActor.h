// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/InteractionInterface.h"
#include "GameFramework/Actor.h"

#include "BaseInteractiveActor.generated.h"

class UTextRenderComponent;

UCLASS(Abstract)
class TESTPROJECT2_API ABaseInteractiveActor : public AActor, public  IInteractionInterface
{
	GENERATED_BODY()

protected:
	ABaseInteractiveActor();

	UPROPERTY(EditAnywhere)
	UTextRenderComponent* TextRender;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;
};
