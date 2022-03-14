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

void append(struct array *arr,int x)
{
    if(arr->length<arr->size)
    arr->A[arr->length]=x;
    arr->length++;
}

void Insert(struct array *arr, int x, int y)
{
    if(y>=0 && y<=arr->length && arr->length<arr->size)
    {
        for(int i=arr->length;i>y;i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[y]=x;
        arr->length++;
    }
}

void Delete(struct array *arr, int x)
{
    if(arr->length>x)
    {
        for(int i=x; i<arr->length-1;++i)
            arr->A[i]=arr->A[i+1];
    }
    arr->length--;
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


int main()
{
  struct array arr={{2,3,4,5,6},10,5};;

  append(&arr,10);
  Insert(&arr,15,3);
  Delete(&arr,2);
  display(arr);
  Search(arr,6);


}
