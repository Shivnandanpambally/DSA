#include<iostream>
#include<cstdio>
using namespace std;

class Diagonal
{
private:
    int *A;
    int n;
public:

Diagonal(int n)
{
    this->n=n;
    A=new int[n];
}

void Set(int i,int j,int x)
{
  if(i==j)
  {
      A[i-1]=x;
  }   
}

void Get(int i,int j)
{
    if(i==j)
    {
        cout<<A[i-1]<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
}

void Display()
{
    int i,j;
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
    {
      if(i==j)
      cout<<A[i]<<" ";
      else
      cout<<"0 ";
    }
    cout<<endl;
    }
}
~Lower_tri()
{
    delete []A;
}
};

int main()
{
class Diagonal D(4);
D.Set(1,1,2);
D.Set(2,2,4);
D.Set(3,3,8);
D.Set(4,4,10);
D.Get(1,2);
D.Display();

}