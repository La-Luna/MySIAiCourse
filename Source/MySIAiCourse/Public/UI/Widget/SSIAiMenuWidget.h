// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SBox.h"
#include "SIAiTypes.h"
#include "STextBlock.h"

class STextBlock;
class SBox;
class SVerticalBox;

/**
 * 
 */
class MYSIAICOURSE_API SSIAiMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSIAiMenuWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	void MenuItemOnclicked(EMenuItem::Type ItemType);
	void ChangeCulture(ECultureTeam Culture);
private:
	TSharedPtr<SBox> RootSizeBox;
	const struct FSIAiMenuStyle *MenuStyle;
	TSharedPtr<STextBlock> TitleText;
	TSharedPtr<SVerticalBox> ContentBox;
};
