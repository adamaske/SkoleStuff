#pragma once
class BinaryNode
{
public:
	BinaryNode();
	BinaryNode(int _data, BinaryNode* _left = nullptr, BinaryNode* _right = nullptr);

	int GetData();
	BinaryNode* Find(int _data);
	void Insert(int _data);
	void Intrav();
	BinaryNode* GetLeft() { return left; };
	BinaryNode* GetRight() { return right; };

	int data;
	BinaryNode* left;
	BinaryNode* right;
};

