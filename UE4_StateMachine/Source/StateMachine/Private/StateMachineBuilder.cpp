// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachineBuilder.h"
#include "Condition.h"
#include "Transition.h"
#include "State.h"

void UStateMachineBuilder::Build()
{
	UCondition* seeSmallEnemy = NewObject<UCondition>();
	UCondition* seeBigEnemy = NewObject<UCondition>();
	UCondition* losingFight = NewObject<UCondition>();
	UCondition* escaped = NewObject<UCondition>();

	UTransition* seeSmallEnemyT = NewObject<UTransition>();
	UTransition* seeBigEnemyT = NewObject<UTransition>();
	UTransition* losingFightT = NewObject<UTransition>();
	UTransition* escapedT = NewObject<UTransition>();
	
	UState* onGuardState = NewObject<UState>();
	UState* fightState = NewObject<UState>();
	UState* runAwayState = NewObject<UState>();

	// Set up transitions
	seeSmallEnemyT->SetCondition(seeSmallEnemy);
	seeSmallEnemyT->SetTargetState(fightState);

	losingFightT->SetCondition(losingFight);
	losingFightT->SetTargetState(runAwayState);

	escapedT->SetCondition(escaped);
	escapedT->SetTargetState(onGuardState);

	seeBigEnemyT->SetCondition(seeBigEnemy);
	seeBigEnemyT->SetTargetState(runAwayState);

	// Set up states
	onGuardState->AddTransition(seeSmallEnemyT);
	onGuardState->AddTransition(seeBigEnemyT);

	fightState->AddTransition(losingFightT);

	runAwayState->AddTransition(escapedT);

	currentState = onGuardState;
}

vector<UState*> UStateMachineBuilder::MoveNext()
{
	UTransition* triggeredTransition = nullptr;
	vector<UState*> actions;

	for (UTransition* transition : currentState->GetTransitions())
	{
		if (transition->IsTriggered())
		{
			triggeredTransition = transition;
			break;
		}
	}

	if (triggeredTransition)
	{
		UState* targetState = triggeredTransition->GetTargetState();

		//actions.push_back(currentState->GetExitAction());
		actions.push_back(triggeredTransition->GetAction());
		//actions.push_back(targetState->GetEntryAction());

		currentState = targetState;
	}
	else
	{
		actions.push_back(currentState->GetAction());
	}

	return actions;
}