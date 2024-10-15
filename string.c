#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void mergeStrings(char str1[], char str2[]) {
    char result[strlen(str1)+strlen(str2)+1];
    int k=0;
    for(int i=0;i<strlen(str1);i++){
        result[k]=str1[i];
        k++;
    }
    for(int i=0;i<strlen(str2);i++){
        result[k]=str2[i];
        k++;
    }
    result[k]='\0';
    printf("Merged String: %s\n", result);
}

void reverseString(char str[]) {
    int len = strlen(str);
    char temp;
    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    printf("Reversed string: %s\n", str);
}

void subString(char str[], char substr[], char newsubstr[]) {
    char buffer[100];
    char *pos;
    int index = 0;
    int strLen = strlen(substr);

    while ((pos = strstr(str, substr)) != NULL) {
        int len = pos - str;
        strncpy(buffer + index, str, len);
        index += len;
        strcpy(buffer + index, newsubstr);
        index += strlen(newsubstr);
        str += len + strLen;
    }
    
    strcpy(buffer + index, str);
    strcpy(str, buffer);
    printf("Updated string: %s\n", str);
}

int main(){
    char str1[100], str2[100], str3[100];
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Merge Two Strings\n");
        printf("2. Reverse a String\n");
        printf("3. Find and Replace Substring\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter the second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';

                mergeStrings(str1, str2);
                break;

            case 2:
                printf("Enter the string to reverse: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                reverseString(str1);
                break;

            case 3:
                printf("Enter the main string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter the substring to find: ");
                fgets(str2, 100, stdin);
                str2[strcspn(str2, "\n")] = '\0';

                printf("Enter the replacement substring: ");
                fgets(str3, 100, stdin);
                str3[strcspn(str3, "\n")] = '\0';

                subString(str1, str2, str3);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}