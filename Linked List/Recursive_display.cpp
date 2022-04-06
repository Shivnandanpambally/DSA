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

void display(struct Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        display(p->n);
    }
}

void Redisplay(struct Node *p)
{
    if(p)
    {
        Redisplay(p->n);
        cout<<p->data<<" ";
    }
}

int main()
{
    int A[5]={3,4,6,7,8};
    create(A,5);
    cout<<"Element of the linked list are: ";
    display(first);

    cout<<"\nElement of linked list in reverse order: ";
    Redisplay(first);
}