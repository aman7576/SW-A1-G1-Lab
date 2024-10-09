#include <stdio.h>
#include <string.h>

void mergestrings() {
    char string1[100], string2[100];
    
    printf("Enter the first string: ");
    scanf(" %[^\n]%*c", string1);
    
    printf("Enter the second string: ");
    scanf(" %[^\n]%*c", string2);
    
    strcat(string1, string2);
    
    printf("Merged String: %s\n", string1);
}

void reversestring() {
    char string[100];
    int length, i;
    
    printf("Enter a string to reverse: ");
    scanf(" %[^\n]%*c", string);
    
    length = strlen(string);
    
    printf("Reversed String: ");
    for(i = length - 1; i >= 0; i--) {
        putchar(string[i]);
    }
    printf("\n");
}

void findreplace() {
    char string[100], substr[50], replacement[50], result[100];
    char *pos;
    int index = 0;

    printf("Enter the main string: ");
    scanf(" %[^\n]%*c", string);
    
    printf("Enter the substring to find: ");
    scanf(" %[^\n]%*c", substr);
    
    printf("Enter the replacement string: ");
    scanf(" %[^\n]%*c", replacement);
    
    pos = strstr(string, substr);
    
    if(pos != NULL) {

        index = pos - string;
        strncpy(result, string, index);
        result[index] = '\0';

        strcat(result, replacement);

        strcat(result, pos + strlen(substr));
        
        printf("Modified String: %s\n", result);
    } else {
        printf("Substring not found!\n");
    }
}

int main() {
    int choice;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Merge Two Strings\n");
        printf("2. Reverse a String\n");
        printf("3. Find a Substring and Replace it\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                mergestrings();
                break;
            case 2:
                reversestring();
                break;
            case 3:
                findreplace();
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