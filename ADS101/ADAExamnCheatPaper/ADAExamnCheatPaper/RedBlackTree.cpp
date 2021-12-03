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
	RBNode* node = new RBNode(data);
	node->color = RED;
	if (root->data > data) {
		//Add it to the left
		if (root->left) {
			//Already has a left
			InsertHelp(root->left, data);
			return node;
		}
		else {
			root->left = node;
			node->parent = root;
		}
	}
	else {
		//Add it to the right
		if (root->right) {
			InsertHelp(root->right, data);
			return node;
		}
		else {
			root->right = node;
			node->parent = root;
		}
	}

	//Sett inn ny node som RED

	//Ved � farge noden RED, blir det enklere � fikse senere

	//Recolor og roter

	//4 secnarioer

	//If node = root, farg sort

	//Hvis node har en r�d onkel, bytt farge p� parent, grandparent og uncle
	/*
	RBNode* u = node->GetUncle(node);
	RBNode* p = node->GetParent(node);
	RBNode* gp = node->GetGrandParent(node);
	RBNode* y;
	
	while (p->color == RED) {
		//Is the parent a left node
		if (p == gp->left) {
			y = gp->right;
			//If the uncle is RED case
			if (y->color == RED) {
				//Switch colors
				p->color = BLACK;
				y->color = BLACK;
				gp->color = RED;
				node->color = gp->color;
			}
			else if (node = p->right) {

			}
		}
		else {
			y = gp->left;
			//If the uncle is RED case
			if (y->color == RED) {
				//Switch colors
				p->color = BLACK;
				y->color = BLACK;
				gp->color = RED;
				node->color = gp->color;
			}
			else if (node = p->left) {

			}
		}
		return node;
		break;
	}
	myRoot->color = BLACK;
	return node;
	*/
	//Triangel case
	//Hvis node og node->parent er omvendt barn av hverandre
	//Hvis onkel er BLACK, roter node->parent
	//Hvis node er en venstrebarn, roter til h�yre, 
	//Hvis node er h�yrebarn, roter til venstre

	//Line case
	//Hvis b�de node og node->parent er venstre eller h�yre barn, er det line case
	//Roter grandparent, omvendt vei av node
	//Node->parent tar grandparent plassen, grandparent blir parent omvendt av node, bytt farge p� parent og grandparent

	
	//R
}

void RedBlackTree::Insert(int data) {
	if (!myRoot) {
		myRoot = new RBNode(data);
		myRoot->color = BLACK;
		return;
	}
	else {
		InsertHelp(myRoot, data);
	}
	
	
}
void RedBlackTree::InorderTraversal()
{
}

void RedBlackTree::PrintTree()
{
}
