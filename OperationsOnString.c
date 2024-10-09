#include <stdio.h>
#include <string.h>

void mergeStrings(char str1[], char str2[], char result[])
{
    int i = 0, j = 0, k = 0;
    while (str1[i] != '\0' && str2[j] != '\0')
    {
        result[k++] = str1[i++];
        result[k++] = str2[j++];
    }
    while (str1[i] != '\0') result[k++] = str1[i++];
    while (str2[j] != '\0') result[k++] = str2[j++];
    result[k] = '\0';
}

void reverseString(char str[])
{
    int start = 0, end = strlen(str) - 1;
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void findAndReplace(char str[], char toFind[], char toReplace[])
{
    char result[200] = "";  // Resulting string after replacements
    char *pos;
    int lenToFind = strlen(toFind);

    while ((pos = strstr(str, toFind)) != NULL)
    {
        strncat(result, str, pos - str);  // Copy part before the match
        strcat(result, toReplace);        // Append replacement
        str = pos + lenToFind;            // Move past the found substring
    }
    strcat(result, str);  // Append any remaining part of the string
    strcpy(str, result);  // Copy result back to the original string
}

int main() {
    char str1[100], str2[100], result[200];
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Merge two strings\n");
        printf("2. Reverse a string\n");
        printf("3. Find and replace a substring\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                mergeStrings(str1, str2, result);
                printf("Merged string: %s\n", result);
                break;
            case 2:
                printf("Enter the string to reverse: ");
                scanf("%s", str1);
                reverseString(str1);
                printf("Reversed string: %s\n", str1);
                break;
            case 3:
                printf("Enter the main string: ");
                scanf("%s", str1);
                printf("Enter the substring to find: ");
                scanf("%s", str2);
                printf("Enter the substring to replace with: ");
                scanf("%s", result);
                findAndReplace(str1, str2, result);
                printf("String after replacement: %s\n", str1);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
