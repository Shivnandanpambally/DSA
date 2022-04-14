#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;


double e(int x, int n)
{
  static double s=1;
  if (n==0)
    return s;
  s=1+x*s/n;
  return e(x,n-1);
}
int main()
{
  int z,y;
  cout<<"Enter the power and accuracy"<<endl;
  cin>>z>>y;
  cout<<e(z,y);

}
