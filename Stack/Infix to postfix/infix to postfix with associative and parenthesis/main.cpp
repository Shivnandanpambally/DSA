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

    int IsOperand(char x)
    {
        if(x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^')
            return 0;
        else
            return 1;
    }

    int OutPre(char x)
    {
        if(x == '+' || x == '-')
            return 1;
        else if(x == '*' || x == '/')
            return 3;
        else if(x=='^')
            return 6;
        else if(x=='(')
            return 7;
        else if(x==')')
            return 0;
        return 0;        
    }

    int InPre(char x)
    {
        if(x == '+' || x == '-')
            return 2;
        else if(x == '*' || x == '/')
            return 4;
        else if(x=='^')
            return 5;
        else if(x=='(')
            return 0;
        // else if(x==')')
        //     return 0;
        return 0;        
    }
    
    char * Convert (char * infix) 
    {
        char * postfix= new char[Stringlen(infix)+1];
        int i=0,j=0;

        while(infix[i] != '\0')
        {
            if(this->IsOperand(infix[i]))
            {
                postfix[j++]=infix[i++];
            }

            else
            {
                if(this->OutPre(infix[i]) > this->InPre(top->data))
                {
                    this->Push(infix[i++]);
                }
                else if(this->OutPre(infix[i]) == this->InPre(top->data))
                {
                    this->Pop();
                    i++;
                }
                else
                {
                    postfix[j++]=this->Pop();
                }
            }
        }
        while(!this->IsEmpty())
        {
            postfix[j++]=this->Pop();
        }
        postfix[j]='\0';
        return postfix;

    }
};

int main()
{
    char *post;
    char infix[10];
    cout<<"\nEnter the expression: ";
    cin>>infix;

    stack S;
    S.Push('#');
    post=S.Convert(infix);
    cout<<post;
}