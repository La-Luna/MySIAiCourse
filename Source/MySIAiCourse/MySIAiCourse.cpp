// Fill out your copyright notice in the Description page of Project Settings.

#include "MySIAiCourse.h"
#include "Modules/ModuleManager.h"
#include "SIAiStyle.h"
#include "SlateStyleRegistry.h"

IMPLEMENT_PRIMARY_GAME_MODULE(FSIAiCourseModule, MySIAiCourse, "MySIAiCourse");

void FSIAiCourseModule::StartupModule()
{
	//FDefaultModuleImpl::StartupModule();
	FSlateStyleRegistry::UnRegisterSlateStyle(SIAiStyle::GetStyleSetName());
	SIAiStyle::Initialize();
}

void FSIAiCourseModule::ShutdownModule()
{
	//FDefaultModuleImpl::ShutdownModule();
	SIAiStyle::ShutDown();
}

