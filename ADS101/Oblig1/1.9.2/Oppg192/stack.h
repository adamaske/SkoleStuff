#ifndef STACK_H
#define STACK_H

#include "charnode.h"
template<class T>
class Stack
{
public:
    Stack();
    //Pop first element
    void Pop();
    //Add new element
    void Push(T*);
    //Get the newest
    T* Top();
    //Get amount of elements
    int Size();
    void Empty();
private:
    T* data;
};
template<class T>
Stack<T>::Stack()
{

}
template<class T>
void Stack<T>::Pop(){
    T* ut = data;
    data = ut->GetNext();
    delete ut;
}
template<class T>
void Stack<T>::Push(T* node){
    data = node;
}
template<class T>
T* Stack<T>::Top(){
    return data;
}
template<class T>
int Stack<T>::Size(){
    return data->GetAmount();
}
template<class T>
void Stack<T>::Empty(){

}

#endif // STACK_H
