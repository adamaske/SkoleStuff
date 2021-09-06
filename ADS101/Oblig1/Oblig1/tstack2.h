#ifndef TSTACK2_H
#define TSTACK2_H

template<class T>
class TStack2
{
public:
    TStack2();
    void Pop();
    void Push(T);
    T Top();
    int Size();

private:
    T data[10];
    int index;
};

#endif // TSTACK2_H
