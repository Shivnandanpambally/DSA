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
    cout<<"Element in the linkedlist are: ";
    while(p)
    {
        cout<<p->data<<" ";
        p=p->n;
    }
}

int Add(struct Node *p)
{
    int sum=0;
    while(p)
    {
        sum+=p->data;
        p=p->n;
    }
    return sum;
}

int ReAdd(struct Node *p)
{
    int sum=0;
    if(p==0)
        return 0;
    else
    {
        return p->data+ReAdd(p->n);
    }
}

int main()
{
    int A[5]={3,4,6,7,8};
    create(A,5);
    Display(first);

    cout<<"\nSum of elements in linked list is: "<<Add(first);
    cout<<"\nSum of elements in linked list using reccursion is: "<<ReAdd(first);
}