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

int count(struct Node *p)
{
    if(p)
    {
        return count(p->n)+1;
    }
    else
        return 0;
}

void DeleteDup(struct Node *p)
{
    struct Node *q=p->n;
    while(q)
    {
         if(q->data==p->data)
         {
             p->n=q->n;
             delete q;
             q=p->n;
         }
         else
         {
             p=q;
             q=q->n;
         }
    }
}

int main()
{
    struct Node * temp;
    int A[5]={2,5,5,10,10};
    create(A,5);
    Display(first);

    DeleteDup(first);
    Display(first);


} 