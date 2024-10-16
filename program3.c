#include <stdio.h>
#include <string.h>

void merge_strings() {
    char s1[100];
    char s2[100];
    printf("Enter the string-1: ");
    scanf("%s", s1);
    printf("Enter the string-2: ");
    scanf("%s", s2);
    printf("Merging string-2 into string-1..\n");
    int i = strlen(s1);
    int j;
    for(j = i; j<i+strlen(s2); j++) {
        s1[j] = s2[j-i];
    }
    s1[j] = '\0';
    printf("Resultant string is: %s", s1);
}

void reverse_string() {
    char s1[100];
    printf("Enter the string that needs to be reversed: ");
    scanf("%s", s1);

    for(int i = 0; i < strlen(s1)/2; i++) {
        char temp = s1[i];
        s1[i] = s1[strlen(s1)-i-1];
        s1[strlen(s1)-i-1] = temp;
    }

    printf("Resultant string after reversal is: %s", s1);
}

void substringfindreplace(void) {
    char m[100]; // mainstring;
    printf("Enter the main string: ");
    scanf("%s", m);

    char find[100];
    printf("Enter the substring that needs to be replaced: ");
    scanf("%s", find);

    int  i= 0, j = 0;
    int start_pos = -1, end_pos = -1;

    for(int i = 0; i < strlen(m); i++) {
        if (m[i] == find[j]) {
            start_pos = i;
            int dummy_i = i;
            while(dummy_i < strlen(m) && m[dummy_i] == find[j]) {
                dummy_i++; j++;
            }
            if (j == strlen(find))  {
                end_pos = dummy_i;
                break;
            }
            else j = 0;  start_pos = -1;
        }
    }

    if (start_pos == -1) {printf("Pattern/ substring not found in the given string."); return;}

    printf("Pattern found in main string \"%s\"  at position: %d", m, start_pos);
    char replace[100];

    printf("\nEnter the string that should replace the pattern: ");
    scanf("%s", replace);

    char newstring[100];
    int k = 0;
    i = 0;
    while(i != start_pos) {
        newstring[k] = m[i];
        k++; i++;
    }
    j = 0;
    while(j < strlen(replace)) {
        newstring[k] = replace[j];
        j++; k++;
    }
    i = end_pos;
    while(m[i] != '\0') {
        newstring[k] = m[i];
        k++;i++;
    }
    newstring[k] = '\0';

    printf("New string after replacing the pattern: %s", newstring);
    
}


int main(void) {
    printf("PROGRAM-3: MENU DRIVEN PROGRAM FOR STRINGS.\n\n");
    char y = 'Y';

    do {
        printf("1. Merge two strings\n2. Reverse strings.\n3. Find a substring and replace it with another string.\n");
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                merge_strings();
                break;
            case 2:
                reverse_string();
                break;
                
            case 3:
                substringfindreplace();
                break;
            default:
                printf("Invalid choice entered.\n");
                break;
        }

        printf("\n\nContinue? (Y/N): ");
        scanf(" %c", &y);  

    } while (y == 'Y' || y == 'y');

    return 0;
}
