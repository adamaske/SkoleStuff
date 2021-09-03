#include "stack.h"

Stack::Stack()
{

}

void Stack::Pop()
{
    index--;
}

void Stack::Push(char node)
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

char Stack::Top()
{
    return data[index-1];
}

int Stack::Size()
{
    return index;
}
