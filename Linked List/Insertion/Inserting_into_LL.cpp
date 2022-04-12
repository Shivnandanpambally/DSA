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
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if(index<0 || index>count(first))
        return;
    t= new struct Node;
    t->data=x;

    if(index==0)
    {
        t->n=first;
        first=t;
    }

    else 
    {
        struct Node *p;
        p=first;
        for(int i=0;i<index-1;i++)
        {
            p=p->n;
        }
        t->n=p->n;
        p->n=t;
    }
}


int main()
{
    struct Node * temp;
    int A[5]={3,4,6,7,-10};
    create(A,5);
    Display(first);

    Insert(first, 0,10);
    Insert(first, 2,8);
    Insert(first, 20,40);

    Display(first);

} 