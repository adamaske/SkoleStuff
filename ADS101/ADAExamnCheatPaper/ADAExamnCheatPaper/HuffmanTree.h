#pragma once
#define MAX_TREE_HT 50
struct MinHNode {
	unsigned freq;
	char data;
	struct MinHNode* left, * right;
};

struct MinH {
	unsigned size;
	unsigned capacity;
	MinHNode** array;
};
class HuffmanTree
{
public:
	MinHNode* NewNode(char _data, int _freq);
	MinH* CreateMinH(unsigned capacity);
	void PrintArray(int arr[], int n);
	void SwapMinHNode(MinHNode** a, MinHNode** b);
	void MinHeapify(MinH* minHeap, int index);
	int CheckSizeOne(MinH* minHeap);
	MinHNode* ExtractMin(MinH* minHeap);
	void InsertMinHeap(MinH* minHeap, MinHNode* minHeapNode);
	void BuildMinHeap(MinH* minHeap);
	int IsLeaf(MinHNode* root);
	MinH* CreateAndBuildMinHeap(char _data[], int _freq[], int size);
	MinHNode* BuildHuffmanTree(char _data[], int _freq[], int size);
	void PrintHuffmanCondes(MinHNode* root, int arr[], int top);
	void HuffmanCodes(char _data[], int _freq[], int size);

};

