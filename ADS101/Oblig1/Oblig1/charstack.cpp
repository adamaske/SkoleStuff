#include "charstack.h"


CharStack::CharStack()
{

}

void CharStack::Pop(){
    //Temp Charnode to delete, new data is temp's next
    CharNode* ut = data;
    data = ut->GetNext();
    delete ut;
}

void CharStack::Push(CharNode* node){
    data = node;
}
CharNode* CharStack::Top(){
    return data;
}
int CharStack::Size(){
    return data->GetAmount();
}
void CharStack::Empty(){

}
