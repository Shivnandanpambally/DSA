#include <iostream>
#include<stdlib.h>
using namespace std;

struct array
{
    int *A;
    int size;
    int length;
};

void display(struct array arr)
{
    int i;
    cout<<"Elements of the array are \n";
    for(i=0;i<arr.length;i++)
        cout<<arr.A[i];
}

int main()
{
   struct array arr, arr1;
   int n,i;
   cout<<"Enter the size of array\t";
   cin>>arr.size;
   arr.A= new int[sizeof(int)];  //arr.A=(int *)malloc(arr.size*sizeof(int));//
   arr.length=0;

   cout<<"Enter the number of element\t";
   cin>>n;

   cout<<"Enter the elements\n";
   for(i=0;i<n;++i)
        cin>>arr.A[i];
   arr.length=n;

    display(arr);

   return 0;
}
