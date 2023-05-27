// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCheckBox.h"
#include "SIAiTypes.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
*/
DECLARE_DELEGATE_OneParam(FChangeCulture, const ECultureTeam)

class MYSIAICOURSE_API SSIAiGameOptionWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSIAiGameOptionWidget)
	{}
	SLATE_EVENT(FChangeCulture, ChangeCulture)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	void ZhCheckBoxStateChanged(ECheckBoxState NewState);
	void EnCheckBoxStateChanged(ECheckBoxState NewState);
	void StyleInitialize();

private:
	FChangeCulture ChangeCulture;
	
private:
	const struct FSIAiMenuStyle* MenuStyle;
	TSharedPtr<SCheckBox> EnCheckBox;
	TSharedPtr<SCheckBox> ZhCheckBox;
};
