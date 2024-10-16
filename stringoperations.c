#include <stdio.h>
#include <string.h>

void merge_strings(char string1[], char string2[], int a, int b) {
    char merge[200];
    for (int i = 0; i < a; i++) {
        merge[i] = string1[i];
    }
    for (int j = 0; j < b; j++) {
        merge[j + a] = string2[j];
    }
    merge[a + b] = '\0';
    printf("Merged string is: %s\n", merge);
}

void substring_replace(char string1[], char string2[], char string3[]) {
    char ans[1000] = {0};
    int ans_idx = 0;
    int i = 0;

    while (i < strlen(string1)) {
        int found = 1;
        for (int j = 0; j < strlen(string2); j++) {
            if (string1[i + j] != string2[j]) {
                found = 0;
                break;
            }
        }

        if (found) {
            for (int k = 0; k < strlen(string3); k++) {
                ans[ans_idx++] = string3[k];
            }
            i += strlen(string2);
        } else {
            ans[ans_idx++] = string1[i];
            i++;
        }
    }
    ans[ans_idx] = '\0';
    printf("Modified string: %s\n", ans);
}

void reverse_string(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    printf("Reversed string: %s\n", str);
}

int main() {
    int choice;
    char string1[100], string2[100], string3[100];
    int flag = 1;

    while (flag) {
        printf("Choose an option:\n");
        printf("1. Merge two strings\n");
        printf("2. Reverse a string\n");
        printf("3. Replace a substring\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter the first string: ");
                gets(string1);
                printf("Enter the second string: ");
                gets(string2);
                merge_strings(string1, string2, strlen(string1), strlen(string2));
                break;
            case 2:
                printf("Enter the string to reverse: ");
                gets(string1);
                reverse_string(string1);
                break;
            case 3:
                printf("Enter the original string: ");
                gets(string1);
                printf("Enter the substring to find: ");
                gets(string2);
                printf("Enter the replacement string: ");
                gets(string3);
                substring_replace(string1, string2, string3);
                break;
            case 4:
                flag = 0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
