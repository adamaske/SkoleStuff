#ifndef STACK_H
#define STACK_H

#include "charnode.h"
template<class T>
class Stack
{
public:
    Stack();
    void Pop();
    void Push(T*);
    T Top();
    int Size();
    void Empty();
private:
    T* data;
};


#endif // STACK_H
