#include<iostream>
#include "QueueCpp.h"
using namespace std;

#ifndef StackCpp_h
#define StackCpp_h

template <class T>
class stack
{
private:
    T size;
    T top;
    Node<T> **S;
public:
    stack();
    stack(T x);
    ~stack();
    void Push(Node<T>* x);
    Node<T>* Pop();
    int isEmpty();
};

template <class T>
stack<T>::stack(){
    size=0;
    top=-1;
}

template <class T>
stack<T>::stack(T x){
    size=x;
    top=-1;
    S=new Node<T>* [size];
}

template <class T>
stack<T>::~stack(){
    delete []S;
}

template <class T>
void stack<T>::Push(Node<T>* x)
{
    if(top==size-1)
        cout<<"\nstack overflow\n";
    else
    {
        top++;
        S[top]=x;
    }
}

template <class T>
Node<T>*stack<T>::Pop()
{
    Node<T>* x=NULL;
    if(top == -1)
        cout<<"\nStack underflow";
    else{
        x=S[top];
        top--;
    }
    return x;
}

template <class T>
int stack<T>::isEmpty(){
    return (top==-1)? 1:0;
}

#endif