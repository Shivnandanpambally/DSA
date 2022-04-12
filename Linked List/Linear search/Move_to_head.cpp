#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
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

struct Node * Search(struct Node *p, int key)
{
    struct Node *q;
    while(p)
    {
        if(key==p->data)
        {
            q->n=p->n;
            p->n=first;
            first=p;
            return p;
        }    
        else 
        {
            q=p;    
            p=p->n;
        }    
    }
    return NULL;
}


int main()
{
    struct Node * temp;
    int A[5]={3,4,6,7,-10};
    create(A,5);
    Display(first);

    temp= Search(first,7);
    if(temp)
        cout<<"\nKey forund "<<temp->data;
    else cout<<"\nElement not found";

    Display(first);

}