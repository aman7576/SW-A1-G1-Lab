// Write a menu driven C program
//     1. Merge two strings
//     2. Reverse Strings
//     3. Find a Substring and Replace it with anoother string

#include <stdio.h>
#include <string.h>
void merge(){
    char s1[15],s2[15];
    printf("Enter String 1: ");
    scanf("%s",s1);
    printf("Enter String 2: ");
    scanf("%s",s2);

    strcat(s1,s2);
    printf("Merged String is %s",s1);
    return;
}
void reverse(){
    char s1[15],s2[15];
    int a=0;
    printf("Enter String: ");
    scanf("%s",s1);
    for(int i=strlen(s1)-1;i>=0;i--){
        s2[a]=s1[i];
        a++;
    }
    s2[a] = '\0';
    printf("Reversed String: %s\n", s2);
}
void replace(){
    char s1[50], s2[20], s3[20];
    char result[70] = "";
    char *pos, *temp;
    
    printf("Enter the main string: ");
    scanf("%s", s1);
    printf("Enter the substring to find: ");
    scanf("%s", s2);
    printf("Enter the substring to replace with: ");
    scanf("%s", s3);

    temp = s1;
    while ((pos = strstr(temp, s2)) != NULL) {
        strncat(result, temp, pos - temp);
        strcat(result, s3);
        temp = pos + strlen(s2);
    }
    strcat(result, temp);
    
    printf("Updated String: %s\n", result);
}

int main(){
    int choice,flag=1;
    while (flag==1){
    printf("\nMENU\n1.Merge two strings\n2. Reverse String\n3. Find a substring and replace it with another string\n4.Exit\n");
    printf("Enter Choice: ");
    scanf("%d",&choice);
        switch (choice){
            case 1:
                merge();
                break;
            case 2:
                reverse();
                break;
            case 3:
                replace();
                break;
            case 4:
                flag=0;
                break;
            default:
                printf("Enter Valid Choice");
                break;
        }
    }
    return 0;

}
