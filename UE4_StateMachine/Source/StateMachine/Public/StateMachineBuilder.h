// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
#include "UObject/NoExportTypes.h"
#include "StateMachineBuilder.generated.h"

class UState;

using namespace std;

/**
 * 
 */
UCLASS()
class STATEMACHINE_API UStateMachineBuilder : public UObject
{
	GENERATED_BODY()

public:
	void Build();
	vector<UState*> MoveNext();

private:
	UState* currentState;
};
