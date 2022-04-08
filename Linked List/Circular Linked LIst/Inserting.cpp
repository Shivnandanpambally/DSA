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

    int Count()
    {
        int c;
        Node *p=Head;
        do
        {
            c++;
            p=p->next;
        } while (p!=Head);
        return c;
    }

    void Insert(int index, int value)
    {
        if(index < 0 || index > this->Count())
            cout<<"Invalied Index";
        else{
            Node *t,*p=Head;
            t=new Node;
            t->data=value;
            t->next=NULL;
            if(Head==NULL)
            {
                Head=t;
                Head->next=Head;
            }

            if(index==0) 
            {
                t->next=Head;
                do
                {
                    p=p->next;
                } while (p->next!=Head);
                p->next=t;
            } 

            else if(index>=1)
            {
                for(int i=1;i<index;i++)
                {
                    p=p->next;
                }
                t->next=p->next;
                p->next=t;
            }
        }     
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

    l.Insert(0,10);
    l.Display();

    l.Insert(2,10);
    l.Display();

    
}