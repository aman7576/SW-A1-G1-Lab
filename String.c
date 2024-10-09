//09-10-2024 ()
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* merge(char* str1,char* str2){
    int j=0;
    int i;
    for(i=strlen(str1);str2[j]!='\0';i++){
        str1[i]=str2[j];
        j++;
    }
    str1[i]='\0';
    return str1;
}

char* reverse(char* str){
    
}

int main()
{
    char str1[50],str2[50],str3[50];
    printf("Enter String-1 : ");
    gets(str1);
    printf("Enter String-2 : ");
    gets(str2);
    printf("The merged string : ");
    puts(merge(str1,str2));
    printf("Enter string to be reversed : ");
    gets(str3);
    puts(reverse(str3));
    return 0;
}