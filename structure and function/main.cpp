#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;

struct rect
{
    int length;
    int breadth;
};
int init(struct rect *p, int l, int b)
{
    p->length=l;
    p->breadth=b;
}
int area(struct rect r)
{
    return(r.length*r.breadth);
}
int changeleng(struct rect *p, int l)
{
    p->length=l;
}
int main()
{
   struct rect r;
   init(&r,10,5);
   cout<<r.length<<endl<<r.breadth<<endl;
   int a=area(r);
   cout<<a<<endl;
   changeleng(&r,15);
   cout<<r.length<<endl<<r.breadth<<endl;

}
