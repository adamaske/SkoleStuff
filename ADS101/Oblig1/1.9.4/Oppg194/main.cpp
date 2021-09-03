#include <iostream>
#include "stack.h"
#include "tstack.h"
using namespace std;

int main()
{
    Stack* s = new Stack();

    s->Push('a');
    s->Push('b');
    s->Push('c');
    s->Push('d');
    s->Push('e');

    while(s->Size() != 0){
        std::cout << s->Top() << std::endl;
        s->Pop();
    }

    TStack<int>* ts = new TStack<int>();

    ts->Push(1);
    ts->Push(3);
    ts->Push(1);
    ts->Push(2);

    while(ts->Size() != 0){
        std::cout << ts->Top() << std::endl;
        ts->Pop();
    }
    return 0;
}
