#include <iostream>
#include <chrono>
#include <algorithm>
#include <array>
#include "TStack.h"
#include "TQueue.h"
#include "CharNode.h"
#include "BinaryNode.h"
#include "QuadTree.h"
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
void InsertsionSort(T(&arr)[N]);
template<typename T, size_t N>
void MergeSort(T(&arr)[N]);


int main()
{
    int a[10];
    //Linked-list
    CharNode* c = new CharNode('a', nullptr);
    c = new CharNode('b', c);
    c = new CharNode('c', c);
    c = new CharNode('d', c);
    c = new CharNode('e', c);
    c = new CharNode('f', c);
    delete c;
    //Stack
    TStack<int>* tstack = new TStack<int>();

    delete tstack;
    //Queue
    TQueue<int>* tqueue = new TQueue<int>();

    delete tqueue;
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

    std::cout << std::endl;
    //Write a function that returns amount of nodes in a binary tree
    std::cout << std::endl << "Number of nodes: " << AmountOfNodes(binaryTree) << std::endl;

    //Write a function that returns amount of levels in a binary tree

    std::cout << std::endl << "Number of levels: " << AmountOfLevels(binaryTree) << std::endl;
    //Write a function that fins if a binary tree is balanced 

    std::cout << std::endl << "The binary tree is " << BalancedCheck(binaryTree) << " balanced" << std::endl << std::endl;
    //Oppgaver 4.4.1-11

    //Avl-tree
    
    //Red-black tree

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

    //Oppgaver 6.5.1-4

    //Sorting O(n) notasjon, Hvordan måle effektivitet?

    //Bobble sort, Utvalgsortering, Binarytree sorting, Insertion sort
    
    InsertsionSort(a);
    MergeSort(a);
    //Mergesort

    //Heapsort

    //Heapsort

    //Hashing

    //std::unordered_set

    //Graphs

    //Djikstras algrorithm

    //A* algorithm

    //Minimum spenntre

    //Huffman

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

template<typename T, size_t N>
void StdSort(T(&arr)[N])
{
    std::sort(std::begin(arr), std::end(arr));
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


