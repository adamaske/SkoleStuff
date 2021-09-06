#include "queue.h"
#include <iostream>
Queue::Queue()
{
    index = 0;
}

char Queue::Front()
{
    //returns index-1 because the index is always 1 larger than the amount of elements in the array
    return data[index-1];
}

char Queue::Back()
{
    //Returns the bottom
    return data[0];
}

void Queue::Push(char node)
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
    char a;
    for(int i = index; i > 0; i--){
        a = data[i-1];
        data[i] = a;
    }
    //Set the 0 index of the array to the node because it is now cleared
    data[0] = node;
    //Add to the index to keep count
    index++;
}

void Queue::Pop()
{
    //Sets the front to null and reduces the index of the array
    data[index -1 ] = NULL;
    index--;
}

int Queue::Size()
{
    //Returns the index
    return index;
}
