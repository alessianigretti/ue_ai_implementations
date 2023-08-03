// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BT_Node.h"
#include "BT_Action.generated.h"

/**
 * 
 */
UCLASS()
class DECISIONMAKER_API UBT_Action : public UBT_Node
{
	GENERATED_BODY()

protected:
	virtual UBT_Node* MakeDecision() override;
};
