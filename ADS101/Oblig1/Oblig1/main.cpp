#include <iostream>
#include "charnode.h"
#include "charstack.h"
#include "tstack.h"
#include "queue.h"
#include "tqueue.h"
#include "stack2.h"
#include "tstack2.h"
#include "math.h"
#include <chrono>
#include <algorithm>
#include <array>
#include <iterator>

template<typename T, size_t N>
void SelectionSort(T (&arr)[N]){

    for (int i = 0; i < N; i++){
        arr[i] = rand();
    }

    auto start = std::chrono::high_resolution_clock::now();
    //1. Selection sort
    for(auto i = 0; i < N-1; i++){
        for(auto j = i +1; j < N; j++){
            if(arr[j] > arr[i]){
                std::swap(arr[j], arr[i]);
            }
        }
    }

    //Get the end
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> totalTime = end-start;
    std::chrono::nanoseconds totalTimeNano = std::chrono::duration_cast<std::chrono::nanoseconds>(totalTime);

    totalTime += totalTimeNano;
    std::cout << "With " << N << " elements, it took " << totalTime.count() << " seconds to sort them doing the selection sort alagorithm." << std::endl;

    //2. Std::sort
    start = std::chrono::high_resolution_clock::now();

    std::sort(std::begin(arr), std::end(arr));

    end = std::chrono::high_resolution_clock::now();
    totalTime = end-start;
    totalTimeNano = std::chrono::duration_cast<std::chrono::nanoseconds>(totalTime);
    totalTime += totalTimeNano;
    std::cout << "With " << N << " elements, it took " << (double)totalTime.count() << " seconds to sort them using std::sort." << std::endl;
        /*for(int i = 0; i < n; i++){
            std::cout << array[i] << ", ";
        }*/
}

int main()
{
    //Opgg 1.9.1
    std::cout << "Oppgave 1.9.1" << std::endl;
    CharStack* s = new CharStack();
    CharNode* c = new CharNode('a', nullptr);
    c = new CharNode('b', c);
    c = new CharNode('c', c);
    c = new CharNode('d', c);
    c = new CharNode('e', c);
    c = new CharNode('f', c);

    s->Push(c);
    //Prints every on top and pop until the stack is empty
    while(s->Size() != 0){
        s->Top()->Print();
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

    ts->Push(tc);

    while(ts->Size() != 0){
       ts->Top()->Print();
       ts->Pop();
       std::cout << "Stack size after pop: " << s->Size() << std::endl;
     }
    delete ts;
    //Opgg 1.9.3
    std::cout << "Oppgave 1.9.3" << std::endl;
    Queue* q = new Queue();
    q->Push('a');
    q->Push('b');
    q->Push('c');
    q->Push('d');
    q->Push('e');

    std::cout << "The front of the queue is: " << q->Front() << std::endl << "The current back of the queue is: " << q->Back() << std::endl;
    //Print each front of the array and pop it
    while(q->Size() != 0){
        std::cout << q->Front() << std::endl;
        q->Pop();
    }

    TQueue<int>* tq = new TQueue<int>();
    tq->Push(1);
    tq->Push(14);
    tq->Push(123);
    tq->Push(5463);
    tq->Push(9073);

     while(tq->Size() != 0){
         std::cout << tq->Front() << std::endl;
         tq->Pop();
     }

    //Oppgg 1.9.4
     std::cout << "Oppgave 1.9.4" << std::endl;
    Stack2* s2 = new Stack2();
    s2->Push('a');
    s2->Push('b');
    s2->Push('c');
    s2->Push('d');
    s2->Push('e');
    s2->Push('f');

    while(s2->Size() != 0){
        std::cout << s2->Top() << std::endl;
        s2->Pop();
    }
    //Template stack
    TStack2<int>* ts2 = new TStack2<int>();
    ts2->Push(1);
    ts2->Push(3);
    ts2->Push(1);
    ts2->Push(2);

    while(ts2->Size() != 0){
        std::cout << ts2->Top() << std::endl;
        ts2->Pop();
    }
    //Oppgg 2.3.1
    std::cout << "Oppgave 2.3.1" << std::endl;
    int a[10];
    int b[100];
    int ca[1000];
    int d[15000];
    int e[20000];
    SelectionSort(a);
    SelectionSort(b);
    SelectionSort(ca);
    SelectionSort(d);
    SelectionSort(e);
    return 0;
}


