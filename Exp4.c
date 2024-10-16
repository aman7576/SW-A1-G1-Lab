#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push '%c'.\n", c);
    } else {
        s->arr[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop.\n");
        return '\0';
    } else {
        return s->arr[(s->top)--];
    }
}

bool isOpeningParenthesis(char c) {
    return c == '(' || c == '{' || c == '[';
}

bool isClosingParenthesis(char c) {
    return c == ')' || c == '}' || c == ']';
}

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool checkParentheses(char *expression) {
    Stack s;
    initialize(&s);
    
    for (int i = 0; i < strlen(expression); i++) {
        if (isOpeningParenthesis(expression[i])) {
            push(&s, expression[i]);
        } else if (isClosingParenthesis(expression[i])) {
            if (isEmpty(&s)) {
                return false;  // No matching opening parenthesis
            }
            char topChar = pop(&s);
            if (!isMatchingPair(topChar, expression[i])) {
                return false;  // Mismatched pair
            }
        }
    }
    return isEmpty(&s);  // Stack should be empty if balanced
}

// Main function
int main() {
    char expression[MAX];
    printf("Enter an expression to check for balanced parentheses: ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = '\0';  // Remove newline character

    if (checkParentheses(expression)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
