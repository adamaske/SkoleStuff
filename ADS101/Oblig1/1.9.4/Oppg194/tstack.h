#ifndef TSTACK_H
#define TSTACK_H

template<class T>
class TStack
{
public:
    TStack();
    void Pop();
    void Push(T);
    T Top();
    int Size();

   private:
    T data[10];
    int index;
};

#endif // TSTACK_H
