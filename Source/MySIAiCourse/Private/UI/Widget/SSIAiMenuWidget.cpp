// Fill out your copyright notice in the Description page of Project Settings.

#include "SSIAiMenuWidget.h"
#include "SBorder.h"
#include "SlateOptMacros.h"
#include "SIAiStyle.h"
#include "SIAiMenuWidgetStyle.h"
#include "SImage.h"
#include "SOverlay.h"
#include "Internationalization.h"
#include "SIAiDataHandle.h"
#include "SIAiTypes.h"
#include "SSIAiMenuItemWidget.h"
#include "VerticalBox.h"
#include "SIAiHelper.h"
#include "SSIAiGameOptionWidget.h"
#include "SSIAiGameOptionWidget.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSIAiMenuWidget::Construct(const FArguments& InArgs)
{
	MenuStyle = &SIAiStyle::Get().GetWidgetStyle<FSIAiMenuStyle>("BPSIAiMenuStyle");

	FInternationalization::Get().SetCurrentCulture(TEXT("zh"));
	
	ChildSlot
	[
		SAssignNew(RootSizeBox,SBox)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(FMargin(0.f,50.f,0.f,0.f))
			[
				SNew(SImage).Image(&MenuStyle->MenuBackgroundBrush)
			]
			+SOverlay::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			.Padding(FMargin(0.f,25.f,0.f,0.f))
			[
				SNew(SImage).Image(&MenuStyle->LeftIconBrush)
			]
			+SOverlay::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Center)
			.Padding(FMargin(0.f,25.f,0.f,0.f))
			[
				SNew(SImage).Image(&MenuStyle->RightIconBrush)
			]
			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Top)
			[
				SNew(SBox).WidthOverride(400.f).HeightOverride(100.f)
				[
					SNew(SBorder).BorderImage(&MenuStyle->TitleBorderBrush).HAlign(HAlign_Center).VAlign(VAlign_Center)
					[
						SAssignNew(TitleText,STextBlock).Font(SIAiStyle::Get().GetFontStyle("MenuItemFont"))
						.Text(NSLOCTEXT("SIAiMenu","Menu","Menu"))
					]
				]
			]
			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Top)
			.Padding(FMargin(0.f,130.f,0.f,0.f))
			[
				SAssignNew(ContentBox,SVerticalBox)
			]
			
			
		]
	];

	RootSizeBox->SetWidthOverride(600.f);
	RootSizeBox->SetHeightOverride(510.f);

	ContentBox->AddSlot()[
		 /*
		 SNew(SSIAiMenuItemWidget)
		 .ItemText(NSLOCTEXT("SIAiMenu","StartGame","StartGame"))
		 .ItemType(EMenuItem::StartGame)
		 .OnClicked(this,&SSIAiMenuWidget::MenuItemOnclicked)
	*/
		SNew(SSIAiGameOptionWidget).ChangeCulture(this, &SSIAiMenuWidget::ChangeCulture).ChangeVolume(this, &SSIAiMenuWidget::ChangeVolume)

	];
}

void SSIAiMenuWidget::MenuItemOnclicked(EMenuItem::Type ItemType)
{
	//TitleText->SetText(NSLOCTEXT("SIAiMenu","StartGame","StartGame"));
	SIAiHelper::Debug(FString("test"),5.f);
}

void SSIAiMenuWidget::ChangeCulture(ECultureTeam Culture)
{
	SIAiDataHandle::Get()->ChangeLocalizationCulture(Culture);
}

void SSIAiMenuWidget::ChangeVolume(const float MusicVolume, const float SoundVolume)
{
	SIAiDataHandle::Get()->ResetMenuVolume(MusicVolume, SoundVolume);
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
