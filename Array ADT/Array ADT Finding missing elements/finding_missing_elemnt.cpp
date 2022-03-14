#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int Length;
};

void Missing(struct Array arr)
{
   int l=arr.A[0],h=arr.A[arr.Length-1],i;
   int dif=arr.A[0]-0;
   for(i=0;i<arr.Length;i++)
   {
       if(arr.A[i]-i!=dif)
       {
           while(dif<arr.A[i]-i)
           {
               cout<<"Missing number is ="<<dif+i<<endl;
               dif++;
           }
       }
   } 
}

int main()
{
    struct Array arr={{3,4,5,6,7,8,10,13,14},10,9};

    Missing(arr);
}