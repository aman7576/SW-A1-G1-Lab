#include <stdio.h>
#include <string.h>

void mergeStrings() {
    char str1[100], str2[100], merged[200];
    
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    strcpy(merged, str1);
    strcat(merged, str2);
    printf("Merged String: %s\n", merged);
}

void reverseString() {
    char str[100], reversed[100];
    int len, i;
    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);
    for(i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0';
    printf("Reversed String: %s\n", reversed);
}

void replaceSubstring() {
    char str[100], substr[100], newstr[100];
    char *pos;
    int index = 0;
    printf("Enter main string: ");
    scanf("%s", str);
    printf("Enter substring to find: ");
    scanf("%s", substr);
    printf("Enter new substring: ");
    scanf("%s", newstr);
    pos = strstr(str, substr);
    
    if (pos != NULL) {
        index = pos - str;
        str[index] = '\0';
        strcat(str, newstr);
        strcat(str, pos + strlen(substr));
        printf("String after replacement: %s\n", str);
    } else {
        printf("Substring not found!\n");
    }
}

int main() {
    int choice;
    
    while(1) {
        printf("\nMenu:\n");
        printf("1. Merge two strings\n");
        printf("2. Reverse a string\n");
        printf("3. Find and replace a substring\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                mergeStrings();
                break;
            case 2:
                reverseString();
                break;
            case 3:
                replaceSubstring();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
