// Fill out your copyright notice in the Description page of Project Settings.

#include "SIAiJsonHandle.h"

#include "SIAiHelper.h"

SIAiJsonHandle::SIAiJsonHandle()
{
	this->RelativePath = FString("Res/ConfigData/");
	this->RecordDataFileName = FString("RecordData.json");
}

void SIAiJsonHandle::RecordDataJsonRead(FString& Culture, float& MusicVolume, float& SoundVolume,
	TArray<FString>& RecordDataList)
{
	FString JsonValue;
	LoadStringFromFile(RecordDataFileName,RelativePath,JsonValue);

	TArray<TSharedPtr<FJsonValue>> JsonParsed;
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonValue);

	if(FJsonSerializer::Deserialize(JsonReader,JsonParsed))
	{
		Culture = JsonParsed[0]->AsObject()->GetStringField(FString("Culture"));
		MusicVolume = JsonParsed[1]->AsObject()->GetNumberField(FString("MusicVolume"));
		SoundVolume = JsonParsed[2]->AsObject()->GetNumberField(FString("SoundVolume"));
		TArray<TSharedPtr<FJsonValue>> RecordDataArray = JsonParsed[3]->AsObject()->GetArrayField(FString("RecordData"));
		for (int i = 0; i < RecordDataArray.Num(); ++i)
		{
			FString RecordDataName = RecordDataArray[i]->AsObject()->GetStringField(FString::FromInt(i));
			RecordDataList.Add(RecordDataName);
		}
	}
	else
	{
		SIAiHelper::Debug(FString("Deserialize Failed"));
	}
	
}

bool SIAiJsonHandle::LoadStringFromFile(const FString& FileName, const FString& Relative, FString& ResultString)
{
	if(!FileName.IsEmpty())
	{
		FString AbsoPath = FPaths::ProjectContentDir() + RelativePath + FileName;
		if(FPaths::FileExists(AbsoPath))
		{
			if(FFileHelper::LoadFileToString(ResultString, *AbsoPath))
			{
				return true;
			}
			else
			{
				SIAiHelper::Debug(FString("Load Error")+ AbsoPath);
			}
		}
		else
		{
			SIAiHelper::Debug(FString("File Not Exist")+ AbsoPath);
		}
	}
	return false;
}


