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
	int m_frekvens = 0;
	char m_data;
	void Insert(char _data);
	void Print() const;
	BinaryNode* m_left;
	void PrintSorted();
	BinaryNode* m_right;
	BinaryNode* left;
	BinaryNode* right;
	void DoBalance(BinaryNode* root, int _data);
	int Height(BinaryNode* root);
	BinaryNode* RightRotation(BinaryNode* root);
	BinaryNode* LeftRotation(BinaryNode* root);
	void Stigende();
	void Avtakende();
	double Sum();
};

