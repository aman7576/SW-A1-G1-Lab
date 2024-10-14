#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* merge(char* str1, char* str2) {

    int length = strlen(str1) + strlen(str2) + 1;
    char* str3 = (char*)malloc(length * sizeof(char));
    int k = 0;
    for (int i = 0; i < strlen(str1); i++) {
        str3[k++] = str1[i];
    }

    for (int i = 0; i < strlen(str2); i++) {
        str3[k++] = str2[i];
    }

    str3[k] = '\0'; 
    return str3;
}

void reverse(char* str1){
    int i=0,j=strlen(str1)-1;
    while(j>i){
        char temp=str1[i];
        str1[i]=str1[j];
        str1[j]=temp;
        i++;
        j--;
    }
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


int main() {
    int choice;
    
    char str1[50],str2[50],str3[50],str4[50],substr[30],newstr[30];

    
    while(1){
        printf("Enter your choice (1 to merge strings): ");
        scanf("%d", &choice);
        if (choice == 1) {
        char str1[30], str2[10];
        printf("Enter the first string: ");
        getchar(); 
        fgets(str1, sizeof(str1), stdin);
        str1[strcspn(str1, "\n")] = '\0'; 

        printf("Enter the second string: ");
        fgets(str2, sizeof(str2), stdin);
        str2[strcspn(str2, "\n")] = '\0';
        char* str3 = merge(str1, str2);
        printf("Merged string: ");
        puts(str3);

        free(str3);

        }

        else if(choice==2){
            int n;
            printf("enter length:");
            scanf("%d",&n);
            char* str1 = (char*)malloc(n * sizeof(char));
            printf("enter word:");
            getchar();
            gets(str1);
            reverse(str1);
            puts(str1);
            free(str1);
            
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
        else{
            printf("invalid choice");
        }
        printf("want to continue ?");
        char c;
        scanf("%c",&c);
        if(c!='y'){
            break;
        }else{
            continue;
        }      
    }


    return 0;
}
