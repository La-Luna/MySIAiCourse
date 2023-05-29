// Fill out your copyright notice in the Description page of Project Settings.

#include "SIAiDataHandle.h"


#include "SIAiHelper.h"
#include "SIAiJsonHandle.h"
#include "SIAiSingleton.h"

TSharedPtr<SIAiDataHandle> SIAiDataHandle::DataInstance = NULL;
SIAiDataHandle::SIAiDataHandle()
{
	InitRecordData();
	/*CurrentCulture = ECultureTeam::ZH;
	MusicVolume = 0.5f;
	SoundVolume = 0.5f;*/
}

void SIAiDataHandle::Initilize()
{
	if(!DataInstance.IsValid())
	{
		DataInstance = Create();
	}
}

TSharedPtr<SIAiDataHandle> SIAiDataHandle::Get()
{
	Initilize();
	return DataInstance;
}

void SIAiDataHandle::ChangeLocalizationCulture(ECultureTeam Culture)
{
	switch (Culture)
	{
	case ECultureTeam::EN:
		{
			FInternationalization::Get().SetCurrentCulture(TEXT("en"));
			break;			
		}

	case ECultureTeam::ZH:
		{
			FInternationalization::Get().SetCurrentCulture(TEXT("zh"));
			break;
		}

	}
	CurrentCulture = Culture;
	SIAiSingleton<SIAiJsonHandle>::Get()->UpdateRecordData(GetEnumValueAsString<ECultureTeam>(FString("ECultureTeam"), CurrentCulture), MusicVolume, SoundVolume, &RecordDataList);
}

void SIAiDataHandle::ResetMenuVolume(float MusicVol, float SoundVol)
{
	if(MusicVol>0)
	{
		MusicVolume = MusicVol;
	}
	if(SoundVol>0)
	{
		SoundVolume = SoundVol;
	}
	SIAiSingleton<SIAiJsonHandle>::Get()->UpdateRecordData(GetEnumValueAsString<ECultureTeam>(FString("ECultureTeam"), CurrentCulture), MusicVolume, SoundVolume, &RecordDataList);
}


TSharedRef<SIAiDataHandle> SIAiDataHandle::Create()
{
	TSharedRef<SIAiDataHandle> DataRef = MakeShareable(new SIAiDataHandle());
	return DataRef;
}

template <typename TEnum>
FString SIAiDataHandle::GetEnumValueAsString(const FString& Name, TEnum Value)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE,*Name,true);
	if(!EnumPtr)
	{
		return FString("InValid");
	}
	return EnumPtr->GetEnumName((int32)Value);
}

template <typename TEnum>
TEnum SIAiDataHandle::GetEnumValueFromString(const FString& Name, FString Value)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE,*Name,true);
	if(!EnumPtr)
	{
		return TEnum(0);
	}
	return (TEnum)EnumPtr->GetIndexByName(FName(*FString(Value)));
}

void SIAiDataHandle::InitRecordData()
{
	FString Culture;
	SIAiSingleton<SIAiJsonHandle>::Get()->RecordDataJsonRead(Culture,MusicVolume,SoundVolume,RecordDataList);
	ChangeLocalizationCulture(GetEnumValueFromString<ECultureTeam>(FString("ECultureTeam"),Culture));

	/*SIAiHelper::Debug(Culture+FString("--")+FString::SanitizeFloat(MusicVolume)+FString("--")+FString::SanitizeFloat(SoundVolume),20.f);
	for(TArray<FString>::TIterator It(RecordDataList);It;It++)
	{
		SIAiHelper::Debug(*It,20.f);
	}*/

	
}