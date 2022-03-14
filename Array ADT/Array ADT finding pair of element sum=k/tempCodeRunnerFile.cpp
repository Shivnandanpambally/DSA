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
void Sum_Unsorted(int k);
void Sum_Sorted(int k);
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

void Array::Sum_Unsorted(int k)
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
    if(B[k-A[i]]!=0)
      cout<<A[i]<<"+"<<B[k-A[i]]<<"="<<k;
    B[A[i]]++;
  }

}

void Array::Sum_Sorted(int k)
{
    int i,j;
    i=0;
    j=Length-1;
    while(i<j)
    {
        if(A[i]+A[j]==k)
        {
            printf("%d+%d=%d",&A[i],&A[j],k);
            i++;
            j++;
        }
        else if(A[i]+A[j]<k)
          i++;
        else
          j--;
    }
}

int main()
{
    Array arr,arr1;

    arr.Sum_Unsorted(10);
    arr1.Sum_Sorted(10);
}