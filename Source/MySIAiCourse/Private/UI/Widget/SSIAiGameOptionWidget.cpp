// Fill out your copyright notice in the Description page of Project Settings.

#include "SSIAiGameOptionWidget.h"

#include "DeclarativeSyntaxSupport.h"
#include "SBox.h"
#include "SIAiDataHandle.h"
#include "SlateOptMacros.h"
#include "SIAiStyle.h"
#include "SIAiMenuWidgetStyle.h"
#include "SImage.h"
#include "SOverlay.h"
#include "STextBlock.h"
#include "VerticalBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSIAiGameOptionWidget::Construct(const FArguments& InArgs)
{
	ChangeCulture = InArgs._ChangeCulture;
	ChangeVolume = InArgs._ChangeVolume;
	MenuStyle = &SIAiStyle::Get().GetWidgetStyle<FSIAiMenuStyle>("BPSIAiMenuStyle");
	ChildSlot[
		SNew(SBox)
		.WidthOverride(500.f)
		.HeightOverride(300.f)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage).Image(&MenuStyle->GameOptionBGBrush)
			]
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(FMargin(50.f))
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.FillHeight(1.f)
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					.FillWidth(1.f)
					[
						SAssignNew(ZhCheckBox,SCheckBox)
						.OnCheckStateChanged(this,&SSIAiGameOptionWidget::ZhCheckBoxStateChanged)
						[
							SNew(STextBlock)
							.Font(MenuStyle->Font_40)
							.Text(NSLOCTEXT("SIAiMenu","Chinese","Chinese"))
							.ColorAndOpacity(MenuStyle->FontColor_Black)
						]
					]
					+SHorizontalBox::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					.FillWidth(1.f)
					[
						SAssignNew(EnCheckBox,SCheckBox)
						.OnCheckStateChanged(this,&SSIAiGameOptionWidget::EnCheckBoxStateChanged)
						[
							SNew(STextBlock)
							.Font(MenuStyle->Font_40)
							.Text(NSLOCTEXT("SIAiMenu","English","English"))
							.ColorAndOpacity(MenuStyle->FontColor_Black)
						]
					]
				]
				+SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.FillHeight(1.f)
				[
					SNew(SOverlay)
					+ SOverlay::Slot().HAlign(HAlign_Left).VAlign(VAlign_Center)
					[
						SNew(STextBlock).Font(MenuStyle->Font_40).ColorAndOpacity(MenuStyle->FontColor_Black).Text(NSLOCTEXT("SlAiMenu", "Music", "Music"))
					]
					+ SOverlay::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)
					[
						SNew(SBox).WidthOverride(240.f)
						[
							SNew(SOverlay)
							+ SOverlay::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Center).Padding(FMargin(30.f, 0.f))
							[
								SNew(SImage).Image(&MenuStyle->SliderBarBrush)
							]
							+ SOverlay::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Center)   
							[
								SAssignNew(MuSlider, SSlider).Style(&MenuStyle->SliderStyle).OnValueChanged(this, &SSIAiGameOptionWidget::MusicSliderChanged)
							]
						]
					]
					+ SOverlay::Slot().HAlign(HAlign_Right).VAlign(VAlign_Center)
					[
						SAssignNew(MuTextBlock, STextBlock).Font(MenuStyle->Font_40).ColorAndOpacity(MenuStyle->FontColor_Black)
					]	
						
				]
				+SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.FillHeight(1.f)
				[
					SNew(SOverlay)
					+ SOverlay::Slot().HAlign(HAlign_Left).VAlign(VAlign_Center)
					[
					SNew(STextBlock).Font(MenuStyle->Font_40).ColorAndOpacity(MenuStyle->FontColor_Black).Text(NSLOCTEXT("SlAiMenu", "Sound", "Sound"))
					]
					+ SOverlay::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)
					[
					SNew(SBox).WidthOverride(240.f)
					[
						SNew(SOverlay)
						+ SOverlay::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Center).Padding(FMargin(30.f, 0.f))
						[
							SNew(SImage).Image(&MenuStyle->SliderBarBrush)
						]
						+ SOverlay::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Center)
						[
							SAssignNew(SoSlider, SSlider).Style(&MenuStyle->SliderStyle).OnValueChanged(this, &SSIAiGameOptionWidget::SoundSliderChanged)
						]
					
					]
					]
					+ SOverlay::Slot().HAlign(HAlign_Right).VAlign(VAlign_Center)
					[
					SAssignNew(SoTextBlock, STextBlock).Font(MenuStyle->Font_40).ColorAndOpacity(MenuStyle->FontColor_Black)
					]
				]
			]
			
		]
		
	];
	StyleInitialize();
}

