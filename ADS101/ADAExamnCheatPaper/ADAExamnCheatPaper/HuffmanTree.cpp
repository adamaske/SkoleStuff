#include "HuffmanTree.h"
#include <iostream>
MinHNode* HuffmanTree::NewNode(char _data, int _freq)
{
    MinHNode* temp = new MinHNode();
    temp->left = temp->right = nullptr;
    temp->data = _data;
    temp->freq = _freq;
    return temp;
}

MinH* HuffmanTree::CreateMinH(unsigned capacity)
{
    MinH* minHeap = new MinH();
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHNode**)(minHeap->capacity * sizeof(struct MinHNode*));
    return minHeap;
}

void HuffmanTree::PrintArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        std::cout << arr[i];

    std::cout << "\n";
}

void HuffmanTree::SwapMinHNode(MinHNode** a, MinHNode** b)
{
    MinHNode* t = *a;
    *a = *b;
    *b = t;
}

void HuffmanTree::MinHeapify(MinH* minHeap, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if(left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != index) {
        SwapMinHNode(&minHeap->array[smallest], &minHeap->array[index]);
        MinHeapify(minHeap, smallest);
    }
}

int HuffmanTree::CheckSizeOne(MinH* minHeap)
{
    return (minHeap->size == 1);
}

MinHNode* HuffmanTree::ExtractMin(MinH* minHeap)
{
    MinHNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    MinHeapify(minHeap, 0);

    return temp;
}

void HuffmanTree::InsertMinHeap(MinH* minHeap, MinHNode* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

void HuffmanTree::BuildMinHeap(MinH* minHeap)
{
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        MinHeapify(minHeap, i);
}

int HuffmanTree::IsLeaf(MinHNode* root)
{
    return !(root->left) && !(root->right);
}

MinH* HuffmanTree::CreateAndBuildMinHeap(char _data[], int _freq[], int size)
{
    MinH* minHeap = CreateMinH(size);

    std::cout << "Size : " << size << std::endl;
    for (int i = 0; i < size; ++i) {
 
            minHeap->array[i] = NewNode(_data[i], _freq[i]);

       
    }
        

    minHeap->size = size;
    BuildMinHeap(minHeap);

    return minHeap;
}

MinHNode* HuffmanTree::BuildHuffmanTree(char _data[], int _freq[], int size)
{
    MinHNode* left, * right, * top;
    struct MinH* minHeap = CreateAndBuildMinHeap(_data, _freq, size);

    while (!CheckSizeOne(minHeap)) {
        left = ExtractMin(minHeap);
        right = ExtractMin(minHeap);

        top = NewNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        InsertMinHeap(minHeap, top);
    }
    return ExtractMin(minHeap);
}

void HuffmanTree::PrintHuffmanCondes(MinHNode* root, int arr[], int top)
{
    if (root->left) {
        arr[top] = 0;
        PrintHuffmanCondes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        PrintHuffmanCondes(root->right, arr, top + 1);
    }
    if (IsLeaf(root)) {
        std::cout << root->data << "  | ";
        PrintArray(arr, top);
    }
}

void HuffmanTree::HuffmanCodes(char _data[], int _freq[], int size)
{
    std::cout << "Size : ";
    MinHNode* root = BuildHuffmanTree(_data, _freq, size);

    int arr[MAX_TREE_HT], top = 0;

    PrintHuffmanCondes(root, arr, top);
}
