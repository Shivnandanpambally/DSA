#include<iostream>
#include<cstdio>
using namespace std;


struct element
{
    int i;
    int j;
    int x;
};

struct sparse
{
    int m;
    int n;
    int num;
    struct element *e;
};

void create(struct sparse *s)
{
    int i;
    cout<<"Enter the dimention of the matrix: ";
    cin>>s->m>>s->n;
    cout<<"Enter number of non zero element: ";
    cin>>s->num;
    s->e=new element[s->num];
    cout<<"Enter the element in the array"<<endl;
    for(i=0;i<s->num;i++)
    {
       cin>>s->e[i].i>>s->e[i].j>>s->e[i].x;
    }
}

int add(struct sparse *s1, struct sparse*s2, struct sparse *sum)
{
    int i=0, j=0, k=0;
    if(s1->m != s2->m || s1->n != s2->n)
        cout<<"Array size are not similar";
    else
    {
        sum->m=s1->m;
        sum->n=s1->n;
        sum->e=new element[s1->num+s2->num];
        while((i<s1->num) && (j<s2->num))
        {
            if(s1->e[i].i < s2->e[j].i)
                sum->e[k++]=s1->e[i++];
            else if(s1->e[i].i > s2->e[j].i)
                sum->e[k++]=s2->e[j++];
            else
            {
                if(s1->e[i].j < s2->e[j].j)
                    sum->e[k++]=s1->e[i++];
                else if(s1->e[i].j > s2->e[j].j)
                    sum->e[k++]=s2->e[j++];
                else{
                        sum->e[k]=s1->e[i++];
                        sum->e[k++].x+=s2->e[j++].x;
                    }
            }
        }
        for(; i<s1->num;i++) sum->e[k++]=s1->e[i];
        for(; j<s2->num;j++) sum->e[k++]=s2->e[j];
        sum->num=k;
    }

}

void display(struct sparse s)
{
    int i,j,k=0;
    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i==s.e[k].i && j==s.e[k].j)
            {
                cout<<s.e[k++].x<<" ";   /*first use k as it is the add k*/
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    struct sparse s1,s2,sum;
    create(&s1);
    create(&s2);
    add(&s1,&s2,&sum);
    cout<<"First Matrix:"<<endl;
    display(s1); 
    cout<<"Second Matrix:"<<endl;
    display(s2);
    cout<<"Third Matrix:"<<endl;
    display(sum);
}




/*Check sir's code too*/
/*
#include <stdio.h>
#include<stdlib.h>
struct Element
{
 int i;
 int j;
 int x;
};
struct Sparse
{
 int m;
 int n;
 int num;
 struct Element *ele;
};
void create(struct Sparse *s)
{
 int i;
 
 printf("Eneter Dimensions");
 scanf("%d%d",&s->m,&s->n);
 printf("Number of non-zero");
 scanf("%d",&s->num);
 
 s->ele=(struct Element *)malloc(s->num*sizeof(struct
Element));
 printf("Eneter non-zero Elements");
 for(i=0;i<s->num;i++)
 scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s-
>ele[i].x);
 
}
void display(struct Sparse s)
{
 int i,j,k=0;
 
 for(i=0;i<s.m;i++)
 {
 for(j=0;j<s.n;j++)
 {
 if(i==s.ele[k].i && j==s.ele[k].j)
 printf("%d ",s.ele[k++].x);
 else
 printf("0 ");
 }
 printf("\n");
 }
}
struct Sparse * add(struct Sparse *s1,struct Sparse *s2)
{
 struct Sparse *sum;
 int i,j,k;
 i=j=k=0;
 
 if(s1->n != s2->n && s1->m != s2->m)
 return NULL;
 sum=(struct Sparse *)malloc(sizeof(struct Sparse));
sum->ele=(struct Element *)malloc((s1->num+s2-
>num)*sizeof(struct Element));
 while(i<s1->num && j<s2->num)
 {
 if(s1->ele[i].i<s2->ele[j].i)
 sum->ele[k++]=s1->ele[i++];
 else if(s1->ele[i].i>s2->ele[j].i)
 sum->ele[k++]=s2->ele[j++];
 else
 {
 if(s1->ele[i].j<s2->ele[j].j)
 sum->ele[k++]=s1->ele[i++];
 else if(s1->ele[i].j>s2->ele[j].j)
 sum->ele[k++]=s2->ele[j++];
 else
 {
 sum->ele[k]=s1->ele[i];
 sum->ele[k++].x=s1->ele[i++].x+s2->ele[j+
+].x;
 }
 
 }
 }
 for(;i<s1->num;i++)sum->ele[k++]=s1->ele[i];
 for(;j<s2->num;j++)sum->ele[k++]=s2->ele[j];
 sum->m=s1->m;
 sum->n=s1->n;
 sum->num=k;
 
 
 return sum;
}
int main()
{
 struct Sparse s1,s2,*s3;
 
 create(&s1);
 create(&s2);
 
 s3=add(&s1,&s2);
 
 printf("First Matrix\n");
 display(s1);
 printf("Second Matrix\n");
 display(s2);
 printf("Sum Matrix\n");
 display(*s3);
 
 
 return 0;
*/