// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DeclarativeSyntaxSupport.h"
#include "SEditorViewportToolBarMenu.h"
#include "Widgets/SCompoundWidget.h"
#include "SIAiTypes.h"

DECLARE_DELEGATE_OneParam(FItemClicked, const EMenuItem::Type)
/**
 * 
 */
class MYSIAICOURSE_API SSIAiMenuItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSIAiMenuItemWidget)
	{}
	SLATE_ATTRIBUTE(FText,ItemText)
	SLATE_ATTRIBUTE(EMenuItem::Type, ItemType)
	SLATE_EVENT(FItemClicked, OnClicked)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	virtual  void OnMouseLeave(const FPointerEvent& MouseEvent) override;

private:
	FSlateColor GetTintColor() const;
	
private:
	FItemClicked OnClicked;
	EMenuItem::Type ItemType;
	const struct FSIAiMenuStyle* MenuStyle;
	bool IsMouseButtonDown;
};
