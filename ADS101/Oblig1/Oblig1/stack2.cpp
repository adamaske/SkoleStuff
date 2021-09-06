#include "stack2.h"

Stack2::Stack2()
{

}

void Stack2::Pop()
{
    index--;
}

void Stack2::Push(char node)
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

char Stack2::Top()
{
    return data[index-1];
}

int Stack2::Size()
{
    return index;
}
