#include<iostream>
#include<cstdio>
using namespace std;

struct Node
{
    int data;
    struct Node *n;
}*first,*last;

void Display(struct Node *p)
{
    cout<<"\nElement in the linkedlist are: ";
    while(p)
    {
        cout<<p->data<<" ";
        p=p->n;
    }
}

void insert(int x)
{
    struct Node *t;
    t= new Node;
    t->data=x;
    t->n=NULL;

    if(first==NULL)
    {
        first=last=t;
    }
    else
    {
        last->n=t;
        last=t;
    }
}


int main()
{

    
    insert(8);
    insert(6);
    insert(1);
    insert(4);
    insert(7);

    Display(first);

} 