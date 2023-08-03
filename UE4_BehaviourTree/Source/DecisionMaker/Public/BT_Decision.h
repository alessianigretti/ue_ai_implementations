// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BT_Node.h"
#include "BT_Decision.generated.h"

/**
 * 
 */
UCLASS()
class DECISIONMAKER_API UBT_Decision : public UBT_Node
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UBT_Node* trueNode;
	
	UPROPERTY()
	UBT_Node* falseNode;
	
	UPROPERTY()
	float testValue;

public:
	virtual UBT_Node* GetBranch();

protected:
	virtual UBT_Node* MakeDecision() override;
};
