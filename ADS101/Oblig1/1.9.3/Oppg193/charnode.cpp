#include "charnode.h"
#include <iostream>

int CharNode::Amount;
CharNode::CharNode(char sign, CharNode* next) : Sign(sign), Next(next)
{
    if(next){
         Amount++;
    }

}

CharNode* CharNode::GetNext(){
    return Next;
}

void CharNode::SetNext(CharNode* node)
{
    if(!Next){
        Next = node;
        Amount++;
    }
}
int CharNode::GetAmount(){
    return Amount;
}

void CharNode::Print(){
    std::cout << Sign << ", ";
}

CharNode::~CharNode(){
    Amount--;
}
