#include<stdio.h>
#include<string.h>
void reverse()
{
     char k,str[30];
    printf("Enter name:");
    scanf("%s",&str);
    int i,l=strlen(str);
    for(i=0;i<l/2;i++)
    {
      k=str[i];
        str[i]=str[l-1-i];
      str[l-1-i]=k;
    }
    
    printf("New string is %s:",str);
}
void merge()
{
    char s1[20];
    char s2[20];
    printf("Enter two strings:");
    scanf("%s",&s1);
    scanf("%s",&s2);
    strcat(s1,s2);
    printf("Merged string is %s",s1);
}
void replacement() {
    char string1[50], string2[50], string3[50];
    
    printf("Enter the main string: ");
    scanf("%s", string1);

    printf("Enter the string you want to replace: ");
    scanf("%s", string2);

    printf("Enter the string you want to add: ");
    scanf("%s", string3);

    char ans[1000] = {0};  
    int ans_idx = 0;

  
    for (int i = 0; i < strlen(string1); i++) {
        int k = 0;

         
        if (string1[i] == string2[k] && i + strlen(string2) <= strlen(string1)) {
            int j;
            for (j = i; j < i + strlen(string2); j++) {
                if (string1[j] != string2[k]) {
                    break;
                }
                k++;
            }

             
            if (j == i + strlen(string2)) {
                 
                for (int l = 0; l < strlen(string3); l++) {
                    ans[ans_idx++] = string3[l];
                }
                i = j - 1;  
            } else {
                ans[ans_idx++] = string1[i];  
            }
        } else {
            ans[ans_idx++] = string1[i];  
        }
    }

    ans[ans_idx] = '\0';  

    printf("Modified string: %s\n", ans);  
}
int main()
{
  int i=1;
  while(i)
  {
  printf("\nWhich operation do you want to do:\n");
  printf("press 1 for reverse a string\n");
  printf("press 2 for merge two string\n");
  printf("press 3 for replacement of string by other string\n");
  scanf("%d",&i);
  switch(i)
  {
    case 1:
    {
      reverse();
      break;
    }
    case 2:
    {
      merge();
      break;
  }
  case 3:
  { 
      replacement();
      break;
  }
  }

}
}
