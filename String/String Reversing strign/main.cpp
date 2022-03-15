#include<iostream>
using namespace std;


int main()
{
 char A[]="Python";
 int i,j,t;
 for(j=0;A[j]!='\0';j++)
 {}
 j--;
 for(i=0;i<j;i++,j--)
 {
   t=A[i];
   A[i]=A[j];
   A[j]=t;
 }
 cout<<"Reversed string is "<<A;

}