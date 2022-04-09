#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

class LL
{
private:
    Node *first;
public:
    LL() {first=NULL;}
    LL(int A[], int n)
    {
        int i;
        Node *t,*last;
        first = new Node;
        first->data=A[0];
        first->next=first->prev=NULL;
        last=first;
        for(i=1;i<n;i++)
        {
            t= new Node;
            t->data=A[i];
            t->next=NULL;
            t->prev=last;
            last->next=t;
            last=last->next; 
        }
    }
    void Display()
    {
        Node *p=first;
        while(p)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }

    int Count()
    {
        int c;
        Node *p=first;
        while(p)
        {
            c++;
            p=p->next;
        }
        return c;
    }

    void Reverse()
    {
        Node *q=NULL,*p=first;
        while(p)
        {
            p->prev=p->next;
            p->next=q;
            q=p;
            p=p->prev;
        }
        first=q;
    }

    ~LL()
    {
    Node *p=first;
    do
    {
        first=first->next;
        delete p;
        p=first;
    }while(p!=first);
    }

};

int main()
{
    int A[]={1,2,3,4,5};
    LL l(A,5);

    l.Display();

    l.Reverse();
    l.Display();
    return 0;   
}