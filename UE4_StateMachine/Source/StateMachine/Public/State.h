// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
#include "UObject/NoExportTypes.h"
#include "State.generated.h"

class UTransition;

using namespace std;

/**
 * 
 */
UCLASS()
class STATEMACHINE_API UState : public UObject
{
	GENERATED_BODY()

public:
	void AddTransition(UTransition* transition);

	UState* GetAction();
	//UState* GetEntryAction();
	//UState* GetExitAction();

	vector<UTransition*> GetTransitions();

private:
	vector<UTransition*> transitions;
};
