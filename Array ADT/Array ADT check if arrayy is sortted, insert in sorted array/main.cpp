#include <iostream>
#include<stdlib.h>

using namespace std;

struct Array
{
    int A[10];
    int Lenght;
    int Size;
};

void Display(struct Array arr)
{
    int i;
    for(i=0;i<arr.Lenght;i++)
        cout<<arr.A[i]<<" ";
    cout<<endl;
}

void Insertinsort(struct Array *arr,int x)
{
    int i=arr->Lenght-1;
    if(arr->Lenght<arr->Size)
    {
      for(i;i>0 && arr->A[i]>x;i--)
        arr->A[i+1]=arr->A[i];
    }
    arr->A[i+1]=x;
    arr->Lenght++;
}

int Issorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.Lenght-2;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return -1;
    }
    return 1;
}

void Swap(int *x, int *y)
{
   int temp;
   temp=*x;
   *x=*y;
   *y=temp;
}

void neglefpostrig(struct Array *arr1)
{
    int i=0;
    int j=arr1->Lenght-1;
    while(i<j)
    {
        while(arr1->A[i]<0)
            i++;
        while(arr1->A[j]>0)
            j--;
        if(i<j)
        Swap(&arr1->A[i],&arr1->A[j]);
    }

}

int main()
{
   struct Array arr ={{2,3,5,10,15},5,10} ;
   struct Array arr1={{-6,3,-8,10,5,-7,-9,12,-4,2},10,10};
   Display(arr);
   Insertinsort(&arr,9);
   Display(arr);
   cout<<Issorted(arr)<<endl;
   neglefpostrig(&arr1);
   Display(arr1);
}
