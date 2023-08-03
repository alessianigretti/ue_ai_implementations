// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BT_Node.generated.h"

/**
 * 
 */
UCLASS()
class DECISIONMAKER_API UBT_Node : public UObject
{
	GENERATED_BODY()

public:
	virtual UBT_Node* MakeDecision();
};
