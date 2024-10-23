#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void mergeStrings() {
    char str1[MAX_SIZE], str2[MAX_SIZE], result[2 * MAX_SIZE];
    printf("Enter the first string: ");
    scanf(" %[^\n]", str1);
    printf("Enter the second string: ");
    scanf(" %[^\n]", str2);
    strcpy(result, str1);
    strcat(result, str2);
    printf("Merged string: %s\n", result);
}

void reverseString() {
    char str[MAX_SIZE], reversed[MAX_SIZE];
    int length, i;
    printf("Enter a string to reverse: ");
    scanf(" %[^\n]", str);
    length = strlen(str);
    for (i = 0; i < length; i++)
        reversed[i] = str[length - i - 1];
    reversed[length] = '\0';
    printf("Reversed string: %s\n", reversed);
}

void findAndReplaceSubstring() {
    char str[MAX_SIZE], substr[MAX_SIZE], replacement[MAX_SIZE], result[MAX_SIZE], *pos;
    int index = 0;

    printf("Enter the main string: ");
    scanf(" %[^\n]", str);
    printf("Enter the substring to find: ");
    scanf(" %[^\n]", substr);
    printf("Enter the replacement string: ");
    scanf(" %[^\n]", replacement);

    result[0] = '\0';
    while ((pos = strstr(str + index, substr)) != NULL) {
        strncat(result, str + index, pos - (str + index));
        strcat(result, replacement);
        index = pos - str + strlen(substr);
    }
    strcat(result, str + index);
    printf("String after replacement: %s\n", result);
}

int main() {
    int choice;
    do {
        printf("\nMenu:\n1. Merge two strings\n2. Reverse a string\n3. Find and replace a substring\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: mergeStrings(); break;
            case 2: reverseString(); break;
            case 3: findAndReplaceSubstring(); break;
            case 4: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
