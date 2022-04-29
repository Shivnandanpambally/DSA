#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class stack
{
private:
    Node *top;
public:
    stack()
    {
        top=NULL;
    }

    void Push(int x)
    {
        Node *t=new Node;
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
};

int main()
{
    stack S;
    S.Push(10);
    S.Push(20);
    S.Push(30);
    S.Push(40);
    S.Push(50);

    S.Display();

    cout<<S.Pop()<<endl;

    S.Display();

    cout<<S.Peek(2)<<endl;
}