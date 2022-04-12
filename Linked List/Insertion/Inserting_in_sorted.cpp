#include<iostream>
#include<cstdio>
using namespace std;

struct Node
{
    int data;
    struct Node *n;
}*first;

void create(int A[], int n)
{
    int i;
    struct Node *t,*last;
    first= new Node; 
    first->data=A[0];
    first->n=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
       t= new Node;
       t->data=A[i];
       t->n=NULL; 
       last->n=t;
       last=t;
    }
}

void Display(struct Node *p)
{
    cout<<"\nElement in the linkedlist are: ";
    while(p)
    {
        cout<<p->data<<" ";
        p=p->n;
    }
}

void SortIns(struct Node *p, int x)
{
    struct Node *q,*t;
    t= new struct Node;
    t->data=x;
    t->n=NULL;
    q=NULL;

    if(first==NULL)
    {
        first=t;
        t->n=NULL;
    }
    else
    {
        while(p&& p->data<x)
        {
            q=p;
            p=p->n;
        }
        if(p==first)
        {
            t->n=first;
            first=t;
        }
        else
        {
            t->n=q->n;
            q->n=t;
        }
    }
}


int main()
{
    struct Node * temp;
    int A[5]={2,5,8,9,10};
    create(A,5);
    Display(first);
    
    SortIns(first,1);
    SortIns(first,6);
    SortIns(first,12);

    Display(first);

} 