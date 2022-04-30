#include<iostream>
using namespace std;

int Num(char A[])
{
    int i;
    for(i=0; A[i]!='\0'; i++)
    {
    }
    return i;
}

struct stack
{
    int size;
    int top;
    char *S;
}st;

void Push(struct stack *st, int x)
{
    if(st->top == st->size-1)
        cout<<"\nstack overflow\n";
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}

char Pop(struct stack *st)
{
    char x=-1;
    if(st->top == -1)
        cout<<"\nStack underflow";
    else{
        x=st->S[st->top];
        st->top--;
    }
    return x;
}

int IsEmpty(struct stack st)
{
    return (st.top== -1)? 1:0;
}

void Display(struct stack st)
{
    for(int i=st.top;i>=0;i--)
    {
        cout<<st.S[i]<<" ";
    }
    cout<<endl;
}

int IsBalance(char A[])
{
    for(int i=0;i<st.size;i++)
    {
        if(A[i]=='(')
            Push(&st, A[i]);
        else if(A[i]==')')
        {
            if(IsEmpty(st)) return 0;
            Pop(&st);
        }
    }
    return IsEmpty(st)? 1:0;
}

int main()
{
    int d;
    char exp[10];
    cout<<"\nEnter the expression: ";
    cin>>exp;
    st.size=Num(exp);
    st.top=-1;
    st.S=new char[st.size];

    d=IsBalance(exp);
    if (d==0)
        cout<<"\nExpression is not matched";
    else
        cout<<"\nExpression is matched";
}