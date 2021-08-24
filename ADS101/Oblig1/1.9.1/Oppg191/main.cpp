#include <iostream>
#include "stack.h"
#include "charnode.h"

int main()
{
    Stack* s = new Stack();
    CharNode* c = new CharNode('a', nullptr);
    c = new CharNode('b', c);
    c = new CharNode('c', c);
    c = new CharNode('d', c);
    c = new CharNode('e', c);
    c = new CharNode('f', c);

    s->Push(c);

    while(s->Top()!= nullptr){
        s->Top()->Print();
        s->Pop();
        std::cout << "Stack size after pop: " << s->Size() << std::endl;
    }
    return 0;
}
