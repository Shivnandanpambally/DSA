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

int count(struct Node *p)
{
    if(p)
    {
        return count(p->n)+1;
    }
    else
        return 0;
}

int main()
{
    int A[5]={3,4,6,7,8};
    create(A,5);

    cout<<"Number of element in linked list: "<<count(first);
}