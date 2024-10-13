#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char x) {
    if (stack->top >= (MAX - 1)) {
        printf("Stack Overflow\n");
    } else {
        stack->arr[++(stack->top)] = x;
    }
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack->arr[(stack->top)--];
    }
}

bool areParenthesesBalanced(char str[]) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack)) {
                return false;
            }
            char top = pop(&stack);

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return isEmpty(&stack);
}

int main() {

    char expr[MAX];

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (areParenthesesBalanced(expr)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
