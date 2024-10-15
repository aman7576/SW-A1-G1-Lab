#include <stdio.h>
#include <string.h>

void mergeStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i, j;

    char mergedStr[len1 + len2 + 1];

    for (i = 0; i < len1; i++)
        mergedStr[i] = str1[i];

    for (j = 0; j < len2; j++)
        mergedStr[i + j] = str2[j];

    mergedStr[len1 + len2] = '\0';

    printf("Merged string: %s\n", mergedStr);
}

void reverseString(char* str) {
    int len = strlen(str);
    int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("Reversed string: %s\n", str);
}

void replaceSubstring(char* str, char* oldSubstr, char* newSubstr) {
    int len = strlen(str);
    int oldLen = strlen(oldSubstr);
    int newLen = strlen(newSubstr);
    int i, j, k;

    for (i = 0; i < len; i++) {
        if (strncmp(str + i, oldSubstr, oldLen) == 0) {
            for (j = i + oldLen; j < len; j++)
                str[j - oldLen + newLen] = str[j];

            for (k = 0; k < newLen; k++)
                str[i + k] = newSubstr[k];

            len += newLen - oldLen;
            i += newLen - 1;
        }
    }

    printf("String after replacement: %s\n", str);
}

int main() {
    char str1[100], str2[100], oldSubstr[100], newSubstr[100];
    int choice;

    while (1) {
        printf("Menu:\n");
        printf("1. Merge two strings\n");
        printf("2. Reverse a string\n");
        printf("3. Replace substring\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                mergeStrings(str1, str2);
                break;
            case 2:
                printf("Enter the string: ");
                scanf("%s", str1);
                reverseString(str1);
                break;
            case 3:
                printf("Enter the string: ");
                scanf("%s", str1);
                printf("Enter the old substring: ");
                scanf("%s", oldSubstr);
                printf("Enter the new substring: ");
                scanf("%s", newSubstr);
                replaceSubstring(str1, oldSubstr, newSubstr);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}