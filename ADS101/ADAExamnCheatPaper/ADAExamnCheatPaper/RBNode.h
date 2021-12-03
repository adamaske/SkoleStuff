#pragma once
enum COLOR{RED, BLACK};
class RBNode
{
public: 
	RBNode();
	RBNode(int _data);

	
	RBNode* parent = nullptr;
	RBNode* left = nullptr;
	RBNode* right = nullptr;
	int data;
	enum COLOR color = RED;

	int GetData() { return data; };
	RBNode* GetLeft() { return left; };
	RBNode* GetRight() { return right; };

	RBNode* GetParent(RBNode* node);
	RBNode* GetGrandParent(RBNode* node);
	RBNode* GetSibling(RBNode* node);
	RBNode* GetUncle(RBNode* node);
	RBNode* GetCloseNephew(RBNode* node);
	RBNode* GetDistantNephew(RBNode* node);
};

