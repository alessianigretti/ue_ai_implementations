// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
#include "UObject/NoExportTypes.h"
#include "Transition.generated.h"

class UState;
class UCondition;

using namespace std;

/**
 * 
 */
UCLASS()
class STATEMACHINE_API UTransition : public UObject
{
	GENERATED_BODY()
	
public:
	void SetCondition(UCondition* setCondition);
	void SetTargetState(UState* setTargetState);

	UState* GetAction();
	UState* GetTargetState();
	bool IsTriggered();

private:
	UCondition* condition;
	UState* targetState;
};
