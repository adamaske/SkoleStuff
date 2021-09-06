#ifndef STACK2_H
#define STACK2_H


class Stack2
{
public:
    Stack2();
    void Pop();
    void Push(char);
    char Top();
    int Size();

   private:
    char data[10];
    int index;
};

#endif // STACK2_H
