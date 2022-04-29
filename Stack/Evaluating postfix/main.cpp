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

    int Pop()
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
        if(x == '+' || x == '-' || x == '*' || x == '/')
            return 0;
        else
            return 1;
    }

    int Pre(char x)
    {
        if(x == '+' || x == '-')
            return 1;
        else if(x == '*' || x == '/')
            return 2;
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
                if(this->Pre(infix[i]) > this->Pre(top->data))
                {
                    this->Push(infix[i++]);
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

    int Claculation(char op, int v1, int v2)
    {
        int res;
        if(op =='+')
        {
            res = v1+v2;
        }
        else if(op=='-')
        {
            res = v1-v2;
        }
        else if(op=='*')
        {
            res = v1*v2;
        }
        else if(op=='/')
        {
            res = v1/v2;
        }
        return res;
    }

    int Evaluate(char * postfix)
    {
        int i=0;
        int x;
        int v1,v2;
        cout<<"\nEnter the value of ";
        while(postfix[i]!='#')
        {
            if(this->IsOperand(postfix[i]))
                cout<<postfix[i]<<", ";
            i++;
        }
        cout<<": ";
        i=0;
        while(postfix[i]!='#')
        {
            if(this->IsOperand(postfix[i]))
            {
                cin>>x;
                postfix[i]=x;
            }
            i++;
        }
        i=0;
        while(postfix[i]!='#')
        {
            if(this->IsOperand(postfix[i]))
            {
                this->Push(postfix[i++]);
            }
            else if(!this->IsOperand(postfix[i]))
            {
                v2=this->Pop();
                v1=this->Pop();
                this->Push(this->Claculation(postfix[i++],v1,v2));
            }
        }
        return top->data;
    }
};

int main()
{
    int fin;
    char *post;
    char infix[10];
    cout<<"\nEnter the expression: ";
    cin>>infix;

    stack S;
    S.Push('#');
    post=S.Convert(infix);

    cout<<"\nPostfix Expression is: "<<post<<endl;

    fin=S.Evaluate(post);
    cout<<fin<<endl;
    
}