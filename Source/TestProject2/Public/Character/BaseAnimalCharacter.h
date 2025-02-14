// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/InteractionInterface.h"
#include "GameFramework/Character.h"

#include "BaseAnimalCharacter.generated.h"

class UInputComponent;
class UInputMappingContext;
class UInputAction;
class ABaseCharacter;
struct FInputActionValue;

UCLASS()
class TESTPROJECT2_API ABaseAnimalCharacter : public ACharacter, public  IInteractionInterface
{
	GENERATED_BODY()

public:

protected:
	ABaseAnimalCharacter();
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void Interact(ABaseCharacter* InteractionInstigator) override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void GetOffFromHorse();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY()
	ABaseCharacter* CurrentInstigatorCharacter;
};
