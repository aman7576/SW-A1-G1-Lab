#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swaps(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void mergeStrings()
{
    int len1, len2;
    int len = 0;
    printf("Enter lengths of the strings to be merged: \n");
    scanf("%d %d", &len1, &len2);

    char s1[len1], s2[len2];
    len = len1 + len2 + 1;
    char ans[len];
    
    printf("Enter two strings to be merged : \n");
    scanf("%s %s", s1, s2);

    for(int i = 0; i < len; i++)
    {
        if(i < len1)
        ans[i] = s1[i];

        else
        ans[i] = s2[i - len1];
    }

    ans[len] = '\0';
    printf("Merged String : %s", ans);
}

void reverseString()
{
    int len;
    printf("Enter the length of the string to be reversed : \n");
    scanf("%d", &len);

    char s[len];

    printf("Enter the string to be reversed : \n");
    scanf("%s", s);

    for(int i = len - 1; (double)i >= (double)len/2; i--)
    {
        swaps(&s[i], &s[len - i - 1]);
    }
    printf("Reversed String : %s", s);
}

void replaceSubstring()
{
    int len1, len2;
    printf("Enter the lengths of the string and the substring to be replaced:\n");
    scanf("%d %d", &len1, &len2);

    if(len2 > len1)
    {
        printf("Invalid Lengths");
        return;
    }

    char str[len1], s1[len2], s2[len2];

    printf("Enter the string, the substring to be replaced, and replacement string: \n");
    scanf("%s %s %s", str, s1, s2);

    for(int i = 0; i < len1 - len2 + 1; i++)
    {
        int j = 0;
        for(;j < len2; j++)
        {
            if(str[i + j] != s1[j])
            break;
        }

        if(j == len2)
        {
            for(int k = 0; k < len2; k++)
            {
                str[i + k] = s2[k];
            }
            printf("Modified String : %s", str);
            return;
        }
    }
    printf("Substring Not Found");
}

int main()
{
    int flag = 1;
    int choice;
    
    printf("Menu: \n");
    printf("1. Merge two strings \n2. Reverse a string \n3. Replace substring in a string \n");

    while(flag)
{
    printf("\nEnter choice : \n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
        mergeStrings();
        break;

        case 2:
        reverseString();
        break;

        case 3:
        replaceSubstring();
        break;

        default:
        printf("Program ends!!");
        flag = 0;
    }    
}
return 0;
}