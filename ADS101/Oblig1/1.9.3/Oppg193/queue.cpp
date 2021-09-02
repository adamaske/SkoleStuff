#include "queue.h"
#include <iostream>
Queue::Queue()
{
    Front = nullptr;
    Back = nullptr;
}

void Queue::Push(CharNode* node)
{
    //If back exists, give it the new back as it's next
    if(Back){
        Back->SetNext(node);
    }
    //New set the new Node to Back
    Back = node;
    //If there is no Front, this is the new Front and Back
    if(!Front){
        Front = Back;
    }
}

void Queue::Pop()
{
    //Remove first
    if(Front){
        CharNode* ut = Front;
        //Try to get the next from Front and set it to new front
        Front = Front->GetNext();
        delete ut;
    }
    if(!Front && Back){
        Front = Back;
    }

    //If it got a nullptr from GetNext(), set back to null also because its empty
    if(!Front){
        Back = nullptr;
    }

}

int Queue::Size()
{
    return Front->GetAmount();
}
