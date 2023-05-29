// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "SlateWidgetStyleContainerBase.h"
#include "SlateBrush.h"
#include "SlateFontInfo.h"
#include "SlateTypes.h"

#include "SIAiMenuWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct MYSIAICOURSE_API FSIAiMenuStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FSIAiMenuStyle();
	virtual ~FSIAiMenuStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FSIAiMenuStyle& GetDefault();

	UPROPERTY(EditAnywhere, Category = MenuHUD)
	FSlateBrush MenuHUDBackgroundBNrush;

	UPROPERTY(EditAnywhere, Category = Menu)
	FSlateBrush MenuBackgroundBrush;

	UPROPERTY(EditAnywhere, Category = Menu)
	FSlateBrush LeftIconBrush;

	UPROPERTY(EditAnywhere, Category = Menu)
	FSlateBrush RightIconBrush;

	UPROPERTY(EditAnywhere, Category = Menu)
	FSlateBrush TitleBorderBrush;

	UPROPERTY(EditAnywhere, Category = Menu)
	FSlateBrush MenuItemBrush;

	UPROPERTY(EditAnywhere, Category = Common)
	FSlateFontInfo Font_60;

	UPROPERTY(EditAnywhere, Category = Common)
	FSlateFontInfo Font_40;

	UPROPERTY(EditAnywhere, Category = Common)
	FSlateFontInfo Font_30;

	UPROPERTY(EditAnywhere, Category = GameOption)
	FSlateBrush GameOptionBGBrush;

	UPROPERTY(EditAnywhere, Category = Common)
	FLinearColor FontColor_White;
	
	UPROPERTY(EditAnywhere, Category = Common)
	FLinearColor FontColor_Black;

	UPROPERTY(EditAnywhere, Category = GameOption)
	FSlateBrush CheckedBoxBrush;

	UPROPERTY(EditAnywhere, Category = GameOption)
	FSlateBrush UnCheckedBoxBrush;

	UPROPERTY(EditAnywhere, Category = GameOption)
	FSlateBrush SliderBarBrush;

	UPROPERTY(EditAnywhere, Category = GameOption)
	FSliderStyle SliderStyle;
	
};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class USIAiMenuWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FSIAiMenuStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
