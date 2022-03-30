#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;

int * fun(int n)
{
    int *p;
    p=(int*) malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    return(p);
}
int main()
{
    int *a;
    a=fun(5);
    for(int i=0;i<5 ;i++)
    cout<<a[i]<<endl;

}
