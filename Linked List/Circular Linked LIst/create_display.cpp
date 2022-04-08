#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LL
{
private:
    Node *Head;
public:
    LL() {Head=NULL;}
    LL(int A[], int n)
    {
        int i;
        Node *t,*last;
        Head = new Node;
        Head->data=A[0];
        Head->next=Head;
        last=Head;
        for(i=1;i<n;i++)
        {
            t= new Node;
            t->data=A[i];
            t->next=Head;
            last->next=t;
            last=last->next; 
        }
    }
    void Display()
    {
        Node *p=Head;
        do
        {
            cout<<p->data<<" ";
            p=p->next;
        }while(p!=Head);
        cout<<endl;
    }

    void RDisplay(struct Node *p)
    {
        static int flag = 0;
        if(flag==0) p=Head;
        if(p!=Head || flag ==0)
        {
            flag=1;
            cout<<p->data<<" ";
            RDisplay(p->next);
        }
        cout<<endl;
        flag=0;
    }

    ~LL()
    {
    Node *p=Head;
    do
    {
        Head=Head->next;
        delete p;
        p=Head;
    }while(p!=Head);
    }

};

int main()
{
    int A[]={1,2,3,4,5};
    LL l(A,5);

    l.Display();
    l.RDisplay(NULL);
}