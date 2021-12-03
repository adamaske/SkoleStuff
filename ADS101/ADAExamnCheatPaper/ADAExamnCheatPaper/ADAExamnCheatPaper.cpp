#include <iostream>
#include <chrono>
#include <algorithm>
#include <array>
#include <unordered_set>
#include <queue>
#include "TStack.h"
#include "TQueue.h"
#include "CharNode.h"
#include "BinaryNode.h"
#include "QuadTree.h"
#include "Graph.h"
#include "Node.h"
#include "RBNode.h"
#include "RedBlackTree.h"
#include "Hash.h"
void Tasks191to194();
template<typename T, size_t N>
void SelectionSort(T(&arr)[N]);
template<typename T, size_t N>
int BinarySearch(T(&arr)[N], T x);

void Inorder(BinaryNode* root);
void Postorder(BinaryNode* root);
int AmountOfNodes(BinaryNode* root);
int AmountOfLevels(BinaryNode* root);
bool BalancedCheck(BinaryNode* root);
int Height(BinaryNode* root);

template<typename T, size_t N>
void StdSort(T(&arr)[N]);
template<typename T, size_t N>
void BubbleSort(T(&arr)[N]);
template<typename T, size_t N>
void UtvalgsSort(T(&arr)[N]);
template<typename T, size_t N>
void InsertsionSort(T(&arr)[N]);
template<typename T, size_t N>
void MergeSort(T(&arr)[N]);
template<typename T, size_t N>
void HeapSort(T(&arr)[N]);
template<typename T, size_t N>
void Heapify(T(&arr)[N], int i);
template<typename T, size_t N>
void QuickSort(T(&arr)[N], int low, int high);
template<typename T, size_t N>
void QuickSortRecursive(T(&arr)[N], int low, int high);
template<typename T, size_t N>
int Partition(T(&arr)[N], int low, int high);
template<typename T, size_t N>
int BuildMaxHeap(T(&arr)[N]);
void SortByPriorityQueue();
void RedBlackTreeInsertion();

