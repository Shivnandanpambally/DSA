#include <iostream>
using namespace std;

template <class T>
class Node{
public:
    Node<T>* lchild;
    T data;
    Node<T>* rchild;
};

template <class T>
class Binary_search_tree{
public:
    Node<T>* root;
    Binary_search_tree();
    ~Binary_search_tree();
    void destroy(Node<T>* p);
    void insert(T x);
    Node<T>* rInsert(Node<T>* p, T x);
    Node<T>* search(T key);
    Node<T>* rSearch(Node<T>* p, T key);
    void Display(Node<T>* p); //It will use recursive method to display
    
    int Height(Node<T>* p);
    Node<T>* Inpre(Node<T>* p);
    Node<T>* Insucc(Node<T>* p);
    Node<T>* Delete(Node<T>*p, T key);
};

template <class T>
Binary_search_tree<T>::Binary_search_tree(){
    root=NULL;
}

template <class T>
Binary_search_tree<T>::~Binary_search_tree(){
    destroy(root);
}

template <class T>
void Binary_search_tree<T>::destroy(Node<T>* p){
    if(p){
        destroy(p->lchild);
        destroy(p->rchild);
        delete p;
    }
}

template <class T>
void Binary_search_tree<T>::insert(T x){
    Node<T>* p=root;
    Node<T>* t=NULL;
    if(p==NULL){
        root = new Node<T>;
        root->data=x;
        root->lchild=root->rchild=NULL;
        return;
    }
    while(p)
    {
        if(x < p->data){
            t=p;
            p=p->lchild;
        }
        else if(x > p->data){
            t=p;
            p=p->rchild;
        }
        else
            return;  //return when (key = p->data)
    }
    p=new Node<T>;
    p->data=x;
    p->lchild=p->rchild=NULL;
    if(p->data < t->data)
        t->lchild=p;
    else
        t->rchild=p;
}

template <class T>
Node<T>* Binary_search_tree<T>::rInsert(Node<T>* p, T x){
    Node<T>* t;
    if(root == NULL){
        t=new Node<T>;
        t->data=x;
        t->lchild=t->rchild=NULL;
        root=t;
        return t;
    }
    if(p==NULL){
        t=new Node<T>;
        t->data=x;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(x < p->data)
        p->lchild=rInsert(p->lchild, x);
    else if(x > p->data)
        p->rchild=rInsert(p->rchild, x);
    else
        cout<<"Element already present in tree"<<endl;
    
    return p; 
}

template <class T>
Node<T>* Binary_search_tree<T>::search(T key){
    Node<T>* p=root;
    while(p){
        if(key == p->data)
            return p;
        else if(key < p->data)
            p=p->lchild;
        else
            p=p->rchild;
    }
    return NULL;
}

template <class T>
Node<T>* Binary_search_tree<T>::rSearch(Node<T>* p, T key){
    if(key == p->data)
        return p;
    else if(key < p->data)
        return rSearch(p->lchild, key);
    else if(key > p->data)
        return rSearch(p->rchild, key);
    else 
        return NULL;
}

template <class T>
void Binary_search_tree<T>::Display(Node<T>* p){
    if(p){
        Display(p->lchild);
        cout<<p->data<<" ";
        Display(p->rchild);
    }
}

template <class T>
int Binary_search_tree<T>::Height(Node<T>* p)
{
    int x,y;
    if(p==NULL)
        return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    
    return (x>y)? x+1:y+1;
}

template <class T>
Node<T>* Binary_search_tree<T>::Inpre(Node<T>* p)
{
    while(p && p->rchild)
        p=p->rchild;
    
    return p;
}

template <class T>
Node<T>* Binary_search_tree<T>::Insucc(Node<T>* p)
{
    while(p && p->lchild)
        p=p->lchild;
    
    return p;
}

template <class T>
Node<T>* Binary_search_tree<T>::Delete(Node<T>* p, T key)
{
    if(p==NULL)
        return NULL;  //Key not present
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root=NULL;
        delete p;
        return NULL;
    }
    
    Node<T>* q;
    if(key<p->data)
        p->lchild=Delete(p->lchild,key);
    else if(key>p->data)
        p->rchild=Delete(p->rchild,key);
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=Inpre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=Insucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;  //Just for maintaining the link it will return its own link to parent node
}



int main(){
    Binary_search_tree<int> B;
    Node<int>* temp1=NULL;
    Node<int>* temp2=NULL;
    B.insert(9);
    B.insert(15);
    B.insert(5);
    B.rInsert(B.root,20);
    B.insert(16);
    B.insert(8);
    B.insert(12);
    B.insert(3);
    B.insert(6);
    
    temp1=B.search(16);
    if(temp1)
        cout<<"Element found "<<temp1->data<<endl;
    else
        cout<<"Element not exixst"<<endl;
        
    temp2=B.search(22);
    if(temp2)
        cout<<"Element found "<<temp2->data<<endl;
    else
        cout<<"Element not exixst"<<endl;

        
    cout<<"Elements of tree are: ";
    B.Display(B.root);
    cout<<endl;
    
    B.Delete(B.root, 15);
    cout<<"Elements of tree are: ";
    B.Display(B.root);
    cout<<endl;
    
    B.Delete(B.root, 8);
    cout<<"Elements of tree are: ";
    B.Display(B.root);
    cout<<endl;
    
    return 0;
    
}



























