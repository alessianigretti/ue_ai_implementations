// Fill out your copyright notice in the Description page of Project Settings.


#include "PathGraph.h"

void UPathGraph::Build()
{
	// Set up nodes
	FPathNode* nodeA = new FPathNode;
	nodeA->Name = "A (Start)";

	FPathNode* nodeB = new FPathNode;
	nodeB->Name = "B";

	FPathNode* nodeC = new FPathNode;
	nodeC->Name = "C";

	FPathNode* nodeD = new FPathNode;
	nodeD->Name = "D";

	FPathNode* nodeE = new FPathNode;
	nodeE->Name = "E";

	FPathNode* nodeF = new FPathNode;
	nodeF->Name = "F";

	FPathNode* nodeG = new FPathNode;
	nodeG->Name = "G (Goal)";

	// Set up edges
	FPathEdge* edgeAB = new FPathEdge;
	edgeAB->FromNode = nodeA;
	edgeAB->ToNode = nodeB;
	edgeAB->TraversalCost = 1.3f;

	FPathEdge* edgeBD = new FPathEdge;
	edgeBD->FromNode = nodeB;
	edgeBD->ToNode = nodeD;
	edgeBD->TraversalCost = 1.5f;

	FPathEdge* edgeAC = new FPathEdge;
	edgeAC->FromNode = nodeA;
	edgeAC->ToNode = nodeC;
	edgeAC->TraversalCost = 1.1f;

	FPathEdge* edgeBE = new FPathEdge;
	edgeBE->FromNode = nodeB;
	edgeBE->ToNode = nodeE;
	edgeBE->TraversalCost = 1.7f;

	FPathEdge* edgeCE = new FPathEdge;
	edgeCE->FromNode = nodeC;
	edgeCE->ToNode = nodeE;
	edgeCE->TraversalCost = 1.5f;

	FPathEdge* edgeCF = new FPathEdge;
	edgeCF->FromNode = nodeC;
	edgeCF->ToNode = nodeF;
	edgeCF->TraversalCost = 1.7f;

	FPathEdge* edgeEG = new FPathEdge;
	edgeEG->FromNode = nodeE;
	edgeEG->ToNode = nodeG;
	edgeEG->TraversalCost = 1.4f;

	// Set up node edges
	nodeA->Edges.Add(edgeAB);
	nodeA->Edges.Add(edgeAC);

	nodeB->Edges.Add(edgeBD);
	nodeB->Edges.Add(edgeBE);

	nodeC->Edges.Add(edgeCE);
	nodeC->Edges.Add(edgeCF);

	nodeD->Edges.Add(edgeBD);

	nodeE->Edges.Add(edgeBE);
	nodeE->Edges.Add(edgeCE);
	nodeE->Edges.Add(edgeEG);

	nodeF->Edges.Add(edgeCF);
	
	nodeG->Edges.Add(edgeEG);

	// Add nodes to member
	Nodes.Add(*nodeA);
	Nodes.Add(*nodeB);
	Nodes.Add(*nodeC);
	Nodes.Add(*nodeD);
	Nodes.Add(*nodeE);
	Nodes.Add(*nodeF);
	Nodes.Add(*nodeG);

	// Set up local variables
	start = nodeA;
	goal = nodeG;

	// Initialise priority queues
	open = NewObject<UPriorityQueue>();
	closed = NewObject<UPriorityQueue>();
}

TArray<FPathEdge*> UPathGraph::GetPath()
{
	TArray<FPathEdge*> path;
	FPathNodeRecord* startRecord = new FPathNodeRecord;
	startRecord->Node = start;
	startRecord->EstimatedTotalCost = GetHeuristicValue(start);

	open->Insert(startRecord, startRecord->EstimatedTotalCost);

	float endNodeHeuristic;

	while (open->Count() > 0)
	{
		FPathNodeRecord* current = open->GetSmallestElement();
		if (current->Node == goal)
		{
			break;
		}

		TArray<FPathEdge*> connections = current->Node->Edges;
		for (FPathEdge* connection : connections)
		{
			FPathNode* endNode = connection->ToNode;
			float endNodeCost = current->CostSoFarValue + connection->TraversalCost;

			FPathNodeRecord* endNodeRecordClosed = closed->Find(endNode->Name);
			FPathNodeRecord* endNodeRecordOpen = open->Find(endNode->Name);
			FPathNodeRecord* endNodeRecord = new FPathNodeRecord;
			if (endNodeRecordClosed != nullptr)
			{
				if (endNodeRecordClosed->CostSoFarValue <= endNodeCost)
				{
					continue;
				}

				closed->Delete(endNodeRecordClosed);
				endNodeHeuristic = endNodeRecordClosed->EstimatedTotalCost - endNodeRecordClosed->CostSoFarValue;
			}
			else if (endNodeRecordOpen != nullptr)
			{
				if (endNodeRecordOpen->CostSoFarValue <= endNodeCost)
				{
					continue;
				}
				endNodeHeuristic = endNodeRecordOpen->EstimatedTotalCost - endNodeRecordOpen->CostSoFarValue;
			}
			else
			{
				endNodeRecord->Node = endNode;

				endNodeHeuristic = GetHeuristicValue(endNode);
			}

			endNodeRecord->CostSoFarValue = endNodeCost;
			endNodeRecord->Connection = connection;
			endNodeRecord->EstimatedTotalCost = endNodeCost + endNodeHeuristic;

			if (endNodeRecordOpen == nullptr)
			{
				open->Insert(endNodeRecord, endNodeRecord->EstimatedTotalCost);
			}

			open->Delete(current);
			closed->Insert(current, current->EstimatedTotalCost);
		}

		if (current->Node != goal)
		{
			// No path found
		}
		else
		{
			while (current->Node != start)
			{
				path.Add(current->Connection);
				current->Connection->FromNode;
			}

			return path;
		}
	}

	return path;
}

float UPathGraph::GetHeuristicValue(FPathNode* node)
{
	return 0.0f;
}