#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* merge(char* str1, char* str2) {
    char* result = (char*)malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

char* reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return str;
}

char* substring(char* str, char* substr, char* new_substr) {
    static char buffer[1024];
    char* pos;

    if (!(pos = strstr(str, substr))) {
        return str; 
    }

    strncpy(buffer, str, pos - str);
    buffer[pos - str] = '\0';

    
    strcat(buffer, new_substr);


    strcat(buffer, pos + strlen(substr));

    strcpy(str, buffer);
    return str;
}

int main() {
    int flag = 1;
    char str1[100], str2[100], str3[100];

    while (flag) {
        printf("Please Select an option \n");
        printf("1. Merge Two strings \n");
        printf("2. Reverse strings\n");
        printf("3. Find a substring and replace it with another string\n");
        printf("4. Exit \n");

        int a;
        scanf("%d", &a);
        getchar(); 
        printf("\n");

        if (a == 1) {
            printf("Enter String-1: ");
            fgets(str1, sizeof(str1), stdin);
            str1[strcspn(str1, "\n")] = 0; 

            printf("Enter String-2: ");
            fgets(str2, sizeof(str2), stdin);
            str2[strcspn(str2, "\n")] = 0; 

            char* result = merge(str1, str2);
            printf("The merged string: %s\n", result);
            free(result);
        } else if (a == 2) {
            printf("Enter string to be reversed: ");
            fgets(str3, sizeof(str3), stdin);
            str3[strcspn(str3, "\n")] = 0; 
            printf("Reversed string: %s\n", reverse(str3));
        } else if (a == 3) {
            printf("Enter the main string: ");
            fgets(str1, sizeof(str1), stdin);
            str1[strcspn(str1, "\n")] = 0; 

            printf("Enter the substring to find: ");
            fgets(str2, sizeof(str2), stdin);
            str2[strcspn(str2, "\n")] = 0; 

            printf("Enter the replacement string: ");
            fgets(str3, sizeof(str3), stdin);
            str3[strcspn(str3, "\n")] = 0; 

            printf("The new string: %s\n", substring(str1, str2, str3));
        } else {
            flag = 0;
        }
    }
}