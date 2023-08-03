// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BT_Action.h"
#include "BT_AttackAction.generated.h"

/**
 * 
 */
UCLASS()
class DECISIONMAKER_API UBT_AttackAction : public UBT_Action
{
	GENERATED_BODY()

protected:
	virtual UBT_Node* MakeDecision() override;
};