#include "BinaryNode.h"
#include <iostream>

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
		}
	}
	else if (_data > data) {
		if (right) {
			right->Insert(_data);
		}
		else {
			right = new BinaryNode(_data);

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
	int a;
	int b;
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

double BinaryNode::Sum()
{
	double totalsum = data;
	if (left)
		totalsum += left->Sum();
	if (right)
		totalsum += right->Sum();
	return totalsum;
}
