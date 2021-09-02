#include <iostream>
#include "charnode.h"
#include "queue.h"


int main()
{
    Queue* q = new Queue();

    CharNode* a;
    a = new CharNode('a', nullptr);
    q->Push(a);
    a = new CharNode('b', nullptr);
    q->Push(a);
    a = new CharNode('c', nullptr);
    q->Push(a);
    a = new CharNode('d', nullptr);
    q->Push(a);
    a = new CharNode('e', nullptr);
    q->Push(a);

    while(q->Size() > 0){
        q->Front->Print();
        q->Pop();
    }

    return 0;
}
