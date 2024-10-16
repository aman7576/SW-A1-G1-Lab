#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack
{
    char *arr;
    int max;
    int top;

} stack;

    void stacks(stack *s, int x)
    {
        s -> max = x;
        s -> top = -1;
        s -> arr = (char*)malloc(sizeof(char) * s -> max);
    }

    void push(stack *s, char ch)
    {
        if(s -> top == (s -> max) - 1)
        printf("Stack Overflow");

        else
        s -> arr[++ (s -> top)] = ch;
    }

    void pop(stack *s)
    {
        if(s -> top == -1)
        printf("Stack Underflow");

        else
            s -> top--;
    }

    char top(stack *s)
    {
        char temp = s -> arr[s -> top];
        return temp;
    }

    bool empty(stack *s)
    {
        if(s -> top == -1)
        return true;

        else
        return false;
    }

int main()
{
    stack s;
    int length;
   printf("Enter the length of the string: \n");
   scanf("%d", &length);

   stacks(&s, length);
   char str[length];

   printf("Enter the string: \n");
   scanf("%s", str);

   for(int i = 0; i < length; i++)
   {
    if(str[i] == '(')
    push(&s, str[i]);

    else if(str[i] == ')')
    {
        if(top(&s) == '(')
        pop(&s);

        else
        push(&s, str[i]);
    } 
   }

   if(empty(&s))
   printf("Valid String\n");

   else
   printf("Invalid String\n");

    return 0;
}