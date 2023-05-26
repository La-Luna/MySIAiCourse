// Fill out your copyright notice in the Description page of Project Settings.

#include "SSIAiMenuHUDWidget.h"
#include "SSIAiMenuWidget.h"
#include "SlateOptMacros.h"
#include "SButton.h"
#include "SImage.h"
#include "SIAiStyle.h"
#include "SOverlay.h"
#include "Engine/Engine.h"
#include "Engine/GameViewportClient.h"
#include "SDPIScaler.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSIAiMenuHUDWidget::Construct(const FArguments& InArgs)
{
	MenuStyle = &SIAiStyle::Get().GetWidgetStyle<FSIAiMenuStyle>("BPSIAiMenuStyle");

	UIScaler.Bind(this,&SSIAiMenuHUDWidget::GetUIScaler);
	
	ChildSlot
	[
		SNew(SDPIScaler)
		.DPIScale(UIScaler)
		[
			SNew(SOverlay)
			+SOverlay::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Fill).Padding(FMargin(30.F))//padding-margin表示上下左右的空隙
			[
				SNew(SImage).Image(&MenuStyle->MenuHUDBackgroundBNrush)
			]
			+SOverlay::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)
			[
				//SNew(SImage).Image(&MenuStyle->MenuBackgroundBrush)
				SAssignNew(MenuWidget,SSIAiMenuWidget)
			]

		]
	];
}

float SSIAiMenuHUDWidget::GetUIScaler() const
{
	return GetViewportSize().Y/2160.f;
}

FVector2D SSIAiMenuHUDWidget::GetViewportSize() const
{
	FVector2D Result(3840,2160);
	if(GEngine && GEngine->GameViewport)
		GEngine->GameViewport->GetViewportSize(Result);
	return Result;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
