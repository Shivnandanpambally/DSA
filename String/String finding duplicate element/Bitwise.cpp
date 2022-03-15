#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
 char A[]="sasicuttan";
 int H=0, x=0,i;
 for(i=0;A[i]!='\0';i++)
 {
     x=1;
     x=x<<A[i]-97;
     if((H&x)>0)
     {
      printf("%c is repeating\n",A[i]);
     }   
    else 
      H=H|x;
 }
 
}