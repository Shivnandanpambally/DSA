#include<iostream>
using namespace std;
#ifndef QueueCpp_h
#define QueueCpp_h

template <class T>
class Node
{
public:
    Node<T> *lchild;
    T data;
    Node<T> *rchild;
};


template <class T>
class Queue
{   
private:
    int size;
    int front;
    int rear;
    Node<T> **Q; //double pointer one for array and one for node(it points to a node)

public:
    
    Queue(); //default constructor
    
    Queue(int x); //parameterized constructor
    
    ~Queue();  //Destuctor
    
    void Enqueue(Node<T>* x);
    
    Node<T>* Dequeue();
    
    int isEmpty();
    
};

template <class T>
Queue<T>::Queue(){
    size=0;
    front=0;
    rear=0;
}

template <class T>
Queue<T>::Queue(int x){
    size=x;
    front=0;
    rear=0;
    Q= new Node<T>*[size];
}

template <class T>
Queue<T>::~Queue(){
    delete[]Q;
}

template <class T>
void Queue<T>::Enqueue(Node<T>* x){
    if((rear+1)%size == front)
        cout<<"\nQueue is full";
    else{
        rear=(rear+1)%size;
        Q[rear]=x;
    }
}

template <class T>
Node<T>* Queue<T>::Dequeue(){
    Node<T>* x=NULL;
    if(front==rear)
        cout<<"\nQueue is Empty";
    else{
        front=(front+1)%size;
        x=Q[front];
    }
    return x;
}

template <class T>
int Queue<T>::isEmpty(){
    return (front==rear)? 1:0;
}

#endif