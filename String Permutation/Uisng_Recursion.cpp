#include<iostream>
#include<cstdio>
using namespace std;

void perm(char S[], int k)
{
    static int A[10]={0};
    static char R[10];
    int i;
    
    if(S[k]=='\0')
    {
        R[k]=='\0';
        cout<<R<<endl;
    }
    else
    {
        for(i=0;S[i]!='\0';i++)
        {
            if(A[i]==0)
            {            
              R[k]=S[i];
              A[i]=1;
              perm(S,k+1);
              A[i]=0;               
            }
        }
    }
}

int main()
{
char S[]="ABC";
perm(S,0);
}