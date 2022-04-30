#include<iostream>
using namespace std;

int Stringlen(char A[])
{
    int i;
    for(i=0; A[i]!='\0'; i++)
    {
    }
    return i;
}

class Node
{
public:    
    char data;
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

    char Pop()
    {
        {
            int x=-1;
            if(top == NULL)
            {
                cout<<"Stack underflow"<<endl;
            }
            else{
                Node *p;
                p=top;
                top=top->next;
                x=p->data;
                delete p;
            }
            return x;
        }
    }

    int IsEmpty()
    {
        return (top == NULL)? 1:0;
    }

    void Display()
    {
        Node *p=top;
        while(p)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }

    int IsBalance(char A[])
    {
        Node *p=top;
        for(int i=0;i<Stringlen(A);i++)
        {
            if(A[i]=='(')
                this->Push(A[i]);
            else if(A[i]==')')
            {
                if(this->IsEmpty())
                    return 0;
                this->Pop();
            }
        }
        return this->IsEmpty()? 1:0;  
    }
};

int main()
{
    int d;
    char exp[10];
    cout<<"\nEnter the expression: ";
    cin>>exp;

    stack S;
    d=S.IsBalance(exp);
    if (d==0)
        cout<<"\nExpression is not matched";
    else
        cout<<"\nExpression is matched";
}