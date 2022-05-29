#include<iostream>
using namespace std;

template <class T>
class Node
{
public:
    Node<T>* lchild;
    T data;
    Node<T>* rchild;
    T height;
};

template <class T>
class AVL
{
public:
    Node<T>* root;
    AVL();
    ~AVL();
    void Destroy(Node<T> *p);
    Node<T>* Rinsert(Node<T>* p, T key);
    int NodeHeight(Node<T>* p);
    int BalanceFactor(Node<T>* p);
    Node<T>* LLRotation(Node<T>* p);
    Node<T>* LRRotation(Node<T>* p);
    Node<T>* RLRotation(Node<T>* p);
    Node<T>* RRRotation(Node<T>* p);
    void display(Node<T>* p);
    void preorder(Node<T>* p);
    
    
    Node<T>* Inpre(Node<T> *p);
    Node<T>* Insucc(Node<T> *p);
    Node<T>* Delete(Node<T> *p, T key);
};

template <class T>
AVL<T>::AVL()
{
    root=NULL;
}

template <class T>
AVL<T>::~AVL()
{
    Destroy(root);    
}

template <class T>
void AVL<T>::Destroy(Node<T>* p)
{
    if(p)
    {
        Destroy(p->lchild);
        Destroy(p->rchild);
        delete p;
    }
}

template <class T>
int AVL<T>::NodeHeight(Node<T> *p)
{
    int hl, hr;
    hl =(p&&p->lchild)?p->lchild->height:0;
    hr =(p&&p->rchild)?p->rchild->height:0;
    
    return (hl>hr)?hl+1:hr+1;
}

template <class T>
int AVL<T>::BalanceFactor(Node<T> *p)
{
    int hl, hr;
    hl =(p&&p->lchild)?p->lchild->height:0;
    hr =(p&&p->rchild)?p->rchild->height:0;  
    
    return hl-hr;
}

template <class T>
Node<T>* AVL<T>::LLRotation(Node<T>* p)
{
    Node<T> *pl, *plr;
    pl=p->lchild;
    plr=pl->rchild;
    
    pl->rchild=p;
    p->lchild=plr;
    
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(p==root)
        root=pl;
    
    return pl;
}

template <class T>
Node<T>* AVL<T>::LRRotation(Node<T>* p)
{
    Node<T> *pl,*pr,*plr,*plrl,*plrr;
    pl=p->lchild;
    pr=p->rchild;
    plr=pl->rchild;
    plrl=plr->lchild;
    plrr=plr->rchild;
    
    plr->lchild=pl;
    plr->rchild=p;
    pl->rchild=plrl;
    p->lchild=plrr;
    
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    plr->height=NodeHeight(plr);

    if(p==root)
        root=plr;
    
    return plr;
}

template <class T>
Node<T>* AVL<T>::RLRotation(Node<T>* p)
{
    Node<T> *pl,*pr,*prl,*prll,*prlr;
    pl=p->lchild;
    pr=p->rchild;
    prl=pr->lchild;
    prll=prl->lchild;
    prlr=prl->rchild;
    
    prl->lchild=p;
    prl->rchild=pr;
    p->rchild=prll;
    pr->lchild=prlr;
    
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pl);
    prl->height=NodeHeight(prl);

    if(p==root)
        root=prl;
    
    return prl;
}

template <class T>
Node<T>* AVL<T>::RRRotation(Node<T>* p)
{
    Node<T> *pr, *prl;
    pr=p->rchild;
    prl=pr->lchild;
    
    pr->lchild=p;
    p->rchild=prl;
    
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);

    if(p==root)
        root=pr;
    
    return pr;
}

template <class T>
Node<T>* AVL<T>::Rinsert(Node<T> *p, T key)
{
    Node<T> *t;
    if(root==NULL)
    {
        root=new Node<T>;
        root->data=key;
        root->height=1;
        root->lchild=root->rchild=NULL;
        return root;
    }
    if(p==NULL)
    {
        t=new Node<T>;
        t->data=key;
        t->height=1;
        t->lchild=t->rchild=NULL;
        return t;
    }
    
    if(key<p->data)
        p->lchild=Rinsert(p->lchild, key);
    else if(key>p->data)
        p->rchild=Rinsert(p->rchild, key);
    
    p->height=NodeHeight(p);
    
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RLRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);
    return p;
}

template <class T>
void AVL<T>::display(Node<T>* p)
{
    if(p)
    {
        display(p->lchild);
        cout<<p->data<<" ";
        display(p->rchild);
    }
}

template <class T>
void AVL<T>::preorder(Node<T>* p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}


template <class T>
Node<T>* AVL<T>::Inpre(Node<T>* p)
{
    while(p && p->rchild)
        p=p->rchild;
    
    return p;
}

template <class T>
Node<T>* AVL<T>::Insucc(Node<T>* p)
{
    while(p && p->lchild)
        p=p->lchild;
    
    return p;
}

template <class T>
Node<T>* AVL<T>::Delete(Node<T>* p, T key)
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
        if(NodeHeight(p->lchild)>NodeHeight(p->rchild))
        {
            q=Inpre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    
    p->height=NodeHeight(p);
    
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1) //L1 rotation
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1) //L-1 rotation
        return LRRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==0) //L0 rotation
        return LLRotation(p);
    if(BalanceFactor(p)==-2 && BalanceFactor(p->lchild)==-1) //R1 rotation
        return RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->lchild)==1) //R-1 rotation
        return RLRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->lchild)==0) //R0 rotation
        return RRRotation(p);
        
    return p;  
}

int main()
{
    AVL<int> A;
    A.Rinsert(A.root,10);
    A.Rinsert(A.root,20);
    A.Rinsert(A.root,30);
    A.Rinsert(A.root,25);
    A.Rinsert(A.root,28);
    A.Rinsert(A.root,27);
    A.Rinsert(A.root,5);
    
    A.display(A.root);
    
    cout<<endl<<"Root of the tree: "<<A.root->data<<endl;;
    
    A.Delete(A.root, 28);
    
    A.display(A.root);
    cout<<endl;
    A.preorder(A.root);
   

}



