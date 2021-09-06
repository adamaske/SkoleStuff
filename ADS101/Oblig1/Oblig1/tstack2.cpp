#include "tstack2.h"
template <class T>
TStack2<T>::TStack2()
{

}
template <class T>
void TStack2<T>::Pop()
{
    index--;
}
template <class T>
void TStack2<T>::Push(T node)
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
T TStack2<T>::Top()
{
    return data[index-1];
}
template <class T>
int TStack2<T>::Size()
{
    return index;
}
template class TStack2<int>;
