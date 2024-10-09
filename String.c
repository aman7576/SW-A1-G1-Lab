#include <stdio.h>
#include <string.h>

void combineStrings() {
    char first[100], second[100];

    printf("Enter the first string: ");
    scanf("%s", first);

    printf("Enter the second string: ");
    scanf("%s", second);

    printf("Combined string: %s%s\n", first, second);
}


void reverseStr() {
    char input[100];
    int left, right;

    printf("Type the string you want reversed: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; 

    left = 0;
    right = strlen(input) - 1;

    while (left < right) {
        char temp = input[left];
        input[left] = input[right];
        input[right] = temp;
        left++;
        right--;
    }

    printf("Reversed string: %s\n", input);
}

void findReplaceSubstring() {
    char text[200], search[50], replace[50], updated[200];
    int i, j, found = 0, k = 0;

    printf("Enter the main string: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;  // Remove newline

    printf("What part of the string do you want to replace? ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0;

    printf("What would you like to replace it with? ");
    fgets(replace, sizeof(replace), stdin);
    replace[strcspn(replace, "\n")] = 0;

    for (i = 0; i < strlen(text); i++) {
        found = 1;
        for (j = 0; j < strlen(search); j++) {
            if (text[i + j] != search[j]) {
                found = 0;
                break;
            }
        }

        if (found == 1) {
            for (j = 0; j < strlen(replace); j++) {
                updated[k++] = replace[j];
            }
            i += strlen(search) - 1;
        } else {
            updated[k++] = text[i];
        }
    }

    updated[k] = '\0';  // Null-terminate the updated string
    printf("Updated string: %s\n", updated);
}

int main() {
    int option;

    do {
        printf("\nMenu Options:\n");
        printf("1. Combine two strings\n");
        printf("2. Reverse a string\n");
        printf("3. Find and replace a substring\n");
        printf("4. Exit\n");
        printf("Pick an option (1-4): ");
        scanf("%d", &option);
        getchar(); 

        switch (option) {
            case 1: 
                combineStrings(); 
                break;
            case 2: 
                reverseStr(); 
                break;
            case 3: 
                findReplaceSubstring(); 
                break;
            case 4: 
                printf("Goodbye!\n"); 
                break;
            default: 
                printf("Invalid choice, try again.\n");
        }
    } while (option != 4);

    return 0;
}
