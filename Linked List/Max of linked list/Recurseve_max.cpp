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

int ReMax1(struct Node *p)
{
   int x;

   if(p)
   {
       x=ReMax1(p->n);
       if(x>p->data)
            return x;
        else
            return p->data;
   } 
   else
        return INT_MIN;    /* it does't need this else(just like below) but better to add*/
}

int ReMax2(struct Node *p)
{
   int x;

   if(p)
   {
       x=ReMax2(p->n);
       return x>p->data?x:p->data;   
   }
}

int main()
{
    int A[5]={3,4,6,7,-10};
    create(A,5);
    Display(first);

    cout<<"\nLargest number is: "<<ReMax1(first);
    cout<<"\nLargest number is: "<<ReMax2(first);
}