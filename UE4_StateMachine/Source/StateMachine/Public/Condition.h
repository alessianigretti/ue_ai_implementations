// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Condition.generated.h"

/**
 * 
 */
UCLASS()
class STATEMACHINE_API UCondition : public UObject
{
	GENERATED_BODY()
	
public:
	bool Test();
};
