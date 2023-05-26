// Fill out your copyright notice in the Description page of Project Settings.

#include "SIAiMenuGameMode.h"
#include "SIAiMenuController.h"
#include "SIAiMenuHUD.h"


ASIAiMenuGameMode::ASIAiMenuGameMode()
{
	PlayerControllerClass = ASIAiMenuController::StaticClass();
	HUDClass = ASIAiMenuHUD::StaticClass();
}
