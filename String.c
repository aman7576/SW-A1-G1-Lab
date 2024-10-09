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
    int j=strlen(str)-1;
    char temp;
    for(int i=0;i<strlen(str)/2;i++){
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        j--;
    }
    return str;
}

char* substring(char* str,char* substr,char* replacestr){
    int j=0,index,size=strlen(substr),flag1=0,flag2=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==substr[j]){
            flag1=1;
            int J=j;
            int k=i;
            while(size-1>0){
                if(str[k]!=substr[J]){
                    flag2=1;
                    break;
                }
                J++;
                size--;
                k++;
            }
            index=i;
            break;
        }
    }
    if(flag1=1 && flag2==0){
        int g=0;
        while(substr[g]!='\0'){
            str[index]=replacestr[g];
            index++;
            g++;
        }
        return str;
    }
    else{
        return "No such substring";
    }
    
}

int main()
{
    char str1[50],str2[50],str3[50],str4[50],substr[30],newstr[30];
    int choice;
    while(1){
        printf("1.Merge\n2.Reverse\n3.Substring\n4.Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter String-1 : ");
            getchar();
            gets(str1);
            printf("Enter String-2 : ");
            
            gets(str2);
            printf("The merged string : ");
            puts(merge(str1,str2));
        }
        else if(choice==2){
            printf("Enter string to be reversed : ");
            getchar();
            gets(str3);
            puts(reverse(str3));
        }
        else if(choice==3){
            printf("Enter main string : ");
            getchar();
            gets(str4);
            printf("Enter substring : ");
            
            gets(substr);
            printf("Enter new substring : ");
            
            gets(newstr);
            puts(substring(str4,substr,newstr));
        }
        else if(choice==4){
            break;
        }
        else{
            printf("Invalid Choice\n");
        }
    }
    
    
    return 0;
}