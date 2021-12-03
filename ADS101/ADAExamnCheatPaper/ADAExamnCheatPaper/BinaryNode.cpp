#include "BinaryNode.h"
#include <iostream>
#include "TQueue.h"
#include "TStack.h"
BinaryNode::BinaryNode()
{
	data = 0;
}

BinaryNode::BinaryNode(int _data, BinaryNode* _left, BinaryNode* _right) :
	data(_data)
{
	data = _data;
	left = _left;
	right = _right;
}

int BinaryNode::GetData()
{
	return data;
}

BinaryNode* BinaryNode::Find(int _data)
{
	if (data == _data) {
		return this;
	}
	else if (_data < data && left != nullptr) {	//If the _data is smaller than this->data and the left node is not null, return the find in left
		return left->Find(_data);
	}
	else if (_data > data && right != nullptr) { //If the _Data is bigger than this-> data, return the right find
		return right->Find(_data);
	}
	//If none of the above returns, return a nullptr
	return nullptr;
}

void BinaryNode::Insert(int _data)
{
	if (_data < data) {
		if (left) {
			left->Insert(_data);
		}
		else {
			left = new BinaryNode(_data);
			left->parent = this;
		}
	}
	else if (_data > data) {
		if (right) {
			right->Insert(_data);
		}
		else {
			right = new BinaryNode(_data);
			right->parent = this;

		}
	}
	DoBalance(this, _data);
}

void BinaryNode::Intrav()
{
	if (left) {
		left->Intrav();
	}
	std::cout << data << std::endl;
	if (right) {
		right->Intrav();
	}
}

void BinaryNode::DoBalance(BinaryNode* root, int _data)
{
	//If Right Height is larger than left it returns negative
	int balanace = Height(root->GetLeft()) - Height(root->GetRight());
	//Left is taller than right
	//Data is smaller than left
	if (balanace > 1 && _data < root->GetLeft()->data) {
		//Unbalanced
		RightRotation(root);
	}
	//Right is taller than left
	//Data is larger than right
	if (balanace < -1 && _data > root->GetRight()->data) {
		//Unbalanced
		LeftRotation(root);
	}
	//Left is taller than right
	//Data is larger than left
	if (balanace > 1 && _data > root->GetLeft()->data) {
		//Unbalanced
		root->left = LeftRotation(root->GetLeft());
		RightRotation(root);
	}
	//Right is taller than left
	//Data is smaller than right
	if (balanace < -1 && _data < root->GetRight()->data) {
		//Unbalanced
		root->right = RightRotation(root->GetRight());
		LeftRotation(root);
	}
}

int BinaryNode::Height(BinaryNode* root)
{
	if (!root) {
		return 0;
	}
	int a = 0;
	int b = 0;
	if (root->GetLeft()) {
		a = 1 + Height(root->GetLeft());
	}
	if (root->GetRight()) {
		b = 1 + Height(root->GetRight());
	}
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}

	return 0;
}

BinaryNode* BinaryNode::RightRotation(BinaryNode* root)
{

	BinaryNode* temp1 = root->GetLeft();
	BinaryNode* temp2 = temp1->GetRight();

	temp1->right = root;
	root->left = temp2;


	return temp1;
}

BinaryNode* BinaryNode::LeftRotation(BinaryNode* root)
{
	BinaryNode* temp1 = root->GetRight();
	BinaryNode* temp2 = temp1->GetLeft();

	root->left = temp1;
	temp1->right = temp2;

	return temp1;
}

void BinaryNode::Stigende()
{
	if (left)
		left->Stigende();
	std::cout << data << std::endl;
	if (right)
		right->Stigende();
}

void BinaryNode::Avtakende()
{
	if (right)
		right->Avtakende();
	std::cout << data << std::endl;
	if (left)
		left->Avtakende();
}

BinaryNode* BinaryNode::DeleteNode(BinaryNode* node)
{
	if (right) {
		if (node->right) {
			if (node != right) {
				node->right->parent = node->parent;
			}
			else {
				node->right->parent = parent;
			}
			if (node != right) {
				node->parent->left = node->right;
				node->right = right;
				right->parent = node;
			}
			node->left = left;
			if (left) {
				left->parent = node;
			}
		}
		if (node) {
			node->parent = parent;
		}
		if (parent) {
			if (parent->left == this) {
				parent->left = node;
			}
			else if (parent->right == this) {
				parent->right = node;
			}
		}
		
	}
	return this;
}

BinaryNode* BinaryNode::FindInorderReplacement()
{
	BinaryNode* replacement;
	if (right) {
		replacement = right;
		while(replacement->right) {
			replacement = replacement->right;
		}
	}
	else {
		replacement = left;
	}
	return replacement;
}

double BinaryNode::Sum()
{
	double totalsum = data;
	if (left)
		totalsum += left->Sum();
	if (right)
		totalsum += right->Sum();
	return totalsum;
}

void BinaryNode::WidthFirstTraversal()
{
	BinaryNode* p = this;
	TQueue<BinaryNode*> queue;
	queue.Push(p);
	while (queue.Size() != 0) {
		queue.Pop();
		std::cout << data << ", ";
		if (p->left) {
			queue.Push(p->left);
		}
		if (p->right) {
			queue.Push(p->right);
		}
	}
	std::cout << std::endl;
}

void BinaryNode::NonRecursivePreorderTraversal()
{
	BinaryNode* p = this;
	TStack<BinaryNode*> stack;
	
	do {
		while (p != nullptr) {
			std::cout << data << ", ";
			stack.Push(p);
			p = p->left;
		}
		if (!stack.Empty()) {
			stack.Pop();
			p = p->right;
		}
	} while (!stack.Empty() || p != nullptr);
	std::cout << std::endl;
}
