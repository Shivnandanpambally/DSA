#include <iostream>
#include<stdlib.h>
using namespace std;

struct array
{
    int A[10];
    int size;
    int length;
};

void display(struct array arr)
{
    int i;
    cout<<"Elements of the array are \n";
    for(i=0;i<arr.length;i++)
        cout<<arr.A[i]<<"\t";
    cout<<"\n";
}

void Search(struct array arr, int x)
{
        for(int i=0;i<arr.length;i++)
        {
            if(arr.A[i]==x)
            cout<<i<<endl;
        }
}

void Swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void TransSearch(struct array *arr, int x)
{
        for(int i=0;i<arr->length;i++)
        {
            if(x==arr->A[i])
            {
                Swap(&arr->A[i],&arr->A[i-1]);
                cout<<i<<endl;
            }
        }
}

void MovefrontSearch(struct array *arr, int x)
{
        for(int i=0;i<arr->length;i++)
        {
            if(x==arr->A[i])
            {
                Swap(&arr->A[i],&arr->A[0]);
                cout<<i<<endl;
            }
        }
}


int main()
{
  struct array arr={{2,3,4,5,6},10,5};;

  display(arr);
  Search(arr,6);
  TransSearch(&arr,6);
  display(arr);
  MovefrontSearch(&arr,6);
  display(arr);


}