void SSIAiGameOptionWidget::ZhCheckBoxStateChanged(ECheckBoxState NewState)
{
	EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	ZhCheckBox->SetIsChecked(ECheckBoxState::Checked);
	ChangeCulture.ExecuteIfBound(ECultureTeam::ZH);	
}

void SSIAiGameOptionWidget::EnCheckBoxStateChanged(ECheckBoxState NewState)
{
	//设置被选中的框
	EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
	ZhCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	//告诉数据控制类转换为中文
	ChangeCulture.ExecuteIfBound(ECultureTeam::EN);
}

void SSIAiGameOptionWidget::StyleInitialize()
{
	////设置ZhCheckBox样式
	ZhCheckBox->SetUncheckedImage(&MenuStyle->UnCheckedBoxBrush);
	ZhCheckBox->SetUncheckedHoveredImage(&MenuStyle->UnCheckedBoxBrush);
	ZhCheckBox->SetUncheckedPressedImage(&MenuStyle->UnCheckedBoxBrush);
	ZhCheckBox->SetCheckedImage(&MenuStyle->CheckedBoxBrush);
	ZhCheckBox->SetCheckedHoveredImage(&MenuStyle->CheckedBoxBrush);
	ZhCheckBox->SetCheckedPressedImage(&MenuStyle->CheckedBoxBrush);

	//设置EnCheckBox样式
	EnCheckBox->SetUncheckedImage(&MenuStyle->UnCheckedBoxBrush);
	EnCheckBox->SetUncheckedHoveredImage(&MenuStyle->UnCheckedBoxBrush);
	EnCheckBox->SetUncheckedPressedImage(&MenuStyle->UnCheckedBoxBrush);
	EnCheckBox->SetCheckedImage(&MenuStyle->CheckedBoxBrush);
	EnCheckBox->SetCheckedHoveredImage(&MenuStyle->CheckedBoxBrush);
	EnCheckBox->SetCheckedPressedImage(&MenuStyle->CheckedBoxBrush);

	switch(SIAiDataHandle::Get()->CurrentCulture) 
	{
	case ECultureTeam::EN:
		EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
		ZhCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
		break;
	case ECultureTeam::ZH:
		EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
		ZhCheckBox->SetIsChecked(ECheckBoxState::Checked);
		break;
	}

	MuSlider->SetValue(SIAiDataHandle::Get()->MusicVolume);
	SoSlider->SetValue(SIAiDataHandle::Get()->SoundVolume);

	MuTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(SIAiDataHandle::Get()->MusicVolume*100))+FString("%")));
	SoTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(SIAiDataHandle::Get()->SoundVolume*100))+FString("%")));
}

void SSIAiGameOptionWidget::MusicSliderChanged(float Value)
{
	//显示百分比
	MuTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(Value * 100)) + FString("%")));
	//修改音量
	//SlAiDataHandle::Get()->ResetMenuVolume(Value, -1.0f);
	ChangeVolume.ExecuteIfBound(Value, -1.0f);
}

void SSIAiGameOptionWidget::SoundSliderChanged(float Value)
{
	//显示百分比
	SoTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(Value * 100)) + FString("%")));
	//修改音量
	//SlAiDataHandle::Get()->ResetMenuVolume(-1.0f,Value);
	ChangeVolume.ExecuteIfBound(-1.0f, Value);
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
