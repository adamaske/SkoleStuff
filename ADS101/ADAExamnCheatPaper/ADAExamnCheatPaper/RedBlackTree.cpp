#include "RedBlackTree.h"

RedBlackTree::RedBlackTree()
{
}

RBNode* RedBlackTree::RotateLeft(RBNode* node)
{
	RBNode* x = node->right;
	RBNode* y = x->left;

	x->left = node;
	node->right = y;
	node->parent = x;
	if (y) {
		y->parent = node;
	}
	return x;
}

RBNode* RedBlackTree::RotateRight(RBNode* node)
{
	RBNode* x = node->left;
	RBNode* y = x->right;

	x->right = node;
	node->left = y;
	node->parent = x;
	if (y) {
		y->parent = node;
	}
	return x;
}

RBNode* RedBlackTree::InsertHelp(RBNode* root, int data)
{
	return nullptr;
}

void RedBlackTree::Insert(int data) {
	
}
void RedBlackTree::InorderTraversal()
{
}

void RedBlackTree::PrintTree()
{
}
