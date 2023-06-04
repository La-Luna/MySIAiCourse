// Fill out your copyright notice in the Description page of Project Settings.

#include "SSIAiNewGameWidget.h"
#include "SlateOptMacros.h"
#include "SBox.h"
#include "STextBlock.h"
#include "SOverlay.h"
#include "SEditableTextBox.h"

#include "SIAiStyle.h"
#include "SIAiMenuWidgetStyle.h"
#include "SIAiDataHandle.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSIAiNewGameWidget::Construct(const FArguments& InArgs)
{
	MenuStyle = &SIAiStyle::Get().GetWidgetStyle<FSIAiMenuStyle>("BPSIAiMenuStyle");

	ChildSlot
		[
			SNew(SBox).WidthOverride(500.f).HeightOverride(100.f)
			[
				SNew(SOverlay)
				+ SOverlay::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Fill)
					[
						SNew(SImage).Image(&MenuStyle->MenuItemBrush)
					]
				+ SOverlay::Slot().HAlign(HAlign_Left).VAlign(VAlign_Center).Padding(FMargin(20.f, 0.f, 0.f, 0.f))
					[
						SNew(STextBlock).Font(MenuStyle->Font_40).Text(NSLOCTEXT("SlAiMenu", "NewGame", "NewGame"))
					]
				+ SOverlay::Slot().HAlign(HAlign_Right).VAlign(VAlign_Center).Padding(FMargin(0.f, 0.f, 20.f, 0.f))
					[
						SNew(SBox).WidthOverride(300.f).HeightOverride(60.f)
						[
							SAssignNew(EditTextBox, SEditableTextBox).HintText(NSLOCTEXT("SlAiMenu", "RecordNameHint", "Input Record Name!")).Font(MenuStyle->Font_30)
						]
					]


			]

		];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
