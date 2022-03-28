#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;


float pow(float x, float n)
{
  if(n>0)
  {
    return x*pow(x,n-1);
  }
  else
    return 1;
}
float fact(float n)
{
    if(n>0)
    {
        return fact(n-1)*n;
    }
    else
        return 1;
}
float suml(float x,float n)
{
    if(n>0)
    {
      return((pow(x,n)/fact(n))+(suml(x,n-1)));
    }
    else
        return 1;
}
int main()
{
  int z,y;
  cout<<"Enter the power and accuracy"<<endl;
  cin>>z>>y;
  cout<<suml(z,y);

}
