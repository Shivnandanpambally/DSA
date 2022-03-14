#include <iostream>
#include<stdlib.h>

using namespace std;

struct Array
{
    int A[10];
    int Lenght;
    int Size;
};

int display(struct Array arr)
{
    int i;
    for(i=0;i<arr.Lenght;i++)
        cout<< arr.A[i];
    cout<<endl;
}

void Reverse(struct Array *arr)
{
    int B[arr->Lenght]={0};
    int i,j;
    for(i=arr->Lenght-1,j=0;i>=0;i--,j++)
    {
        B[j]=arr->A[i];
    }
    for(i=0;i<arr->Lenght;i++)
        arr->A[i]=B[i];
    cout<<"Reversed array= ";
    for(i=0;i<arr->Lenght;i++)
        cout<< arr->A[i];
    cout<<endl;
}

void Reverse2(struct Array *arr)
{
    int i,temp;
    for(i=0;i<=(arr->Lenght-1)/2;i++)
    {
        temp=arr->A[i];
        arr->A[i]=arr->A[arr->Lenght-1-i];
        arr->A[arr->Lenght-1-i]=temp;
    }

    cout<<"Reversed array using second method= ";
    for(i=0;i<arr->Lenght;i++)
        cout<< arr->A[i];
    cout<<endl;
}

void Leftshift(struct Array *arr)
{
    int i;
    for(i=0;i<arr->Lenght-1;i++)
    {
        arr->A[i]=arr->A[i+1];
    }
    arr->Lenght--;
    cout<<"Left shifted array= ";
    for(i=0;i<arr->Lenght;i++)
        cout<< arr->A[i];
    cout<<endl;
}

void Rotate(struct Array *arr)
{
    int i;
    int temp=arr->A[0];
    for(i=0;i<arr->Lenght-1;i++)
    {
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->Lenght-1]=temp;
    cout<<"Rotated array is array= ";
    for(i=0;i<arr->Lenght;i++)
        cout<< arr->A[i];
    cout<<endl;
}



int main()
{

    struct Array arr={{2,4,6,7,8},5,10};

    display(arr);
    Reverse(&arr);
    Reverse2(&arr);
    Leftshift(&arr);
    Rotate(&arr);

}
