#include<iostream>
#include<cstdio>
using namespace std;


struct element
{
    int i;
    int j;
    int x;
};

struct sparse
{
    int m;
    int n;
    int num;
    struct element *e;
};

void create(struct sparse *s)
{
    int i;
    cout<<"Enter the dimention of the matrix: ";
    cin>>s->m>>s->n;
    cout<<"Enter number of non zero element: ";
    cin>>s->num;
    s->e=new element[s->num];
    cout<<"Enter the element in the array"<<endl;
    for(i=0;i<s->num;i++)
    {
       cin>>s->e[i].i>>s->e[i].j>>s->e[i].x;
    }
}

void display(struct sparse s)
{
    int i,j,k=0;
    for(i=0; i<s.m;i++)
    {
        for(j=0; j<s.n;j++)
        {
            if(i==s.e[k].i && j==s.e[k].j)
            {
                cout<<s.e[k++].x<<" ";   /*first use k as it is the add k*/
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    struct sparse s;
    create(&s);
    display(s);

}