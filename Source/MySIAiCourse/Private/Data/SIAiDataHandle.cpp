// Fill out your copyright notice in the Description page of Project Settings.

#include "SIAiDataHandle.h"

TSharedPtr<SIAiDataHandle> SIAiDataHandle::DataInstance = NULL;
SIAiDataHandle::SIAiDataHandle()
{
	CurrentCulture = ECultureTeam::ZH;
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
}

TSharedRef<SIAiDataHandle> SIAiDataHandle::Create()
{
	TSharedRef<SIAiDataHandle> DataRef = MakeShareable(new SIAiDataHandle());
	return DataRef;
}

