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

//*******************************************************************************************************//Node part over

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

//*******************************************************************************************************//stack part over
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

//*******************************************************************************************************//Queue part over

template <class T>
class Binary_tree{
public:
    Node<T> *root;
    Binary_tree();
    ~Binary_tree();
    void destroy(Node<T>* p);
    void creat();
    void preorder(Node<T> *p);
    void inorder(Node<T> *p);
    void postorder(Node<T> *p);
    void Ipreorder(Node<T> *p);
    void Iinorder(Node<T> *p);
    void Ipostorder(Node<T> *p);
    void levelorder(Node<T> *p);
    int height(Node<T> *p);
    int count(Node<T>*p);
    int count_0(Node<T>*p);//Number of nodes with degree 0
    int count_1(Node<T>*p);//Number of nodes with degree 1
    int count_2(Node<T>*p);//Number of nodes with degree 2
    int count_12(Node<T>*p);//Number of nodes with degree 1 or 2
};

template <class T>
Binary_tree<T>::Binary_tree(){
    root=NULL;
}

template <class T>
Binary_tree<T>::~Binary_tree(){
    destroy(root);
}

template <class T>
void Binary_tree<T>::destroy(Node<T>* p){
    if (p != NULL) {
        destroy(p->lchild);
        destroy(p->rchild);
        delete p;
    }
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
void Binary_tree<T>::Ipreorder(Node<T> *p){
    stack<T> S(10);
    while(p!=NULL || !S.isEmpty()){
        if(p!=NULL){
            cout<<p->data<<" ";
            S.Push(p);
            p=p->lchild;
        }
        else{
            p=S.Pop();
            p=p->rchild;
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
void Binary_tree<T>::Iinorder(Node<T> *p){
    stack<T> S(10);
    while(p!=NULL || !S.isEmpty()){
        if(p!=NULL){
            S.Push(p);
            p=p->lchild;
        }
        else{
            p=S.Pop();
            cout<<p->data<<" ";
            p=p->rchild;
        }
    }
}

template <class T>
void Binary_tree<T>::Ipostorder(Node<T> *p){
    stack<T> S(10);
    long long int temp;
    while(p!=NULL || !S.isEmpty()){
        if(p!=NULL){
            S.Push(p);
            p=p->lchild;
        }
        else{
            temp=(long long int)(S.Pop());
            if(temp>0){
                S.Push((Node<T>*)(-temp));
                p=((Node<T>*)temp)->rchild;
            }
            else{
                cout<<((Node<T>*)(-temp))->data<<" ";
                p=NULL;
            }
        }
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

template <class T>
int Binary_tree<T>::count(Node<T>*p){
    if(p)
        return count(p->lchild)+count(p->rchild)+1;
    else
        return 0;
}

template<class T>
int Binary_tree<T>::count_0(Node<T>*p){
    if(!p)
        return 0;
    else{
        if(!p->lchild  && !p->rchild)
            return count_0(p->lchild)+count_0(p->rchild)+1;
        else
            return count_0(p->lchild)+count_0(p->rchild);
    }
}

template<class T>
int Binary_tree<T>::count_1(Node<T>*p){
    if(!p)
        return 0;
    else{
        if((!p->lchild && p->rchild) || (p->lchild && !p->rchild))
            return count_1(p->lchild)+count_1(p->rchild)+1;
        else
            return count_1(p->lchild)+count_1(p->rchild);
    }
}

template<class T>
int Binary_tree<T>::count_2(Node<T>*p){
    if(!p)
        return 0;
    else{
        if(p->lchild  && p->rchild)
            return count_2(p->lchild)+count_2(p->rchild)+1;
        else
            return count_2(p->lchild)+count_2(p->rchild);
    }
}

template<class T>
int Binary_tree<T>::count_12(Node<T>*p){
    if(!p)
        return 0;
    else{
        if(p->lchild  || p->rchild)
            return count_12(p->lchild)+count_12(p->rchild)+1;
        else
            return count_12(p->lchild)+count_12(p->rchild);
    }
}
    
//*******************************************************************************************************//Binary_tree part over

int main()
{  
    Binary_tree<int> T;
    T.creat();
   
    cout<<endl<<endl;
    cout<<"Recursive"<<endl;
    cout<<"Preorder arrangement: "; 
    T.preorder(T.root);
    cout<<endl;
    cout<<"inorder arrangement: ";
    T.inorder(T.root);
    cout<<endl;
    cout<<"Postorder arrangement: ";
    T.postorder(T.root);
    cout<<endl;
    cout<<endl<<endl;
    
    cout<<"Iterative"<<endl;
    cout<<"Preorder arrangement: "; 
    T.Ipreorder(T.root);
    cout<<endl;
    cout<<"inorder arrangement: ";
    T.Iinorder(T.root);
    cout<<endl;
    cout<<"Postorder arrangement: ";
    T.Ipostorder(T.root);
    cout<<endl;
    cout<<endl<<endl;
    
    cout<<"Levelorder arrangement: ";
    T.levelorder(T.root);
    cout<<endl;
    cout<<"Height of the tree: ";
    cout<<T.height(T.root);
    cout<<endl;
    cout<<"Number of nodes in the tree: ";
    cout<<T.count(T.root);
    cout<<endl;
    
    cout<<"Number of nodes with degree 0: ";
    cout<<T.count_0(T.root);
    cout<<endl;
    
    cout<<"Number of nodes with degree 1: ";
    cout<<T.count_1(T.root);
    cout<<endl;
    
    cout<<"Number of nodes with degree 2: ";
    cout<<T.count_2(T.root);
    cout<<endl;
    
    cout<<"Number of nodes with degree 1 or 2: ";
    cout<<T.count_12(T.root);
    cout<<endl;
   
    return 0;
}





