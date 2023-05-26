// Fill out your copyright notice in the Description page of Project Settings.

#include "SSIAiMenuItemWidget.h"

#include "SBox.h"
#include "SlateOptMacros.h"
#include "SIAiStyle.h"
#include "SIAiMenuWidgetStyle.h"
#include "SImage.h"
#include "SOverlay.h"
#include "STextBlock.h"
#include "SIAiTypes.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSIAiMenuItemWidget::Construct(const FArguments& InArgs)
{
	OnClicked = InArgs._OnClicked;
	ItemType = InArgs._ItemType.Get();

	MenuStyle = &SIAiStyle::Get().GetWidgetStyle<FSIAiMenuStyle>("BPSIAiMenuStyle");
	IsMouseButtonDown = false;
	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(500.f)
		.HeightOverride(100.f)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.VAlign(VAlign_Fill)
			.HAlign(HAlign_Fill)
			[
				SNew(SImage).Image(&MenuStyle->MenuItemBrush).ColorAndOpacity(this,&SSIAiMenuItemWidget::GetTintColor)
			]
			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock).Text(InArgs._ItemText).Font(MenuStyle->Font_60)
			]
			
		]
		
	];
}

FReply SSIAiMenuItemWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	this->IsMouseButtonDown = true;
	return FReply::Handled();
}

FReply SSIAiMenuItemWidget::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if(IsMouseButtonDown)
	{
		IsMouseButtonDown = false;
		OnClicked.ExecuteIfBound(ItemType);
	}
	return FReply::Handled();
}

void SSIAiMenuItemWidget::OnMouseLeave(const FPointerEvent& MouseEvent)
{
	IsMouseButtonDown = false;
	return;
}

FSlateColor SSIAiMenuItemWidget::GetTintColor() const
{
	if(IsMouseButtonDown)
	{
		return FLinearColor(1.f,0.1f,0.1f,0.5f);
	}
	else
	{
		return FLinearColor(1.f,1.f,1.f,1.f);
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
