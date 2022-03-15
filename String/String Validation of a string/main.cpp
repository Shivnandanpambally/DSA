#include<iostream>
using namespace std;

int Valid(char * name)
{ 
  int i;
  for(i=0;name[i]!='\0';++i)
  {
    if(!(name[i]>='A'&& name[i]<='Z') || !(name[i]>='a'&& name[i]<='z') || !(name[i]>='1'&& name[i]<='9'))
    return 0;
  }
  return 1;
}

int main()
{
 char *name="John%123";
 if(Valid(name)==1)
  cout<<"User name is valid";
 else
  cout<<"User name is invalid";
}