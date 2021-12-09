#pragma once
#include <iostream>
#include <vector>
#include "CharNode.h"
#define SIZE 100
template<class T>
class TStack
{
public:
    TStack();
    void Pop();
    void Push(T);
    T Top();
    int Size();
    bool Empty();
private:
    T data[SIZE];
    int index;
};

template <class T>
TStack<T>::TStack() {
    index = 0;
}
template <class T>
void TStack<T>::Pop()
{
    index--;
}
template <class T>
void TStack<T>::Push(T node)
{
    //Check if the 0 element has a char
    if (index == 0) {
        data[0] = node;
        index++;
    }
    //Move every element one step up in the array
    T a;
    for (int i = index; i > 0; i--) {
        a = data[i - 1];
        data[i] = a;
    }
    data[0] = node;
    index++;

}
template <class T>
T TStack<T>::Top()
{
    return data[index - 1];
}
template <class T>
int TStack<T>::Size()
{
    return index;
}

template<class T>
inline bool TStack<T>::Empty()
{
    if (Size() == 0) {
        return true;
    }
    else {
        return false;
    }
    
}
