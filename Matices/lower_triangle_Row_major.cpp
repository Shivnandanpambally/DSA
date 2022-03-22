#include<iostream>
#include<cstdio>
using namespace std;

class Lower_tri
{
private:
    int *A;
    int n;
public:

Lower_tri(int n)
{
    this->n=n;
    A=new int[n*(n+1)/2];
}

void Set(int i,int j,int x)
{
  if(i>=j)
  {
      A[((i-1)*i/2)+j-1]=x;
  }   
}

void Get(int i,int j)
{
    if(i>=j)
    {
        cout<<A[((i-1)*i/2)+j-1]<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
}

void Display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)
    {
      if(i>=j)
      cout<<A[((i-1)*i/2)+j-1]<<"\t";
      else
      cout<<"0\t";
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
int n,x;
cout<<"Enter the dimension of the matrix: ";
cin>>n;
class Lower_tri D(n);
printf("Enter all %d elements \n",n*(n+1)/2);
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=i;j++)
    {
        cin>>x;
        D.Set(i,j,x);
    }
}
D.Get(1,1);
D.Display();


}