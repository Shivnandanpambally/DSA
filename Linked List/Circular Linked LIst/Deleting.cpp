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

    void Delete(int index)
    {
        if(index < 0 || index > this->Count())
        {
            cout<<"\nInvalied Index"<<endl;
        }
        else{
            Node *q=NULL,*p=Head;
            if(index==1) 
            {
                do
                {
                    p=p->next;
                } while (p->next!=Head);
                if(Head==p)
                {
                    delete Head;
                    Head=NULL;
                }
                else
                {
                    q=Head;
                    Head=Head->next;
                    p->next=Head;
                    delete q;
                }
            } 

            else if(index>1)
            {
                for(int i=1; i<index;i++)
                {
                    q=p;
                    p=p->next;
                }
                q->next=p->next;
                delete p;
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

    l.Delete(8);
    l.Display();

    l.Delete(2);
    l.Display();
    
    l.Delete(1);
    l.Display();

    l.Delete(3);
    l.Display();

    l.Delete(2);
    l.Display();

    l.Delete(1);
    l.Display();
    
    return 0;   
}