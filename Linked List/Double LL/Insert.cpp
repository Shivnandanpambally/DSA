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

    void Insert(int index, int val)
    {
        if(index < 0 || index > this->Count())
            cout<<"Invalied Index";
        else{
            Node *t,*p=first;
            t=new Node;
            t->data=val;
            t->next=NULL;
            t->prev=NULL;
            if(first==NULL)
            {
                first=t;
                first->next=NULL;
                first->prev=NULL;
            }

            if(index==0) 
            {
                t->next=first;
                t->prev=NULL;
                first->prev=t;
                first=t;
            } 

            else if(index>=1)
            {
                for(int i=1;i<index;i++)
                {
                    p=p->next;
                }
                t->next=p->next;
                t->prev=p;    
                if(p->next)
                    p->next->prev=t;  /* #########*/
                p->next=t;
            }
        }
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

    l.Insert(0,10);
    l.Display();

    l.Insert(3,20);
    l.Display();

    l.Insert(7,30);
    l.Display();
    
    return 0;   
}