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
    for (auto node : nodes) {
        node->visited = false;
    }
    Edge edge(0, nodes.front());
    apq.push(edge);

    while (!apq.empty()) {
        edge = apq.top();
        apq.pop();
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

    for (auto node : nodes) {
        node->visited = false;
    }

    Node* startNode = FindNode(fromNode);
    Node* endNode = FindNode(toNode);

    Path startPath;
    Edge startEdge(0, startNode);

    startPath.edges.push_back(&startEdge);
    startPath.totalCost = 0;

    apq.push(startPath);
    
    while (!apq.empty() && !endNode->visited) {
        //Gets the shortest path from apq, top should be the shortest path
        auto path = apq.top();
        apq.pop();

        //Print current path
        std::cout << "Popped from queue: ";
        for (auto edge : path.edges) {
            std::cout << edge->toNode->name << ", ";
        }
        std::cout << " = " << path.totalCost << std::endl;

        if (!endNode->visited) {
            Node* node = path.edges.back()->toNode; //This is 
            if (!node->visited) {
                for (auto e : node->edges) {
      
                    Path p = path;
                    p.edges.push_back(&e);
                    p.totalCost += e.weight;
                    apq.push(p);
                    std::cout << "The old path contains: ";
                    for (auto x : path.edges) {
                        std::cout << x->toNode->name << ", ";
                    }
                    std::cout << " = " << p.totalCost << std::endl;
                    std::cout << "Added " << e.toNode->name << " to the path" << std::endl;
                    std::cout << "The new pushed path contains: ";
                    for (auto x : p.edges) {
                        std::cout << x->toNode->name << ", ";
                    }
                    std::cout << " = " << p.totalCost << std::endl;
                }
            }

            
            node->visited = true;
        }
    }
    /*
        
    
    */
    while (!apq.empty()) {
        std::cout << "Path: ";
        Path p = apq.top();
        for (auto edge : p.edges) {
            Node* n = edge->toNode;
            std::cout << n->name << ", ";
        }
        std::cout << " = " << p.totalCost << std::endl;
        apq.pop();
    }
}

void Graph::AStar(char fromNode, char toNode)
{

}
