#include <stdio.h>
#include <string.h>

void merge_strings(char string1[], char string2[], char result[]) {
    strcpy(result, string1); 
    strcat(result, string2);  
}

void reverse_string(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    int choice;
    char string1[100], string2[100], merged_string[200];
    printf("Choose an option:\n");
    printf("1. Merge two strings\n");
    printf("2. Reverse a string\n");
    scanf("%d", &choice);
    getchar(); 

    switch (choice) {
        case 1:
  
            printf("Enter the first string: ");
            gets(string1); 
            printf("Enter the second string: ");
            gets(string2);
            merge_strings(string1, string2, merged_string);
            printf("Merged string: %s\n", merged_string);
            break;

        case 2:
            printf("Enter the string to reverse: ");
            gets(string1);
            reverse_string(string1);
            printf("Reversed string: %s\n", string1);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
