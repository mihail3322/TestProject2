// Fill out your copyright notice in the Description page of Project Settings.

#include "MapObjects/BaseInteractiveActor.h"

#include "Components/TextRenderComponent.h"

ABaseInteractiveActor::ABaseInteractiveActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	TextRender = CreateDefaultSubobject<UTextRenderComponent>("TextRender");

	SetRootComponent(Mesh);
	TextRender->SetupAttachment(Mesh);
	TextRender->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	TextRender->SetWorldSize(50.0f);
}
