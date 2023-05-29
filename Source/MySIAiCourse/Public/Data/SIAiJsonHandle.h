// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Json.h"
#include "SIAiTypes.h"
/**
 * 
 */
class MYSIAICOURSE_API SIAiJsonHandle
{
public:
	SIAiJsonHandle();
	void RecordDataJsonRead(FString& Culture, float& MusicVolume, float& SoundVolume, TArray<FString>& RecordDataList);

private:
	bool LoadStringFromFile(const FString& FileName,const FString& Relative, FString& ResultString);
	
private:
	FString RecordDataFileName;
	FString RelativePath;
};
