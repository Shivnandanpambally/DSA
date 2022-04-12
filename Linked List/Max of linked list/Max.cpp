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
    cout<<"Element in the linkedlist are: ";
    while(p)
    {
        cout<<p->data<<" ";
        p=p->n;
    }
}

void Max(struct Node *p)
{
    cout<<"\nLargest element in linked list is: ";
    int i= INT_MIN;
    while(p)
    {
        if(p->data > i) i=p->data;
        p=p->n;
    }
    cout<<i;
}

int main()
{
    int A[5]={3,4,6,7,8};
    create(A,5);
    Display(first);

    Max(first);
}