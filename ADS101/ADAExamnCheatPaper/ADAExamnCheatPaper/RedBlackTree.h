#pragma once
#include "RBNode.h"
class RedBlackTree
{
public:
	RBNode* myRoot;
	RedBlackTree();

	RBNode* RotateLeft(RBNode* node);
	RBNode* RotateRight(RBNode* node);

	RBNode* InsertHelp(RBNode* root, int data);
	void Insert(int data);
	void InorderTraversal();
	void PrintTree();
};

