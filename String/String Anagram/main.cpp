#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
 char A[]="decimal";
 char B[]="medical";
 int i;
 int H[26];
 for(i=0;i<26;i++)
  H[i]=0;
 for(i=0;A[i]!='\0';i++)
  H[A[i]-97]++;
 for(i=0;B[i]!='\0';i++)
 {
  H[B[i]-97]--;
   if(H[B[i]-97]<0)
   {
    cout<<"It is not an Anagram";
    break;
   }
 }
 if(B[i]=='\0')  
 cout<<"It is an Anagram";
}