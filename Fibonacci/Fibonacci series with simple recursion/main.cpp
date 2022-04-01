#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;


int f(int n)
{
  if(n<=1)
    return n;
  else
    return f(n-2)+f(n-1);
}
int main()
{
  int z,y;
  cout<<"Enter the power and accuracy"<<endl;
  cin>>z;
  cout<<f(z);

}
