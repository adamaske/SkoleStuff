#pragma once
#include <list>
#include "Node.h"
#include <vector>
struct Path {
	std::list<Edge*> edges;
	double totalCost = 0;
	bool operator > (const Path& p) const { return totalCost > p.totalCost; };
	
};
struct Cell {
	Node* node;
	double f;
	double g;
	double h;

};
class Graph
{
public:
	Graph();
	std::list<Node*> nodes;
	Node* FindNode(char name);
	void InsertNode(char name);
	void InsertEdge(char fromNode, char toNode, float weight);
	float MinimumSpanningTree();
	void Djikstra(char fromNode, char toNode);
	void AStar(char fromNode, char toNode);
};

