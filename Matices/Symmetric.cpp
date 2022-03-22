#include<iostream>
#include<cstdio>
using namespace std;

class symmetric
{
private:
   int *A;
   int n;
public:
   symmetric(int n)
   {
       this->n=n;
       A=new int[n*(n+1)/2];
   }
   void Set(int i, int j, int x)
   {
       if(i>=j)
       {
           A[((i-1)*i/2)+j-1]=x;
       }
   }
   void Get(int i, int j)
   {
       if(i>=j)
       {
           cout<<A[((i-1)*i/2)+j-1]<<endl;
       }
       else
       {
           cout<<A[((j-1)*j/2)+i-1]<<endl;
       }
   }
   void Display()
   {
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=n;j++)
           {
              if(i>=j)
                {
                    cout<<A[((i-1)*i/2)+j-1]<<"\t";
                }
              else
                {
                    cout<<A[((j-1)*j/2)+i-1]<<"\t";
                }    
           }
           cout<<endl;
       }
   }
   ~symmetric()
   {
    delete []A;
   }
};


int main()
{
  int n,x; 
  cout<<"Enter the size of the array: ";
  cin>>n;
  class symmetric S(n);
  cout<<"Enter the lower triangular part of symmatirc matrix(Row wise)"<<endl;
  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=i;j++)
      {
          cin>>x;
          S.Set(i,j,x);
      }
  }
  S.Display();
 
}