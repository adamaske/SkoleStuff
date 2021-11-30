#include "Graph.h"
#include <queue>
#include <iostream>
Graph::Graph()
{
}

Node* Graph::FindNode(char name)
{
    for (auto& node : nodes) {
        if (node->name == name) {
            return node;
        }
    }
	return nullptr;
}

void Graph::InsertNode(char name)
{
    Node* n = new Node(name);
    for (auto& node : nodes) {
        if (node->name == name) {
            //Har allerede noden
            return;
        }
    }
    nodes.push_back(n);
}

void Graph::InsertEdge(char fromNode, char toNode, float weight)
{
    auto _toNode = FindNode(toNode);
    Edge e(weight, _toNode);

    auto _fromNode = FindNode(fromNode);
    _fromNode->InsertEdgeInNode(e);
}

float Graph::MinimumSpanningTree()
{
    float sum = 0;
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> apq;

    Edge edge(0, nodes.front());
    apq.push(edge);
    while (!apq.empty()) {
        edge = apq.top();
        Node* p = edge.toNode;
        if (!p->visited) {
            p->visited = true;

            sum += edge.weight;
            for (auto it : p->edges) {
                apq.push(it);
            }
        }
    }
	return sum;
}

void Graph::Djikstra(char fromNode, char toNode)
{

    std::priority_queue<Path, std::vector<Path>, std::greater<Path>> apq;

    Node* startNode = FindNode(fromNode);
    Node* endNode = FindNode(toNode);
    Path startPath;
    Edge startEdge(0, startNode);
    startPath.edges.push_back(&startEdge);
    startPath.totalCost = 0;

    apq.push(startPath);
    // A, Cost : 0
    while (!apq.empty() && !endNode->visited) {
        //Gets the shortest path from apq, top should be the shortest path
        auto path = apq.top();
        apq.pop();

        if (!endNode->visited) {
            //A er current node
            for (auto& edge : endNode->edges) {

                path.edges.push_back(&edge);
                path.totalCost += edge.weight;
                apq.push(path);
            }
        }
    }

}
