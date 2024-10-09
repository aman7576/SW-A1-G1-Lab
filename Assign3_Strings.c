#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* merge(char* s1, char *s2){
    int i = strlen(s1);  
    int j = 0;
    while (s2[j] != '\0') {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';  
    return s1;
}

char* reversal(char * str){
    int i = strlen(str) - 1;  
    int j = 0;
    char temp;
    while(j < i) {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        j++;
        i--;
    }
    return str;
}


char* replace(char* str, char* sub, char *new){
    int j = 0, index = 0, size = strlen(sub);
    int f1 = 0, f2 = 0;
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == sub[j]) {
            f1 = 1;
            int J = j;
            int k = i;
            while(size > 1) {
                if(str[k] != sub[J]) {
                    f2 = 1;
                    break;
                }
                J++;
                size--;
                k++;
            }
            index = i;
            break;
        }
    }
    
    if(f1 == 1 && f2 == 0) {
        int g = 0;
        while(new[g] != '\0') {
            str[index] = new[g];
            index++;
            g++;
        }
        return str;
    } else {
        return "No required substring found";
    }
}

int main() {
    int choice = 0;
    char s1[100];
    char s2[100];
    char s3[100];
    char s4[100];
    char sub[50];
    char new[50];
    
    printf("Options: \n");
    printf("1 : Merge \n");
    printf("2 : Reverse string \n");
    printf("3 : Find substring and replace with another \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();  
    
    do {
        if (choice == 1) {
            printf("Enter first string: ");
            fgets(s1, 100, stdin);
            s1[strcspn(s1, "\n")] = 0;  
            
            printf("Enter second string: ");
            fgets(s2, 100, stdin);
            s2[strcspn(s2, "\n")] = 0;  
            
            printf("Concatenated string is: %s\n", merge(s1, s2));

        } else if (choice == 2) {
            printf("Enter string: ");
            fgets(s3, 100, stdin);
            s3[strcspn(s3, "\n")] = 0;  
            
            printf("The reversed string is: %s\n", reversal(s3));

        } else if (choice == 3) {
            printf("Enter string: ");
            fgets(s4, 100, stdin);
            s4[strcspn(s4, "\n")] = 0;  
            
            printf("Enter substring to be found: ");
            fgets(sub, 50, stdin);
            sub[strcspn(sub, "\n")] = 0;  
            
            printf("Enter substring to replace with: ");
            fgets(new, 50, stdin);
            new[strcspn(new, "\n")] = 0;  
            
            printf("New string is: %s\n", replace(s4, sub, new));
            
        } else {
            printf("Wrong option\n");
        }
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

    } while (choice > 0 && choice < 4);

    return 0;
}
