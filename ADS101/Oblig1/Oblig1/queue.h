#ifndef QUEUE_H
#define QUEUE_H


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
     char data[10];
     int index = 0;
};

#endif // QUEUE_H
