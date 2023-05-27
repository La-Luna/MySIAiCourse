// Fill out your copyright notice in the Description page of Project Settings.

#include "SIAiMenuController.h"


ASIAiMenuController::ASIAiMenuController()
{
	bShowMouseCursor = true;
}

void ASIAiMenuController::BeginPlay()
{
	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputMode);
}
