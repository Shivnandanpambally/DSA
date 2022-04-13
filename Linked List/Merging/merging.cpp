#include<iostream>
#include<cstdio>
using namespace std;

struct Node{
    int data;
    struct Node *n;
};

struct Node * create(int n)
{
    int dig;
    struct Node *N,*p,*t;
    p=new Node;
    N=p;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            cin>>dig;
            p->data=dig;
            p->n=NULL;
        }
        else
        {
            cin>>dig;
            t=new Node;
            t->data=dig;
            t->n=NULL;
            p->n=t;
            p=p->n;
        }         
    }
    return N;
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

struct Node * Merge(struct Node *p1, struct Node *p2)
{
    struct Node *t, *last;
    if(p1->data < p2->data)
    {
        t=last=p1;
        p1=p1->n;
        last->n=NULL;
    }
    else if(p1->data > p2->data)
    {
        t=last=p2;
        p2=p2->n;
        last->n=NULL;
    }

    while(p1 && p2)
    {
        if(p1->data < p2->data)
        {
            last->n=p1;
            p1=p1->n;
            last=last->n;
            last->n=NULL;
        }
        else if(p1->data > p2->data)
        {
            last->n=p2;
            p2=p2->n;
            last=last->n;
            last->n=NULL;
        }        
    }

    while(p1)
    {
        last->n=p1;
        p1=p1->n;
        last=last->n;
        last->n=NULL;
    }
    while(p2)
    {
        last->n=p2;
        p2=p2->n;
        last=last->n;
        last->n=NULL;
    }

    return t;
}

int main()
{
    static struct Node *first, *second, *third;
    int x,y;
    cout<<"Enter the number of element in first and second: ";
    cin>>x>>y;
    cout<<"\nEnter the element in first linked list: ";
    first=create(x);
    cout<<"\nEnter the element in secon linked list: ";
    second=create(y);

    display(first);
    display(second);

    third=Merge(first,second);

    display(third);

}