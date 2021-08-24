#ifndef STACK_H
#define STACK_H

#include "charnode.h"
class Stack
{
public:
    Stack();
    void Pop();
    void Push(CharNode*);
    CharNode* Top();
    int Size();
    void Empty();
private:
    CharNode* data;
};

#endif // STACK_H
