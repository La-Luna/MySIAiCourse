// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MYSIAICOURSE_API SIAiInternation
{
public:
	static void Register(FText Value)
	{
		return;
	}
};

#define LOCTEXT_NAMESPACE "SIAiMenu"
//在SIAimenu域下的本地化key value
	SIAiInternation::Register(LOCTEXT("Menu","Menu"));
	SIAiInternation::Register(LOCTEXT("StartGame","StartGame"));
	SIAiInternation::Register(LOCTEXT("GameOption","GameOption"));
	SIAiInternation::Register(LOCTEXT("QuitGame","QuitGame"));
	SIAiInternation::Register(LOCTEXT("NewGame","NewGame"));
	SIAiInternation::Register(LOCTEXT("LoadRecord","LoadRecord"));
	SIAiInternation::Register(LOCTEXT("ChooseRecord","ChooseRecord"));
	SIAiInternation::Register(LOCTEXT("RecordName","RecordName"));
	SIAiInternation::Register(LOCTEXT("EnterGame","EnterGame"));
	SIAiInternation::Register(LOCTEXT("EnterRecord","EnterRecord"));
	SIAiInternation::Register(LOCTEXT("RecordNameHint","Input Record Name!"));
	SIAiInternation::Register (LOCTEXT("NameRepeatedHint","Record Name Repeated!"));
	SIAiInternation::Register(LOCTEXT("Chinese","Chinease"));
	SIAiInternation::Register(LOCTEXT("English","English"));
	SIAiInternation::Register(LOCTEXT("Music","Music"));
	SIAiInternation::Register(LOCTEXT("Sound","Sound"));
	SIAiInternation::Register(LOCTEXT("GoBack","Goback"));
	


#undef LOCTEXT_NAMESPACE