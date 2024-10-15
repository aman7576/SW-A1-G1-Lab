#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* merge(char s1[], char s2[]) {

    char* temp = (char*)malloc(strlen(s1) + strlen(s2) + 1);
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(temp, s1);
    strcat(temp, s2);
    return temp;
}

void reverse(char s[]) {
    int length = strlen(s);
    for (int i = 0; i < length / 2; i++) {
        char temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
}

void findAndReplaceSubstring(char str[], char oldSub[], char newSub[]) {
    char buffer[256];
    char* pos;
    if ((pos = strstr(str, oldSub)) != NULL) {
        int index = pos - str;
        strncpy(buffer, str, index);
        buffer[index] = '\0';
        sprintf(buffer + index, "%s%s", newSub, pos + strlen(oldSub));
        strcpy(str, buffer);
    } else {
        printf("Substring not found.\n");
    }
}

int main() {
    char s1[100];
    char s2[100];
    
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);
    
    int flag = 1;
    int choice = 0;

    while (flag == 1) {
        printf("*************************************************************************************\n");
        printf("Enter the number corresponding to the operation you want to perform:\n");
        printf("1. Merge two strings\n2. Reverse a string\n3. Find and replace a substring\n4. Exit\n");
        printf("*************************************************************************************\n");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char* mergedString = merge(s1, s2);
                printf("Merged string: %s\n", mergedString);
                free(mergedString);
                break;
            }
            case 2: {
                char stringToReverse[100];
                printf("Enter a string to reverse: ");
                scanf("%s", stringToReverse);
                reverse(stringToReverse);
                printf("Reversed string: %s\n", stringToReverse);
                break;
            }
            case 3: {
                char str[256];
                char oldSub[100], newSub[100];
                printf("Enter a string for substring replacement: ");
                scanf("%s", str);
                printf("Enter the substring to find: ");
                scanf("%s", oldSub);
                printf("Enter the new substring to replace with: ");
                scanf("%s", newSub);
                findAndReplaceSubstring(str, oldSub, newSub);
                printf("Updated string: %s\n", str);
                break;
            }
            case 4:
                flag = 0;
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
