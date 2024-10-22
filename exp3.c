#include <stdio.h>
#include <string.h>
#define MAX 100
void mergeStrings(char str1[], char str2[])
{
    char result[MAX * 2];
    strcpy(result, str1);
    strcat(result, " ");
    strcat(result, str2);
    printf("Merged String: %s\n", result);
}
void reverseString(char str[])
{
    int len = strlen(str);
    printf("Reversed String: ");
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}
void replaceSubstring(char str[], char find[], char replace[])
{
    char result[MAX];
    char *pos;
    int index = 0;
    int lenFind = strlen(find);
    result[0] = '\0';
    while ((pos = strstr(str, find)) != NULL)
    {
        strncat(result, str, pos - str);
        strcat(result, replace);
        str = pos + lenFind;
    }
    strcat(result, str);
    printf("String after replacement: %s\n", result);
}
int main()
{
    char str1[MAX], str2[MAX], find[MAX], replace[MAX];
    int choice;
    int running = 1;
    while (running)
    {
        printf("\nMenu:\n");
        printf("1. Merge two strings\n");
        printf("2. Reverse a string\n");
        printf("3. Find a substring and replace it with another string\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            printf("Enter the first string: ");
            fgets(str1, MAX, stdin);
            str1[strcspn(str1, "\n")] = 0;
            printf("Enter the second string: ");
            fgets(str2, MAX, stdin);
            str2[strcspn(str2, "\n")] = 0;
            mergeStrings(str1, str2);
            break;
        case 2:
            printf("Enter a string to reverse: ");
            fgets(str1, MAX, stdin);
            str1[strcspn(str1, "\n")] = 0;
            reverseString(str1);
            break;
        case 3:
            printf("Enter the main string: ");
            fgets(str1, MAX, stdin);
            str1[strcspn(str1, "\n")] = 0;
            printf("Enter the substring to find: ");
            fgets(find, MAX, stdin);
            find[strcspn(find, "\n")] = 0;
            printf("Enter the replacement string: ");
            fgets(replace, MAX, stdin);
            replace[strcspn(replace, "\n")] = 0;
            replaceSubstring(str1, find, replace);
            break;
        case 4:
            running = 0;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}