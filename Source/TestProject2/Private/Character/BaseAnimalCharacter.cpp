// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseAnimalCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "NavigationSystem.h"
#include "Character/BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "NavFilters/NavigationQueryFilter.h"

ABaseAnimalCharacter::ABaseAnimalCharacter()
{
}

void ABaseAnimalCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseAnimalCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {

		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ThisClass::GetOffFromHorse);

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
	}
}

void ABaseAnimalCharacter::Interact(ABaseCharacter* InteractionInstigator)
{
	CurrentInstigatorCharacter = InteractionInstigator;

	InteractionInstigator->GetMovementComponent()->Deactivate();
	InteractionInstigator->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), "SpineSocket");
	InteractionInstigator->SetActorEnableCollision(false);
	GetWorld()->GetFirstPlayerController()->Possess(this);
}

void ABaseAnimalCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ABaseAnimalCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ABaseAnimalCharacter::GetOffFromHorse()
{
	if(GetCharacterMovement()->IsFalling())
	{
		return;
	}

	CurrentInstigatorCharacter->GetMovementComponent()->Activate();
	CurrentInstigatorCharacter->DetachFromActor(FDetachmentTransformRules(EDetachmentRule::KeepWorld, true));
	CurrentInstigatorCharacter->SetActorEnableCollision(true);
	GetWorld()->GetFirstPlayerController()->Possess(CurrentInstigatorCharacter);
	GetMovementComponent()->Velocity = FVector(0.0f);

	// Find  Random location to character 
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());

	if (NavSys)
	{
		ANavigationData* UseNavData = NavSys->GetDefaultNavDataInstance(FNavigationSystem::DontCreate);

		if (UseNavData)
		{
			FNavLocation RandomPoint(GetActorLocation());

			if (NavSys->GetRandomPointInNavigableRadius(GetActorLocation(), 200.0f, RandomPoint, UseNavData, UNavigationQueryFilter::GetQueryFilter(*UseNavData, this, nullptr)))
			{
				CurrentInstigatorCharacter->SetActorLocation(RandomPoint);
			}
		}
	}

	CurrentInstigatorCharacter = nullptr;
}
