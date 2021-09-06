#ifndef CHARNODE_H
#define CHARNODE_H


class CharNode
{
public:
    CharNode(char sign, CharNode* next);
    CharNode* GetNext();
    static int GetAmount();
    void Print();
    ~CharNode();
private:
    static int Amount;
    char Sign;
    CharNode* Next;
};

#endif // CHARNODE_H
