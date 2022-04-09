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

void Delete(struct Node *p, int index)
{
    if(index< 1 || index>count(first))
        return;
    int x;
    struct Node *q;
    q=NULL;

    if(index==1)
    {
        p=first;
        first=first->n;
        x=p->data;
        delete p;
        cout<<endl<<x<<" Deleted from location: "<<index;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->n;
        }
        
        q->n=p->n;
        x=p->data;
        delete p;
        cout<<endl<<x<<" Deleted from location: "<<index;
        
    }
    
}


int main()
{
    struct Node * temp;
    int A[5]={2,5,8,9,10};
    create(A,5);
    Display(first);

    Delete(first,1);
    Display(first);

    Delete(first,3);
    Display(first);
    
    

} 