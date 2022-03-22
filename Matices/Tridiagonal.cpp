#include<iostream>
#include<cstdio>
using namespace std;

class tridiagonal
{
private:
   int *A;
   int n;
public:
   tridiagonal(int n)
   {
       this->n=n;
       A=new int[3*n-2];
   }
   void Set(int i, int j, int x)
   {
       if(i-j==1)
       {
           A[j-1]=x;
       }
       else if(i==j)
       {
           A[n-1+i-1]=x;
       }
       else if(i-j==-1)
       {
           A[2*n-1+i-1]=x;
       }
   }
   void Get(int i, int j)
   {
       if(i-j==1)
       {
           cout<<A[j-1]<<endl;
       }
       else if(i==j)
       {
           cout<<A[n-1+i-1]<<endl;
       }
       else if(i-j==-1)
       {
           cout<<A[2*n-1+i-1]<<endl;
       }
       else
           cout<<"0"<<endl;
   }
   void Display()
   {
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=n;j++)
           {
              if(i-j==1)
              {
                  cout<<A[j-1]<<"\t";
              }
              else if(i==j)
              {
                  cout<<A[n-1+i-1]<<"\t";
              }
              else if(i-j==-1)
              {
                  cout<<A[2*n-1+i-1]<<"\t";
              }
              else
                  cout<<"0"<<"\t";    
            }
            cout<<endl;
        }
   }
   ~tridiagonal()
   {
    delete []A;
   }
};


int main()
{
  int n,x; 
  cout<<"Enter the size of the array: ";
  cin>>n;
  class tridiagonal T(n);
  cout<<"Enter the element of Tridiagonal matrix row wise"<<endl;
  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=n;j++)
      {
          cin>>x;
          T.Set(i,j,x);
      }
  }
  T.Display();

 
}