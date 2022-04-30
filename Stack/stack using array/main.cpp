#include<iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *S;
};

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

int Pop(struct stack *st)
{
    int x=-1;
    if(st->top == -1)
        cout<<"\nStack underflow";
    else{
        x=st->S[st->top];
        st->top--;
    }
    return x;
}

int Peek(struct stack st, int pos)
{
    int x=-1;
    if(st.top-pos+1<0)
        cout<<"\nInvalied position";
    else
        x=st.S[st.top-pos+1];
    return x;
}

void Display(struct stack st)
{
    for(int i=st.top;i>=0;i--)
    {
        cout<<st.S[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    struct stack st;
    cout<<"\nEnter the size of stack: ";
    cin>>st.size;
    st.S=new int[st.size];
    st.top=-1;

    Push(&st,10);
    Push(&st,20);
    Push(&st,30);
    Push(&st,40);
    Push(&st,50);

    Display(st);

    cout<<Pop(&st)<<endl;

    Display(st);

    cout<<Peek(st,2)<<endl;
}