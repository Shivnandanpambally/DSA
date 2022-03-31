#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;


int c(int n, int r)
{
  if (r==0||n==r)
    return 1;
  else
    return c(n-1,r)+c(n-1,r-1);
}
int main()
{
  int z,y;
  cout<<"Enter the power and accuracy"<<endl;
  cin>>z>>y;
  cout<<c(z,y);

}

