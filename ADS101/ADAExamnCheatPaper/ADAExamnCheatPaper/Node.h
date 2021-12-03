#pragma once
#include <list>
class Node;
struct Edge {
	float weight;
	Node* toNode;
	Edge(float _weight, Node* _toNode) : weight(_weight), toNode(_toNode){}
	bool operator > (const Edge& e) const { return weight < e.weight; };
};

class Node
{
public:

	char name;
	bool visited;
	std::list<Edge> edges;
	Node(char _name) : name(_name), visited(false){ };
	void InsertEdgeInNode(const Edge& edge);
};




