#include <stdio.h>
#include <string.h>

void mergeTwoStrings(char string1[], char string2[]) {
    int length1 = strlen(string1);
    int length2 = strlen(string2);
    char merge[100];
    
    if(length1 + length2 > 100) {
        printf("Out of Menory"); 
    } else {
    for(int i=0; i<length1; i++) {
        merge[i] = string1[i];
    }
    for(int i=0; i<length2; i++) {
        merge[i+length1] = string2[i];
    }
    printf("New merged string is: %s\n", merge);
    }
}

void reverseTheString(char string1[] ){
    int length = strlen(string1);
    for(int i=0; i< length/2; i++) {
        char temp = string1[i];
        string1[i] = string1[length - i - 1];
        string1[length - i -1] = temp;
    }
    for(int i=0; i<length; i++) {
        printf("%c", string1[i]);
    }
    printf("\n");
}
int linearSearch(char string1[], char string2[],int length) {
    for(int i=0; i<length; i++) {
        if(string1[i] == string2[i]) {
        return i;
        }
    }
        return -1;
}
void replaceSubstring(char string1[], char string2[], char string3[]) {
    int length1 = strlen(string1); 
    int length2 = strlen(string2); 
    int length3 = strlen(string3); 
    int index;
    
    if(length1 > length2) {
        printf("Old String : %s\n", string1);
        index = linearSearch(string1, string2, length1);
        for(int i=index; i < length3; i++) {
            string1[i] = string3[i];
        }
        printf("New String : %s\n", string1);
    } 
    else if(length1 < length2) {
        printf("Old String : %s\n", string2);
        index = linearSearch(string2, string1, length2);
        for(int i=index; i < length3; i++) {
            string2[i] = string3[i];
        }
        printf("New String : %s\n", string2);
    } 
}

int main() {
    int function;
    char string1[15];
    char string2[15];
    char string3[15];
    
    int flag = 1;
    while(flag) {
      printf("******************************\n");
      printf("Choose a functionality: \n");
      printf("1. Merge Two Strings\n");
      printf("2. Reverse the Given String\n");
      printf("3. Find and Replace Substring\n");
      printf("4. EXIT\n");
      printf("******************************\n");
      scanf("%d", &function);
    
      switch(function) {
          case 1 : printf("Enter the 1st String : ");
                   scanf("%s", &string1);
                   printf("Enter the 2nd String : ");
                   scanf("%s", &string2);
                   mergeTwoStrings(string1, string2);
                   break;
                 
          case 2 : printf("Enter the String : ");
                   scanf("%s", &string1);
                   reverseTheString(string1);
                   break;
                 
          case 3 : printf("Enter the 1st String : ");
                   scanf("%s", &string1);
                   printf("Enter the 2st String : ");
                   scanf("%s", &string2);
                   printf("Enter the 3st String : ");
                   scanf("%s", &string3);
                   replaceSubstring(string1, string2, string3);
                   break;
                   
          case 4 : flag = 0;
                   break;
        }
    }
}