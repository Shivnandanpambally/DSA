#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int Length;

public:
Array()
{
    size=10;
    Length=10;
    A=new int[size]; 
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<Length;i++)
    {
      cin>>A[i];
    }
}
void Num_Duplicate();
int Least();
int Highest();
~Array()
{
    delete[]A;
}
};

int Array::Least()
{
  int L=A[0];
  for(int i=0;i<Length;i++)
  {
    if(A[i]<L)
    L=A[i];
  }
  return L;
}

int Array::Highest()
{
  int H=A[0];
  for(int i=0;i<Length;i++)
  {
    if(A[i]>H)
    H=A[i];
  }
  return H;
}

void Array::Num_Duplicate()
{
  int *B,i;
  int L=Least();
  int H=Highest();
  B=new int[H+1];  
  for(i=0;i<H+1;i++)
  {
    B[i]=0;
  }
  for(i=0;i<Length;i++)
  {
    B[A[i]]++;
  }
  for(i=L;i<H+1;i++)
  {
    if(B[i]>1)
    cout<<i<<" duplicate "<<B[i]<<" times "<<endl;
  }

}

int main()
{
    Array arr;

    arr.Num_Duplicate();
}