#include <iostream>

#include "queue.h"
#include "tqueue.h"

int main()
{
    Queue* q = new Queue();

    q->Push('a');
    q->Push('b');
    q->Push('c');
    q->Push('d');
    q->Push('e');

    std::cout << "The front of the queue is: " << q->Front() << std::endl << "The current back of the array is: " << q->Back() << std::endl;
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
    return 0;
}
