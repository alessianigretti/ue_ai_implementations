// Fill out your copyright notice in the Description page of Project Settings.


#include "State.h"
#include "Transition.h"
#include "Condition.h"

void UState::AddTransition(UTransition* transition)
{
	transitions.push_back(transition);
}

UState* UState::GetAction()
{
	UState* action = NewObject<UState>();

	UE_LOG(LogTemp, Warning, TEXT("Not triggered action"));
	
	return action;
}

vector<UTransition*> UState::GetTransitions()
{
	return transitions;
}