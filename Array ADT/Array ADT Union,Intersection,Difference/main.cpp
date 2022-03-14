#include <iostream>
#include<stdlib.h>

using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;
};
void Display(struct Array arr)
{
    int i;
    cout<<"\nElements are\n";
    for(i=0; i<arr.length; i++)
        cout<<arr.A[i]<<" ";
}
struct Array* Union(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct
                       Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k]=arr1->A[i];
            i++;
        }
        else if(arr2->A[j]<arr1->A[i])
        {
            arr3->A[k]=arr2->A[j];
            j++;
        }
        else
        {
            arr3->A[k]=arr2->A[j];
            i++;
            j++;
        }
        k++;
    }
    for(; i<arr1->length; i++)
        arr3->A[k++]=arr1->A[i];
    for(; j<arr2->length; j++)
        arr3->A[k++]=arr2->A[j];
    arr3->length=k;
    arr3->size=10;

    return arr3;
}

struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr4=(struct Array *)malloc(sizeof(struct
                       Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]==arr2->A[j])
        {
            arr4->A[k]=arr2->A[j];
            i++;
            j++;
            k++;   /* this is important comparing to other program that i did*/
        }
        else
        {
            i++;
            j++;
        }

    }               /*not copying left over elements*/
    arr4->length=k;
    arr4->size=10;

    return arr4;
}

struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr5=(struct Array *)malloc(sizeof(struct
                       Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr5->A[k]=arr1->A[i];
            i++;
            k++;
        }
        else if(arr1->A[i]>arr2->A[j])
        {
            j++;
        }
        else
        {
            j++;
            i++;
        }

    }
    for(; i<arr1->length; i++)
        arr5->A[k++]=arr1->A[i];
    arr5->length=k;
    arr5->size=10;

    return arr5;
}

int main()
{
    struct Array arr1= {{2,6,10,15,25},10,5};
    struct Array arr2= {{3,6,7,15,20},10,5};
    struct Array *arr3, *arr4, *arr5;
    arr3=Union(&arr1,&arr2);
    Display(*arr3);
    arr4=Intersection(&arr1,&arr2);
    Display(*arr4);
    arr5=Difference(&arr1,&arr2);
    Display(*arr5);


}
