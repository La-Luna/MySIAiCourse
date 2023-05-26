// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SIAiTypes.h"
#include "CoreMinimal.h"

/**
 * 
 */
class MYSIAICOURSE_API SIAiDataHandle
{
public:
	SIAiDataHandle();
	static void Initilize();
	static TSharedPtr<SIAiDataHandle> Get();
	void ChangeLocalizationCulture(ECultureTeam Culture);
	
public:
	ECultureTeam CurrentCulture;

private:
	static TSharedRef<SIAiDataHandle> Create();

private:
	static TSharedPtr<SIAiDataHandle> DataInstance;
};
