#include<iostream>
#include<cstdio>
using namespace std;

void Swap(char *x, char *y)
{
    char t;
    t=*x;
    *x=*y;
    *y=t;
}

void perm(char S[], int l, int h)
{
    int i;
    if(l==h)
    {
        cout<<S<<endl;
    }
    else
    {
        for(i=l;i<=h;i++)
        {
            Swap(&S[l],&S[i]);
            perm(S, l+1,h);
            Swap(&S[l],&S[i]); 
        }        
    }
}

int main()
{
char S[]="ABC";
perm(S,0,2);
}