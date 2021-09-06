#ifndef TQUEUE_H
#define TQUEUE_H


template<class T>
class TQueue
{
public:
    TQueue<T>();

    T Front();
    T Back();

    void Push(T);
    void Pop();

    int Size();
private:
    T data[10];
    int index = 0;
};

#endif // TQUEUE_H
