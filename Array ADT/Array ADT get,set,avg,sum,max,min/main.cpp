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
}

int get(struct Array arr, int x)
{
    if(x>=0 && x<arr.Lenght)
     return arr.A[x];
}

void Set(struct Array *arr, int x, int y)
{
    if(x>=0 && x<arr->Lenght)
    arr->A[x]=y;
}

int Max(struct Array arr)
{
    int maxval=0,i;
    for(i=0;i<arr.Lenght;i++)
    {
        if(arr.A[i]>maxval)
            maxval=arr.A[i];
    }
    return maxval;
}

int Sum(struct Array arr)
{
    int sum=0,i;
    for(i=0;i<arr.Lenght;i++)
        sum=sum+arr.A[i];
    return sum;
}

float average(struct Array arr)
{
    int avr=0;
    avr=(float)Sum(arr)/arr.Lenght;
    return avr;
}

int main()
{

    struct Array arr={{2,4,6,7,8},5,10};

    display(arr); cout<<endl;

    cout<<get(arr,3)<<endl;

    Set(&arr,3,10);

    cout<<Max(arr)<<endl;

    cout<<Sum(arr)<<endl;

    cout<<average(arr)<<endl;

    display(arr); cout<<endl;

    cout<<get(arr,3)<<endl;


}
