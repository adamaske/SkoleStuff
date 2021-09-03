#ifndef STACK_H
#define STACK_H


class Stack
{
public:
    Stack();
    void Pop();
    void Push(char);
    char Top();
    int Size();

   private:
    char data[10];
    int index;
};

#endif // STACK_H
