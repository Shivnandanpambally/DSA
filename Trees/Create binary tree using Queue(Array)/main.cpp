#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    Node<T> *lchild;
    T data;
    Node<T> *rchild;
};

//*******************************************************************************************************//

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

//*******************************************************************************************************//

template <class T>
class Binary_tree{
public:
    Node<T> *root;
    Binary_tree();
    ~Binary_tree();
    void creat();
    void preorder(Node<T> *p);
    void inorder(Node<T> *p);
    void postorder(Node<T> *p);
    void levelorder(Node<T> *p);
    int height(Node<T> *p);
};

template <class T>
Binary_tree<T>::Binary_tree(){
    root=NULL;
}

template <class T>
Binary_tree<T>::~Binary_tree(){
    delete root;
}

template <class T>
void Binary_tree<T>::creat(){
    Node<T> *p,*t;
    Queue<T> Q(100);
    int x;
    cout<<"\nEnter the value of root: ";
    cin>>x;
    root=new Node<T>;
    root->data=x;
    root->rchild=root->lchild=NULL;
    Q.Enqueue(root);//adiing root address to Queue
    while(!Q.isEmpty()){
        p=Q.Dequeue();
        cout<<"\nEnter left child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){
           t=new Node<T>;
           t->data=x;
           t->lchild=t->rchild=NULL;
           p->lchild=t;
           Q.Enqueue(t);
        }
        cout<<"\nEnter right child of  "<<p->data<<": ";
        cin>>x;
        if(x!=-1){
           t=new Node<T>;
           t->data=x;
           t->lchild=t->rchild=NULL;
           p->rchild=t;
           Q.Enqueue(t);
        }
    }
 
} 

template <class T>
void Binary_tree<T>::preorder(Node<T> *p){
    if(p){
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

template <class T>
void Binary_tree<T>::inorder(Node<T> *p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

template <class T>
void Binary_tree<T>::postorder(Node<T> *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

template <class T>
void Binary_tree<T>::levelorder(Node<T> *p){
    Queue<T> Q(100);
    Q.Enqueue(p);
    cout<<p->data<<" ";
    while(!Q.isEmpty()){
        p=Q.Dequeue();
        if(p->lchild!=NULL){
            Q.Enqueue(p->lchild);
            cout<<p->lchild->data<<" ";
        }
        if(p->rchild!=NULL){
            Q.Enqueue(p->rchild);
            cout<<p->rchild->data<<" ";
        }
    }
}

template <class T>
int Binary_tree<T>::height(Node<T> *p){
    int x=0,y=0;
    if(p==NULL)
        return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}
    

int main()
{  
    Binary_tree<int> T;
    T.creat();
   
    T.preorder(T.root);
    cout<<endl;
    T.inorder(T.root);
    cout<<endl;
    T.postorder(T.root);
    cout<<endl;
    T.levelorder(T.root);
    cout<<endl;
    cout<<T.height(T.root);
    cout<<endl;
   
    return 0;
}
