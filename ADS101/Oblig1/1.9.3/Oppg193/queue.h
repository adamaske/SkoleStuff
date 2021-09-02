#ifndef QUEUE_H
#define QUEUE_H

#include "charnode.h"
class Queue
{
public:
    Queue();

    CharNode* Front;
    CharNode* Back;

    void Push(CharNode*);
    void Pop();

    int Size();
private:
    CharNode* first;
    CharNode* back;
};

#endif // QUEUE_H
