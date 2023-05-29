// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCheckBox.h"
#include "SIAiTypes.h"
#include "SSlider.h"
#include "STextBlock.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
*/
DECLARE_DELEGATE_OneParam(FChangeCulture, const ECultureTeam)
DECLARE_DELEGATE_TwoParams(FChangeVolume, const float, const float)

class MYSIAICOURSE_API SSIAiGameOptionWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSIAiGameOptionWidget)
	{}
	SLATE_EVENT(FChangeCulture, ChangeCulture)
	SLATE_EVENT(FChangeVolume, ChangeVolume)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	void ZhCheckBoxStateChanged(ECheckBoxState NewState);
	void EnCheckBoxStateChanged(ECheckBoxState NewState);
	void StyleInitialize();
	void MusicSliderChanged(float Value);
	void SoundSliderChanged(float Value);
	
private:
	FChangeCulture ChangeCulture;
	FChangeVolume ChangeVolume;
	
private:
	const struct FSIAiMenuStyle* MenuStyle;
	TSharedPtr<SCheckBox> EnCheckBox;
	TSharedPtr<SCheckBox> ZhCheckBox;
	TSharedPtr<SSlider> MuSlider;//背景音乐
	TSharedPtr<SSlider> SoSlider;//音效
	TSharedPtr<STextBlock> MuTextBlock;
	TSharedPtr<STextBlock> SoTextBlock;
};
