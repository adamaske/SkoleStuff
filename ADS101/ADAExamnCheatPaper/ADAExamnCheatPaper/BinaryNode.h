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
<<<<<<< HEAD
	int m_frekvens = 0;
	char m_data;
	void Insert(char _data);
	void Print() const;
	BinaryNode* m_left;
	void PrintSorted();
	BinaryNode* m_right;
	BinaryNode* left;
	BinaryNode* right;
=======
	BinaryNode* left = nullptr;
	BinaryNode* right = nullptr;
	BinaryNode* parent;
>>>>>>> a40aec551ab31a016b196c0b2db70ee80ec145d0
	void DoBalance(BinaryNode* root, int _data);
	int Height(BinaryNode* root);
	BinaryNode* RightRotation(BinaryNode* root);
	BinaryNode* LeftRotation(BinaryNode* root);
	void Stigende();
	void Avtakende();
	BinaryNode* DeleteNode(BinaryNode* node);
	BinaryNode* FindInorderReplacement();
	double Sum();
	void WidthFirstTraversal();
	void NonRecursivePreorderTraversal();
};

