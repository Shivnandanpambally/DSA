#include<iostream>
#include "QueueCpp.h"
#include "StackCpp.h"
using namespace std;

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
    void Ipreorder(Node<T> *p);
    void Iinorder(Node<T> *p);
    void Ipostorder(Node<T> *p);
    void levelorder(Node<T> *p);
    int height(Node<T> *p);
    int count(Node<T>*p);
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
   
    return 0;
}
