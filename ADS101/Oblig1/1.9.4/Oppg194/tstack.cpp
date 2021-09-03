#include "tstack.h"
template <class T>
TStack<T>::TStack()
{

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
    if(index == 0){
        data[0] = 0;
        index++;
    }
     //Move every element one step up in the array
    char a;
    for(int i = index; i > 0; i--){
        a = data[i-1];
        data[i] = a;
    }
    data[0] = node;
    index++;

}
template <class T>
T TStack<T>::Top()
{
    return data[index-1];
}
template <class T>
int TStack<T>::Size()
{
    return index;
}
template class TStack<int>;
