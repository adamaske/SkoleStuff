#pragma once
class CharNode
{
public:
    CharNode(char sign = 'A', CharNode* next = nullptr);
    CharNode* GetNext();
    static int GetAmount();
    void Print();
    ~CharNode();
private:
    static int Amount;
    char Sign;
    CharNode* Next;
};

