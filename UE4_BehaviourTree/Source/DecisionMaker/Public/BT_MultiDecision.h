// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BT_Decision.h"
#include <vector>
#include "BT_MultiDecision.generated.h"

using namespace std;

/**
 * 
 */
UCLASS()
class DECISIONMAKER_API UBT_MultiDecision : public UBT_Decision
{
	GENERATED_BODY()
	
public:
	vector<UBT_Node> daughterNodes;

protected:
	UBT_Node* GetBranch() override;
};
