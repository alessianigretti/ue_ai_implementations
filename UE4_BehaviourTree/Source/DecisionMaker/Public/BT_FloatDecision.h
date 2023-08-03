// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BT_Decision.h"
#include "BT_FloatDecision.generated.h"

/**
 * 
 */
UCLASS()
class DECISIONMAKER_API UBT_FloatDecision : public UBT_Decision
{
	GENERATED_BODY()

public:
	float minValue;
	float maxValue;

protected:
	virtual UBT_Node* GetBranch() override;
	virtual UBT_Node* MakeDecision() override;
};
