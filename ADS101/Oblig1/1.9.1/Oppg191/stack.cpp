#include "stack.h"

Stack::Stack()
{

}

void Stack::Pop(){
    CharNode* ut = data;
    data = ut->GetNext();
    delete ut;
}
void Stack::Push(CharNode* node){
    data = node;
}
CharNode* Stack::Top(){
    return data;
}
int Stack::Size(){
    return data->GetAmount();
}
void Stack::Empty(){

}
