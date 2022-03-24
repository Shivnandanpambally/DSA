#include<iostream>
#include<cstdio>
using namespace std;


class element
{
public:
    int i;
    int j;
    int x;
};

class sparse
{
private:
        int m;
        int n;
        int num;
        element *e;  /*object of class element*/

public:
    sparse(int m, int n, int num)
    {
        this->n=n;
        this->m=m;
        this->num=num;
        e=new element[this->num];
    }
    ~sparse()
    {
        delete [] e;
    }
    sparse operator +(sparse &s);
    friend istream & operator >>(istream &is, sparse &s);
    friend ostream & operator <<(ostream &os, sparse &s);
};

sparse sparse :: operator +(sparse &s)
{
    int i,j,k;
    i=j=k=0;
    if(m!=s.m || n!=s.n)
    {
        return sparse(0,0,0);
    }
    sparse *sum=new sparse(m,n,num+s.num);  /*when we are making object it create e using construcotr*/
    while(i< num && j< s.num)
    {
      if(e[i].i<s.e[j].i)
        sum->e[k++]=e[i++];
      else if(e[i].i>s.e[j].i)
        sum->e[k++]=s.e[j++];
      else
      {
        if(e[i].j<s.e[j].j)
            sum->e[k++]=e[i++];
        else if(e[i].j>s.e[j].j)
            sum->e[k++]=s.e[j++];
        else
        {
            sum->e[k]=e[i++];
            sum->e[k++].x+=s.e[j++].x;
        }
      }   
    }
    for(;i<num;i++) sum->e[k++]=e[i];
    for(;j<s.num;j++) sum->e[k++]=s.e[j];
    sum->num=k;

    return *sum;
}

istream & operator >>(istream &is, sparse &s)   /* no need of score resolution (::) because they are friend*/
{
    int i;
    cout<<"Enter the element in the array"<<endl;
    for(i=0;i<s.num;i++)
    {
       cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;
    }
    return is;  /* ########### impor */
}


ostream & operator <<(ostream &os, sparse &s)
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
    return os;
}


int main()
{
    sparse s1(5,5,5), s2(5,5,5);
    cin>>s1>>s2;
    sparse s3=s1+s2;
    cout<<s1<<endl<<s2<<endl<<s3;
    return 0;
} 



/*
   #include<iostream>
    #include<cstdio>
    using namespace std;
    
    
    class element
    {
    public:
        int i;
        int j;
        int x;
    };
    
    class sparse
    {
    private:
            int m;
            int n;
            int num;
            element *e;  
    
    public:
        sparse(int m, int n, int num)
        {
            this->n=n;
            this->m=m;
            this->num=num;
            e=new element[this->num];
        }
        ~sparse()
        {
            delete [] e;
        }
        void read()
        {
            int i;
            cout<<"Enter the element in the array"<<endl;
            for(i=0;i<num;i++)
            {
               cin>>e[i].i>>e[i].j>>e[i].x;
            }
        }
    
        void display()
        {
            int i,j,k=0;
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(i==e[k].i && j==e[k].j)
                    {
                        cout<<e[k++].x<<" ";   
                    }
                    else
                    {
                        cout<<"0 ";
                    }
                }
                cout<<endl;
            }
        }
    };
    
    int main()
    {
        sparse s1(5,5,5);
        s1.read();
        s1.display();
        return 0;
    }
*/