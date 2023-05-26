// Fill out your copyright notice in the Description page of Project Settings.

#include "SIAiMenuWidgetStyle.h"


FSIAiMenuStyle::FSIAiMenuStyle()
{
}

FSIAiMenuStyle::~FSIAiMenuStyle()
{
}

const FName FSIAiMenuStyle::TypeName(TEXT("FSIAiMenuStyle"));

const FSIAiMenuStyle& FSIAiMenuStyle::GetDefault()
{
	static FSIAiMenuStyle Default;
	return Default;
}

void FSIAiMenuStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

