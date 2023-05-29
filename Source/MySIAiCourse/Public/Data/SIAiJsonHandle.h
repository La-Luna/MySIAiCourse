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
	void UpdateRecordData(FString Culture, float MusicVolume, float SoundVolume, TArray<FString>* RecordDataList);
	
private:
	bool LoadStringFromFile(const FString& FileName,const FString& Relative, FString& ResultString);
	bool GetFStringInJsonData(const TSharedPtr<FJsonObject>& JsonObj, FString& JsonStr);
	bool WriteFileWithJsonData(const FString& JsonStr, const FString& RelaPath, const FString& FileName);
	
private:
	FString RecordDataFileName;
	FString RelativePath;
};
