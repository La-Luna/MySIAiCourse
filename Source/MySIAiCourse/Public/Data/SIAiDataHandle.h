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
	void ResetMenuVolume(float MusicVol, float SoundVol);
	
public:
	ECultureTeam CurrentCulture;
	float MusicVolume;
	float SoundVolume;
	TArray<FString> RecordDataList;

private:
	static TSharedRef<SIAiDataHandle> Create();
	template<typename TEnum>
	FString GetEnumValueAsString(const FString& Name,TEnum Value);
	template<typename TEnum>
	TEnum GetEnumValueFromString(const FString& Name, FString Value);
	void InitRecordData();
	
private:
	static TSharedPtr<SIAiDataHandle> DataInstance;
};


