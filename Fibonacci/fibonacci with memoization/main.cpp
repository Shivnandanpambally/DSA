#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;

int f[20];
int memo(int n)
{
  if(n<=1)
  {
      f[n]=n;
      return n;
  }
  else
  {
      if(f[n-2]==-1)
        f[n-2]=memo(n-2);
      if(f[n-1]==-1)
        f[n-1]=memo(n-1);
      return f[n-2]+f[n-1];
  }
}
int main()
{
    for(int i=0;i<20;++i)
        f[i]=-1;
  int z,y;
  cout<<"Enter the power and accuracy"<<endl;
  cin>>z;
  cout<<memo(z);

}
