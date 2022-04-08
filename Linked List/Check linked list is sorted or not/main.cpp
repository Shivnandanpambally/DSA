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


bool IsSorte(struct Node *p)
{
    int x=INT_MIN;
    for(int i=0;p;i++)
    {
        if(p->data<x)
            return false;
        x=p->data;
        p=p->n;
    }
    return true;  
}


int main()
{
    int A[5]={2,5,8,1,10};
    create(A,5);

    if(IsSorte(first))
        cout<<"\nLinked list is sorted";
    else
        cout<<"\nLinked list is not sorted";
    Display(first);
} 