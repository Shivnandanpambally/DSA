#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*top=NULL;

void Push(int x)
{
    struct Node *t=new Node;
    if(t==NULL)
        cout<<"Stack overflow"<<endl;
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int Pop()
{
    {
        int x=-1;
        if(top == NULL)
        {
            cout<<"Stack underflow"<<endl;
        }
        else{
            struct Node *p;
            p=top;
            top=top->next;
            x=p->data;
            delete p;
        }
        return x;
    }
}

void Display()
{
    struct Node *p=top;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int Peek(int pos)
{
    struct Node *p;
    p=top;
    for(int i=0;p!=NULL && i<pos-1;i++)
    {
        p=p->next;
    }
    if(p!=NULL)
    {
        return p->data;
    }
    else
        return -1;

}

int main()
{
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    Push(50);

    Display();

    cout<<Pop()<<endl;

    Display();

    cout<<Peek(2)<<endl;
}