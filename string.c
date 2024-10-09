#include <stdio.h>


void merge(char str1[], char str2[], char result[]) {
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }
    result[i] = '\0';
}

void reverse(char str[], char result[]) {
    int len = 0, i;
    while (str[len] != '\0') {
        len++;
    }
    for (i = 0; i < len; i++) {
        result[i] = str[len - i - 1];
    }
    result[len] = '\0';
}

void replace(char str[], char oldSubStr[], char newSubStr[], char result[]) {
    int i = 0, j = 0, k = 0;
    int found = 0;
    int oldLen = 0, newLen = 0;
    while (oldSubStr[oldLen] != '\0') oldLen++;
    while (newSubStr[newLen] != '\0') newLen++;

    while (str[i] != '\0') {
        found = 1;
        for (j = 0; j < oldLen; j++) {
            if (str[i + j] != oldSubStr[j]) {
                found = 0;
                break;
            }
        }
        if (found == 1) {
            for (j = 0; j < newLen; j++) {
                result[k++] = newSubStr[j];
            }
            i += oldLen;
        } else {
            result[k++] = str[i++];
        }
    }
    result[k] = '\0';
}

int main() {
    int choice = 0;
    char str1[100], str2[100], subStr[100], newSubStr[100], result[100];

    while (choice != 4) {
        printf("Menu: ");
        printf("1. Merge two strings\n");
        printf("2. Reverse a string\n");
        printf("3. Find and replace a substring\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("Enter the first string: ");
            fgets(str1, 100, stdin);

            printf("Enter the second string: ");
            fgets(str2, 100, stdin);
           
            merge(str1, str2, result);
            printf("Merged string: %s\n", result);
        } 
        else if (choice == 2) {
            printf("Enter the string to reverse: ");
            fgets(str1, 100, stdin);

            reverse(str1, result);
            printf("Reversed string: %s\n", result);
        } 
        else if (choice == 3) {
            printf("Enter the main string: ");
            fgets(str1, 100, stdin);

            printf("Enter the substring to find: ");
            fgets(subStr, 100, stdin);
        
            printf("replacing substring: ");
            fgets(newSubStr, 100, stdin);

            replace(str1, subStr, newSubStr, result);
            printf("Modified string: %s\n", result);
        } 
        else if (choice == 4) {
            printf("Exit");
        } 
        else {
            printf("Invalid choice");
        }
    }

    return 0;
}
