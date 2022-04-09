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

    void Delete(int index)
    {
        if(index <= 0 || index > this->Count())
            cout<<"\nInvalied Index\n";
        else{
            Node *p=first;
            if(first==NULL)
            {
                delete first;
                first = NULL;
            }

            if(index==1) 
            {
                first=first->next;
                if(first)
                    first->prev=NULL;   /* #########*/
                delete p;
            } 

            else if(index>1)
            {
                for(int i=1;i<index;i++)
                {
                    p=p->next;
                }
                p->prev->next=p->next;
                if(p->next)
                    p->next->prev=p->prev;   /* #########*/
                delete p;
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