int main()
{
    int a[10];
    int sizeofa = sizeof(a) / sizeof(a[0]);
    //Linked-list
    CharNode* c = new CharNode('a', nullptr);
    c = new CharNode('b', c);
    c = new CharNode('c', c);
    c = new CharNode('d', c);
    c = new CharNode('e', c);
    c = new CharNode('f', c);
   
    //Stack
    TStack<int>* tstack = new TStack<int>();

    delete tstack;
    //Queue
    TQueue<int>* tqueue = new TQueue<int>();

    delete tqueue;
    //Smart pointers
    std::shared_ptr<CharNode> shp(c);
    std::cout << "shp er unik: " << shp.unique() << std::endl;
    std::unique_ptr<CharNode> up1(c);
    std::cout << "shp er unik: " << shp.unique() << std::endl;

    std::unique_ptr<CharNode> up(c->GetNext());
    auto tmp = shp.get();
    std::cout << "shared pointer data: " << tmp->GetAmount() << std::endl;
    std::cout << "Shared pointer data: " << shp->GetAmount() << std::endl;
    tmp = up.get();
    std::cout << "Unique pointer data: " << tmp->GetAmount() << std::endl;
    std::cout << "Unique pointer data: " << up->GetAmount() << std::endl;
    delete c;
    //Oppgaver 1.9.1-4
    Tasks191to194();
    //Selection sort
    SelectionSort(a);
    //Binary Search
    BinarySearch(a, 10);
    //Chrono
    //Syntax for using chrono
    auto start = std::chrono::high_resolution_clock::now();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> totalTime = end - start;
    std::chrono::nanoseconds totalTimeNano = std::chrono::duration_cast<std::chrono::nanoseconds>(totalTime);

    totalTime += totalTimeNano;
    int time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    
    //Recrusion Oppgaver 3.2.1-3

    //Binary Tree
    //Testing
    BinaryNode* left = new BinaryNode(1);
    BinaryNode* right = new BinaryNode(4);

    right = new BinaryNode(2, left, right);

    BinaryNode* binaryTree = new BinaryNode(8);

    left = new BinaryNode(16);
    binaryTree = new BinaryNode(10, binaryTree, left);
    binaryTree = new BinaryNode(7, right, binaryTree);

    //binaryTree->Intrav();
    //Create a non recursive inorder traversal of a binary tree
    Inorder(binaryTree);
    std::cout << std::endl;
    //Create a non recursive postorder traversal of a binary tree
    Postorder(binaryTree);
    std::cout << "Non recrusive Preorder Traversal of binary tree: " << std::endl;
    binaryTree->NonRecursivePreorderTraversal();
    std::cout << "Width first traversal of binary tree: " << std::endl;
    binaryTree->WidthFirstTraversal();
    std::cout << std::endl;
    //Write a function that returns amount of nodes in a binary tree
    std::cout << std::endl << "Number of nodes: " << AmountOfNodes(binaryTree) << std::endl;
    //Write a function that returns amount of levels in a binary tree
    std::cout << std::endl << "Number of levels: " << AmountOfLevels(binaryTree) << std::endl;
    //Write a function that fins if a binary tree is balanced 
    std::cout << std::endl << "The binary tree is " << BalancedCheck(binaryTree) << " balanced" << std::endl << std::endl;
    //Sum av binært tre
    binaryTree->Sum();
    //Print stigende 
    binaryTree->Stigende();
    //Print avtakende
    binaryTree->Avtakende();

    //Oppgaver 4.4.1-11

    //Avl-tree
    
    //Red-black tree
    RedBlackTree* rbTree = new RedBlackTree();
    rbTree->Insert(4);
    rbTree->Insert(5);
    rbTree->Insert(8);
    rbTree->InorderTraversal();
    //Stl::set

    //B-trees

    //2-3-4 trees

    //Quadtrees
    //Write a quadtree where the blades lay in different levels
    Vector2D ne{ 100, 100 };
    Vector2D nw{ 0, 100 };
    Vector2D se{ 100, 0 };
    Vector2D sw{ 0, -0 };
    QuadTree* tree = new QuadTree(ne, nw, se, sw);
    tree->Subdivide(1);
    tree->q_ne->Subdivide(1);
    Vector2D va;
    for (int i = 0; i < 18; i++)
    {
        va.x = rand() % 100;
        va.y = rand() % 100;
        tree->Insert(va);
    }
    ///tree->Print();
    //Write a function that returns all the corners to all quads which are blades 
    tree->FindAllLeafes();

    //Oppgaver 5.7.1-4

    //Heap

    //stl priority_queue
    std::cout << "max heap(descending)= default " << std::endl;
    std::priority_queue<double> max_heap;
    max_heap.push(3.14);
    max_heap.push(9.81);
    max_heap.push(2.71828);
    auto rot = max_heap.top();
    std::cout << " Foer pop : heap rot = heap top = " << rot << std::endl;
    max_heap.pop();
    rot = max_heap.top();
    std::cout << " Etter pop : heap rot = heap top = " << rot << std::endl;
    std::cout << "min heap(ascending) " << std::endl;
    std::priority_queue<double, std::vector<double>, std::greater<double>> min_heap;
    min_heap.push(3.14);
    min_heap.push(9.81);
    min_heap.push(2.71828);
    auto min_rot = min_heap.top();
    std:: cout << " Foer pop : heap r o t = heap top = " << min_rot << std::endl;
    min_heap.pop();
    min_rot = min_heap.top();
    std::cout << " Etter pop : heap rot = heap top = " << min_rot << std::endl;
    std::cout << " Etter pop : heap size = " << min_heap.size() << std::endl;
    std::cout << " Etter pop : heap empty ? " << std::boolalpha << min_heap.empty() << std::endl;

    std::cout << "Displaying Hashtable" << std::endl;
    Hash h(7);
    for (int i = 0; i < sizeofa; i++) {
        h.InsertItem(a[i]);
    }
    h.DeleteItem(1);
    h.DisplayHash();
    std::cout << "Ended hashing" << std::endl;
    //Oppgaver 6.5.1-4

    //Sorting O(n) notasjon, Hvordan måle effektivitet?
    std::cout << "Started sorting" << std::endl;
    //Bobble sort, Utvalgsortering, Binarytree sorting, Insertion sort
    BubbleSort(a);
    UtvalgsSort(a);
    InsertsionSort(a);
    //Mergesort
    MergeSort(a);
    //Heapsort
    HeapSort(a);
    //Quicksort
    QuickSort(a, 0, sizeofa - 1);
    std::cout << "Ended sorting" << std::endl;
    //Hashing
    std::hash<Test> hashtabell;
    std::unordered_set<Test> us;
    Test t;
    t.key = 12; 
    t.s = "tolv"; 
    us.insert(t);
    t.key = 13; 
    t.s = "tretten"; 
    us.insert(t);
    t.key = 20; 
    t.s = "tjuesju"; 
    us.insert(t);
    t.key = 21; 
    t.s = "tjueen"; 
    us.insert(t);
    for (int i = 1; i < 7; i++) {
        t.key = i; 
        t.s = "blabla"; 
        us.insert(t);
    }
    Hash* hash = new Hash();
    std::cout << std::endl << "Tester hash for int" << std::endl;
    hash->TestHash();
    std::cout << "Test unordered set" << std::endl;
    hash->TestUnorderdSet();
    std::cout << "Test unordered multiset" << std::endl;
    hash->TestUnorderdMultiset();
    //Graphs
    Graph* g = new Graph();
    g->InsertNode('A');
    g->InsertNode('B');
    g->InsertNode('C');
    g->InsertNode('D');
    g->InsertNode('E');
    g->InsertNode('F');
    g->InsertNode('G');
    g->InsertEdge('A', 'B', 2);
    g->InsertEdge('A', 'C', 17);
    g->InsertEdge('C', 'B', 2);
    g->InsertEdge('B', 'E', 3);
    g->InsertEdge('B', 'F', 7);
    g->InsertEdge('E', 'C', 4);
    g->InsertEdge('E', 'F', 3);
    g->InsertEdge('F', 'C', 2);
    g->InsertEdge('C', 'G', 5);
    g->InsertEdge('F', 'G', 3);
    g->InsertEdge('G', 'D', 2);
    g->InsertEdge('D', 'G', 4);
    g->InsertEdge('D', 'C', 2);
    
    //Mst
    std::cout << "Graphs minimum spanning tree: " << g->MinimumSpanningTree() << std::endl;
    //Djikstras algrorithm
    g->Djikstra('A', 'D');
    //A* algorithm

    //Huffman

    //Eksamen 2021 V
    //Gitt tallene 2.71828, 1.732, 3.1416, 9.81
    //A Tegn et binært søketre av tallene, satt inn i rekkefølgen over
    //              2.71828
    //              /   \
    //          1.732   3.1416
    //         /   \     /   \
    //      1.414           9.81
    //B min-heap
    // Fasit 1b
    //          9.81
    //           / \
    //      3.1416   1.41
    //       / \
    //   1.732  2.78
    //C max.heap
    //              1.41
    //                  \
    //          2.71828 1.732
    //           / \
    //      3.1416  9.81
    // 
    //D skriv et C++ program som begynner en max-heap med de samme tallene
    BuildMaxHeap(a);


    return 0;
}

