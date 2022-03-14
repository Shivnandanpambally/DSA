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

void Merge(struct Array arr1,struct Array arr2)
{
    int *A;
    A=(int*)malloc((arr1.Lenght+arr2.Lenght)*sizeof(int));
    int i=0,j=0,k=0;
    while(i<arr1.Lenght&&j<arr2.Lenght)
    {
        if(arr1.A[i]<arr2.A[j])
        {
            A[k]=arr1.A[i];
            i++;
        }
        else
        {
          A[k]=arr2.A[j];
          j++;
        }
        k++;
    }
    for(i,k;i<arr1.Lenght;i++,k++)
       A[k]=arr1.A[i];
    for(j,k;j<arr2.Lenght;j++,k++)
       A[k]=arr2.A[j];
    for(k=0;k<arr1.Lenght+arr2.Lenght;k++)
        cout<<A[k]<<" ";
    cout<<endl;
}

int main()
{
  struct Array arr1={{3,8,9,20,25},5,10};
  struct Array arr2={{4,10,12,22,23},5,10};
  Display(arr1);
  Display(arr2);
  Merge(arr1,arr2);
}

/* Sirs Method is given below*/

/*#include <iostream>
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
struct Array* Merge(struct Array *arr1,struct Array *arr2)
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
        else
        {
            arr3->A[k]=arr2->A[j];
            j++;
        }
        k++;
    }
    for(; i<arr1->length; i++)
        arr3->A[k++]=arr1->A[i];
    for(; j<arr2->length; j++)
        arr3->A[k++]=arr2->A[j];
    arr3->length=arr1->length+arr2->length;
    arr3->size=10;

    return arr3;
}
int main()
{
    struct Array arr1= {{3,8,9,20,25},10,5};
    struct Array arr2= {{4,10,12,22,23},10,5};
    struct Array *arr3;
    arr3=Merge(&arr1,&arr2);
    Display(*arr3);

    ret*/
