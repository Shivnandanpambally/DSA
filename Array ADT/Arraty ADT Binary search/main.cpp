#include <iostream>

using namespace std;

struct Array
{
    int A[10];
    int Size;
    int Leangth;
};

int BinarySearch(struct Array arr,int l, int h, int key)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(arr.A[mid]==key)
            return mid;
        else if(key<arr.A[mid])
            return BinarySearch(arr,l,mid-1,key);
        else
            return BinarySearch(arr,mid+1,h,key);

    }
return -1;
}

void Display(struct Array arr)
{
    for(int i=0;i<arr.Leangth;i++)
        cout<<arr.A[i];
}

int main()
{
    struct Array arr= {{2,3,4,5,6},10,5};
    int x;

    Display(arr);
    cout<<endl<<"Enter the value to be search\t";
    cin>>x;
    cout<<endl;
    cout<<BinarySearch(arr,0,arr.Leangth-1,x);
}
