#include<iostream>
#include<cstdio>
using namespace std;

struct Node{
    int data;
    struct Node *n;
}*first;

void create(int A[],int n)
{
    struct Node *p,*t;
    p=new Node;
    p->data=A[0];
    p->n=NULL;
    first=p;
    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->n=NULL;
        p->n=t;
        p=p->n;     
    }
}

void display(struct Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->n;
    }
    cout<<endl;
}

void Rever(struct
 Node *q, struct Node *p)
{
    if(p)
    {
        Rever(p,p->n);
        p->n=q;
    }
    else
        first=q;
}

int main()
{
    int A[5]={1,2,3,4,5};

    create(A,5);

    display(first);

    Rever(NULL,first);

    display(first);

}