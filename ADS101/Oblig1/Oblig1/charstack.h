#ifndef CHARSTACK_H
#define CHARSTACK_H
#include "charnode.h"

class CharStack
{
public:
    CharStack();
    void Pop();
    void Push(CharNode*);
    CharNode* Top();
    int Size();
    void Empty();
 private:
        CharNode* data;
};

#endif // CHARSTACK_H
