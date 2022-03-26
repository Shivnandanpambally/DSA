#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;


void TOH(int n, int A, int B, int C)
{
  if(n>0)
  {
      TOH(n-1,A,C,B);
      printf("Move a disk from %d from %d\n",A,C);
      TOH(n-1,B,A,C);
  }
}
int main()
{
  int m,x,y,z;
  cout<<"Enter the power and accuracy"<<endl;
  cin>>m>>x>>y>>z;
  TOH(m,x,y,z);

}