void Tasks191to194()
{
    //Opgg 1.9.1
    std::cout << "Oppgave 1.9.1" << std::endl;
    TStack<CharNode>* s = new TStack<CharNode>();
    CharNode* c = new CharNode('a', nullptr);
    c = new CharNode('b', c);
    c = new CharNode('c', c);
    c = new CharNode('d', c);
    c = new CharNode('e', c);
    c = new CharNode('f', c);

    s->Push(*c);
    //Prints every on top and pop until the stack is empty
    while (s->Size() != 0) {
        s->Top().Print();
        s->Pop();
        std::cout << "Stack size after pop: " << s->Size() << std::endl;
    }

    //Opgg 1.9.2
    std::cout << "Oppgave 1.9.2" << std::endl;
    TStack<CharNode>* ts = new TStack<CharNode>();
    CharNode* tc = new CharNode('a', nullptr);
    tc = new CharNode('b', tc);
    tc = new CharNode('c', tc);
    tc = new CharNode('d', tc);
    tc = new CharNode('e', tc);
    tc = new CharNode('f', tc);

    ts->Push(*tc);

    while (ts->Size() != 0) {
        ts->Top().Print();
        ts->Pop();
        std::cout << "Stack size after pop: " << s->Size() << std::endl;
    }
    delete ts;
    //Opgg 1.9.3
    std::cout << "Oppgave 1.9.3" << std::endl;
    TQueue<char>* q = new TQueue<char>();
    q->Push('a');
    q->Push('b');
    q->Push('c');
    q->Push('d');
    q->Push('e');

    std::cout << "The front of the queue is: " << q->Front() << std::endl << "The current back of the queue is: " << q->Back() << std::endl;
    //Print each front of the array and pop it
    while (q->Size() != 0) {
        std::cout << q->Front() << std::endl;
        q->Pop();
    }

    TQueue<int>* tq = new TQueue<int>();
    tq->Push(1);
    tq->Push(14);
    tq->Push(123);
    tq->Push(5463);
    tq->Push(9073);

    while (tq->Size() != 0) {
        std::cout << tq->Front() << std::endl;
        tq->Pop();
    }

    //Oppgg 1.9.4
    std::cout << "Oppgave 1.9.4" << std::endl;
    TStack<char>* s2 = new TStack<char>();
    s2->Push('a');
    s2->Push('b');
    s2->Push('c');
    s2->Push('d');
    s2->Push('e');
    s2->Push('f');

    while (s2->Size() != 0) {
        std::cout << s2->Top() << std::endl;
        s2->Pop();
    }
}

