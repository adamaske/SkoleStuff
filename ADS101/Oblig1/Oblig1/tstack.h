#ifndef TSTACK_H
#define TSTACK_H

template<class T>
class TStack
{
public:
    TStack();
    void Pop();
    void Push(T*);
    T* Top();
    int Size();
    void Empty();
private:
    T* data;
};
template<class T>
TStack<T>::TStack()
{

}
template<class T>
void TStack<T>::Pop(){
    T* ut = data;
    data = ut->GetNext();
    delete ut;
}
template<class T>
void TStack<T>::Push(T* node){
    data = node;
}
template<class T>
T* TStack<T>::Top(){
    return data;
}
template<class T>
int TStack<T>::Size(){
    return data->GetAmount();
}
template<class T>
void TStack<T>::Empty(){

}

#endif // TSTACK_H
