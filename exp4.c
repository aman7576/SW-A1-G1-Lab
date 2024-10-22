#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char arr[MAX];
    int top;
} CharStack;

void initStack(CharStack *stack)
{
    stack->top = -1;
}

bool isFull(CharStack *stack)
{
    return stack->top == MAX - 1;
}

bool isEmpty(CharStack *stack)
{
    return stack->top == -1;
}

void push(CharStack *stack, char value)
{
    if (isFull(stack))
    {
        printf("Stack Overflow! Cannot push '%c'\n", value);
    }
    else
    {
        stack->arr[++(stack->top)] = value;
    }
}

char pop(CharStack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow! Cannot pop\n");
        return '\0';
    }
    else
    {
        return stack->arr[(stack->top)--];
    }
}

bool isMatchingPair(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool checkParentheses(char *expression)
{
    CharStack stack;
    initStack(&stack);

    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            push(&stack, expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if (isEmpty(&stack))
            {
                return false;
            }
            char poppedChar = pop(&stack);
            if (!isMatchingPair(poppedChar, expression[i]))
            {
                return false;
            }
        }
    }

    return isEmpty(&stack);
}

int main()
{
    char expression[MAX];

    printf("Enter a string of parentheses: ");
    scanf("%s", expression);

    if (checkParentheses(expression))
    {
        printf("Parentheses are balanced.\n");
    }
    else
    {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}
