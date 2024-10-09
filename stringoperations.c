#include <stdio.h>
#include <string.h>
//arjun yadav //

void merge_strings(char string1[], char string2[], int a ,int b) {
    char merge[100];
    for(int i=0;i<a;i++){
        merge[i]=string1[i];
    }
    for(int j=0;j<b;j++){
        merge[j+a]=string2[j];
    }
    printf("Merged string is %s",merge);
}

void substring(char string1[],char string2[],char string3[]){
    {
    char ans[1000] = { 0 };
    int ans_idx = 0;
    for (int i = 0; i < strlen(string1); i++) {
        int k = 0;
        if (string1[i] == string2[k] && i + strlen(string2) <= strlen(string1)) {
            int j;
            for (j = i; j < i + strlen(string2); j++) {
                if (string1[j] != string2[k]) {
                    break;
                }
                else {
                    k = k + 1;
                }
            }
            if (j == i + strlen(string2)) {
                for (int l = 0; l < strlen(string3); l++) {
                    ans[ans_idx++] = string2[l];
                }
                i = j - 1;
            }
            else {
                ans[ans_idx++] = string3[i];
            }
        }
    }
}

void reverse_string(char str[]){
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    int choice;
    char string1[100], string2[100];
    int a=strlen(string1);
    int b=strlen(string2);
    int flag=1;

    while(flag){
        printf("Choose an option:\n");
        printf("1. Merge two strings\n");
        printf("2. Reverse a string\n");
        printf("3.Substring ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                printf("Enter the first string: ");
                gets(string1); 
                printf("Enter the second string: ");
                gets(string2);
                merge_strings(string1, string2,a,b);
                break;
            case 2:
                printf("Enter the string to reverse: ");
                gets(string1);
                reverse_string(string1);
                printf("Reversed string: %s\n", string1);
                break;
            case 3:
                printf("Enter the first string: ");
                gets(string1); 
                printf("Enter the you want to find string: ");
                gets(string2);
                printf("Enter the you want to replace with string: ");
                gets(string3);
                substring(string1,string2,string3);
                break;
            case 4:
                flag=0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}
