#include<stdio.h>
#include<string.h>
int main()
{
    char k,str[30];
    printf("Enter name:");
    gets(str);
    int i,l=strlen(str);
    for(i=0;i<l/2;i++)
    {
      k=str[i];
        str[i]=str[l-1-i];
      str[l-1-i]=k;
    }
    
    printf("New string is %s:",str);
    
}