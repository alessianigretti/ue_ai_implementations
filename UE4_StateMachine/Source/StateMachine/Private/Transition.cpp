// Fill out your copyright notice in the Description page of Project Settings.


#include "Transition.h"
#include "Condition.h"

void UTransition::SetCondition(UCondition* setCondition)
{
	condition = setCondition;
}

void UTransition::SetTargetState(UState* setTargetState)
{
	targetState = setTargetState;
}

UState* UTransition::GetAction()
{
	if (IsTriggered())
	{
		UE_LOG(LogTemp, Warning, TEXT("Triggered Action"));

		return targetState;
	}
	else
	{
		// TODO
		return nullptr;
	}
}

UState* UTransition::GetTargetState()
{
	return targetState;
}

bool UTransition::IsTriggered()
{
	return condition->Test();
}