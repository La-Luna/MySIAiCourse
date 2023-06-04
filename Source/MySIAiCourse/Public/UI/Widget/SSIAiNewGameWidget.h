// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SEditableTextBox;
/**
 * 
 */
class MYSIAICOURSE_API SSIAiNewGameWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSIAiNewGameWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


private:
	const struct FSIAiMenuStyle *MenuStyle;
	TSharedPtr<SEditableTextBox> EditTextBox;
	
};
