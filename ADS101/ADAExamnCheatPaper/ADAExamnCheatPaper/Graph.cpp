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
    std::priority_queue<Path> dpq;
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
        //This is A
        Node* node;
        if (!endNode->visited) {
            for (auto edge : path.edges) {
                node = edge->toNode;
                //This becomes A
                if (!node->visited) {
                    //A.visited = true;
                    node->visited = true;
                    std::cout << "Set " << node->name << " to visisted" << std::endl;
                    //For each edge in A
                    for (auto e : node->edges) {
                        
                        Path p = path;
                        //Pushes C to A-> A, C
                        //Pushes B to A-> A, B
                        p.edges.push_back(&e);
                        //Adds 17
                        //Adds 2
                        std::cout << "Added " << e.weight << "to " << p.totalCost;
                        p.totalCost += e.weight;
                        std::cout << "which is now " << p.totalCost << std::endl;
                        //A C is pushed, A B is pushed
                        apq.push(p);
                        std::cout << "Pushed path: ";
                        for (auto edge : p.edges) {
                            Node* n = edge->toNode;
                            std::cout << n->name << ", ";
                        }
                        std::cout << " = " << p.totalCost << std::endl;
                        Path q = apq.top();
                        std::cout << "This is the top of apq now: ";
                        for (auto edge : q.edges) {
                            Node* n = edge->toNode;
                            std::cout << n->name << ", ";
                        }
                        std::cout << " = " << q.totalCost << std::endl;
                    }
                }
                else {
                    std::cout << "Skipped " << node->name << " becuause it has already been visited" << std::endl;
                }
            }
        }
    }
    
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
