// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
template<class T>
class MYSIAICOURSE_API SIAiSingleton
{
public:
	static TSharedPtr<T> Get();
private:
	static void Initialize();
	static TSharedPtr<T> Create();

	static TSharedPtr<T> TInstance;


 
};

template<class T>
TSharedPtr<T> SIAiSingleton<T>::TInstance =  NULL;

template <class T>
TSharedPtr<T> SIAiSingleton<T>::Get()
{
	Initialize();
	return TInstance;
}

template <class T>
void SIAiSingleton<T>::Initialize()
{
	if(!TInstance.IsValid())
	{
		TInstance = Create();
	}
}

template <class T>
TSharedPtr<T> SIAiSingleton<T>::Create()
{
	TSharedPtr<T> TRef = MakeShareable(new T());
	return TRef;
}

