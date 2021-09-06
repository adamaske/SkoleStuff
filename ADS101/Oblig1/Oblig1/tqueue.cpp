#include "tqueue.h"

#include <iostream>
template<class T>
TQueue<T>::TQueue(){

}
template<class T>
T TQueue<T>::Front()
{
    return data[index-1];
}

template<class T>
T TQueue<T>::Back()
{
    return data[0];
}

template<class T>
void TQueue<T>::Push(T node)
{
    if(index == 10){
        std::cout << "Max amount of elements reached!" << std::endl;
        return;
    }

    //Check if the index is at 0, that means there are nothing in the array and set it to the node
    if(index == 0){
        data[0] = node;
        index++;
        return;
    }

    //Move every elenemt in the array one up
    T a;
    for(int i = index; i > 0; i--){
        a = data[i-1];
        data[i] = a;
    }
    //Set the 0 index of the array to the node because it is now cleared
    data[0] = node;
    //Add to the index to keep count
    index++;
}

template<class T>
void TQueue<T>::Pop()
{
    //Sets the front to null and reduces the index of the array
    //data[index -1 ] = NULL;
    index--;
}

template<class T>
int TQueue<T>::Size()
{
    //Returns the
    return index;
}
template class TQueue<int>;
