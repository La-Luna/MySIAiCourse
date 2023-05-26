// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "SIAiMenuWidgetStyle.h"

/**
 * 
 */
class MYSIAICOURSE_API SSIAiMenuHUDWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSIAiMenuHUDWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	float GetUIScaler() const;
	FVector2D GetViewportSize() const;
	
private:
	const struct FSIAiMenuStyle *MenuStyle;
	TAttribute<float> UIScaler;
	TSharedPtr<class SSIAiMenuWidget> MenuWidget;
};
