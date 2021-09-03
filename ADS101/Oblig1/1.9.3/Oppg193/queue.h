#ifndef QUEUE_H
#define QUEUE_H

#define MAXSIZE 10
class Queue
{
public:
    Queue();

    char Front();
    char Back();

    void Push(char);
    void Pop();

    int Size();
private:
    char data[MAXSIZE];
    int index = 0;
};

#endif // QUEUE_H
