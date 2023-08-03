// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BT_Node.h"
#include <vector>
#include "UObject/NoExportTypes.h"
#include "BT_TreeBuilder.generated.h"

using namespace std;

/**
 * 
 */
UCLASS()
class DECISIONMAKER_API UBT_TreeBuilder : public UObject
{
	GENERATED_BODY()
	
public:
	vector<UBT_Node*> nodes;

	void BuildTree(float input);
	void Run();
};
