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