template<typename T, size_t N>
void SelectionSort(T(&arr)[N])
{
    //1. Selection sort
    for (auto i = 0; i < N - 1; i++) {
        for (auto j = i + 1; j < N; j++) {
            if (arr[j] > arr[i]) {
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

template<typename T, size_t N>
int BinarySearch(T(&arr)[N], T x)
{
    int indeks = -1;
    int n = N;
    int v{ 0 }; 
    int h{ N - 1 };
    while (v <= h && indeks == -1)
    {
        auto midt = (v + h) / 2;
        if(x == arr[midt]) {
            indeks = midt;
        }  
        else if (x < arr[midt]) {
            h = midt - 1;
        } else {// x > a [ midt ]
            v = midt + 1;
        } 
    }
    return indeks;
}

void Inorder(BinaryNode* root) {
    BinaryNode* current, * previous;
    current = root;

    while (current != nullptr) {
        //Goes down the left, until there is no more to the left, then goes down right until there is no more
        if (current->GetLeft() != nullptr) {
            previous = current->GetLeft();
            //Get the bottom right and stores it in previous
            while (previous->GetRight() != nullptr && previous->GetRight() != current) {
                previous = previous->GetRight();
            }
            //Here it has gotten the bottom right it can, without a left
            //Store this in previous 
            if (previous->GetRight() == nullptr) {
                //Store the current as previous->Right
                previous->right = current;
                //Then go down the left as long as it goes
                current = current->GetLeft();
            }
            else {
                //If the previous has no right, then print it
                std::cout << current->GetData() << " ";
                previous->right = nullptr;
                //Get the new current as this ones right
                current = current->GetRight();
                //Then returns to check if it has a left, then it prints it
            }
        }
        else {
            //Get the right instead of the left

            std::cout << current->GetData() << " ";
            current = current->GetRight();
        }
    }
}

void Postorder(BinaryNode* root)
{
    TStack<BinaryNode*> stack;
    stack.Push(root);

    while (!stack.Empty()) {
        BinaryNode* current = stack.Top();
        stack.Pop();

        std::cout << current->GetData() << " ";

        if (current->GetLeft()) {
            stack.Push(current->GetLeft());
        }

        if (current->GetRight()) {
            stack.Push(current->GetRight());
        }
    }
}

int AmountOfNodes(BinaryNode* root)
{
    TStack<BinaryNode*> stack;
    stack.Push(root);

    int count = 0;

    while (!stack.Empty()) {
        BinaryNode* current = stack.Top();
        stack.Pop();

        count++;

        if (current->GetLeft()) {
            stack.Push(current->GetLeft());
        }

        if (current->GetRight()) {
            stack.Push(current->GetRight());
        }
    }


    return count;
}

int AmountOfLevels(BinaryNode* root)
{
    TStack<BinaryNode*> stack;
    stack.Push(root);

    int count = 0;

    while (!stack.Empty()) {
        BinaryNode* current = stack.Top();
        stack.Pop();
        bool hasCounted = false;

        //Only add count if it hasnt done it already
        if (current->GetLeft()) {
            stack.Push(current->GetLeft());
            count++;
            hasCounted = true;
        }

        if (current->GetRight()) {
            stack.Push(current->GetRight());
            if (!hasCounted) {
                count++;
                hasCounted = true;
            }
        }
    }

    return count;
}

bool BalancedCheck(BinaryNode* root)
{
    //Return true if this is null
    if (!root) {
        return true;
    }
    //Find how many levels there is down from here for both left and right
    int leftHeight = Height(root->GetLeft());
    int rightHeight = Height(root->GetRight());
    //The heights must be either 0, then check this for every level of the tree
    //if any level is not balanced the whole loop returns false
    if ((leftHeight - rightHeight) <= 0 && BalancedCheck(root->GetLeft()) && BalancedCheck(root->GetRight())) {
        return true;
    }
    else {
        return false;
    }

}

int Height(BinaryNode* root) {
    if (!root) {
        return 0;
    }
    else {
        //Goes down the 
        int a = Height(root->GetLeft());
        int b = Height(root->GetRight());

        //returns the highest of the two
        if (a > b) {
            return 1 + a;
        }
        else {
            return 1 + b;
        }
    }


}

void SortByPriorityQueue()
{
    int a[]{ 14,33,12,4,7,19,29,11,17 };
    std::priority_queue<int> pq;
    for (int i = 0; i < 9; i++) {
        pq.push(a[i]);
    }
    while (!pq.empty()) {
        std::cout << pq.top() << ", ";
        pq.pop();
    }
    std::cout << std::endl;
}

void RedBlackTreeInsertion()
{
    //Sett inn ny node som RED

    //Ved å farge noden RED, blir det enklere å fikse senere

    //Recolor og roter

    //4 secnarioer

    //If node = root, farg sort

    //Hvis node har en rød onkel, bytt farge på parent, grandparent og uncle

    //Triangel case
    //Hvis node og node->parent er omvendt barn av hverandre
    //Hvis onkel er BLACK, roter node->parent
    //Hvis node er en venstrebarn, roter til høyre, 
    //Hvis node er høyrebarn, roter til venstre

    //Line case
    //Hvis både node og node->parent er venstre eller høyre barn, er det line case
    //Roter grandparent, omvendt vei av node
    //Node->parent tar grandparent plassen, grandparent blir parent omvendt av node, bytt farge på parent og grandparent

}

template<typename T, size_t N>
void StdSort(T(&arr)[N])
{
    std::sort(std::begin(arr), std::end(arr));
}

template<typename T, size_t N>
void BubbleSort(T(&arr)[N])
{
    int i, j;
    for (i = 0; i < N - 1; i++) {
        // Last i elements are already in place
        for (j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template<typename T, size_t N>
void UtvalgsSort(T(&arr)[N])
{
    for (auto i = 0; i < N - 1; i++)
    {
        for (auto j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[i])
            {
                auto hjelp = arr[i];
                arr[i] = arr[j];
                arr[j] = hjelp;
            }
        }
    }
}

template<typename T, size_t N>
void InsertsionSort(T(&arr)[N])
{
    for (auto i = 1; i < sizeof(arr) / sizeof(*arr); i++)
    {
        //Gets the current
        auto hjelp = arr[i];
        //If the the prevois element is larger, move it behind
        for (auto j = i - 1; j >= 0 && arr[j] > hjelp; j--)
        {
            arr[j + 1] = arr[j];
            arr[j] = hjelp;
        }
    }
}

template<typename T, size_t N>
void MergeSort(T(&arr)[N])
{
    int i, j, k, lower1, lower2, size, upper1, upper2;
    std::array<int, N> hjelp;
    size = 1;
    while (size < N) {
        lower1 = 0;
        k = 0;
        while (lower1 + size < N) {
            upper1 = lower1 + size - 1;
            lower2 = upper1 + 1;
            upper2 = (lower2 + size - 1 < N) ? lower2 + size - 1 : N - 1;
            for (i = lower1, j = lower2; i <= upper1 && j <= upper2; k++)
            {
                if (arr[i] < arr[j]) {
                    hjelp[k] = arr[i++];
                }
                else {
                    hjelp[k] = arr[j++];
                }
            }
            for (; i <= upper1; k++) {
                hjelp[k] = arr[i++];
            }
            for (; j <= upper2; k++) {
                hjelp[k] = arr[j++];
            }
            lower1 = upper2 + 1;

        }
        for (i = lower1; k < N; i++) {
            hjelp[k++] = arr[i];
        }
        for (i = 0; i < N; i++) {
            arr[i] = hjelp[i];
        }
        size = size * 2;
    }
}

template<typename T, size_t N>
void HeapSort(T(&arr)[N])
{
    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--) {
        Heapify(arr, i);
    }
        
    // One by one extract an element from heap
    for (int i = N - 1; i > 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        Heapify(arr, 0);
    }
}

template<typename T, size_t N>
void Heapify(T(&arr)[N], int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest]) {
        largest = l;
    }
        
    // If right child is larger than largest so far
    if (r < N && arr[r] > arr[largest]) {
        largest = r;
    }
       
    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        Heapify(arr, largest);
    }
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
template<typename T, size_t N>
void QuickSort(T(&arr)[N], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = Partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

template<typename T, size_t N>
void QuickSortRecursive(T(&arr)[N], int low, int high)
{
    if (low < high) // left+10 <=right i boka
    {
        int pivot = arr[(low + high) / 2]; // enklere pivoteringsvalg
        int i = low, j = high;
        for (;;)
        {
            while (arr[i] < pivot) { i++; } // funnet 1. fra venstre >= pivot
            while (pivot < arr[j]) { j--; } // funnet 1. fra høyre <= pivot
            if (i < j)
                std::swap(arr[i], arr[j]);   // på riktig side av pivot
            else
                break;
        }
        QuickSortRecursive(arr, low, i - 1);
        QuickSortRecursive(arr, i + 1, high);
    }
}

template<typename T, size_t N>
int Partition(T(&arr)[N], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template<typename T, size_t N>
int BuildMaxHeap(T(&arr)[N])
{
    double a[]{ 2.71828, 1.732, 1.414, 3.1416, 9.81 };
    std::priority_queue<double> pq;
    for (int i = 0; i < 5; i++)
    {
        pq.push(a[i]);
    }
    pq.pop();
    std::cout << pq.top();
    return 0;
}


