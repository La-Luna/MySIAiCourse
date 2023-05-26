// Fill out your copyright notice in the Description page of Project Settings.

#include "SIAiMenuHUD.h"

#include "DeclarativeSyntaxSupport.h"
#include "SSIAiMenuHUDWidget.h"
#include "SWeakWidget.h"
#include "Engine/Engine.h"
#include "Engine/GameViewportClient.h"

ASIAiMenuHUD::ASIAiMenuHUD()
{
	if(GEngine && GEngine->GameViewport)
	{
		SAssignNew(MenuHUDWidget,SSIAiMenuHUDWidget);
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MenuHUDWidget.ToSharedRef()));
	}
}
