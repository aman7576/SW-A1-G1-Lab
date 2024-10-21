#include <stdio.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, char c) {
    if (!isFull(s)) {
        s->arr[++s->top] = c;
    }
}

char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    }
    return '\0';
}

int isMatchingPair(char a, char b) {
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

int isParenthesisCorrect(char* expr) {
    Stack s;
    init(&s);
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(&s, expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), expr[i])) {
                return 0;
            }
        }
    }
    return isEmpty(&s);
}

int main() {
    char expr[MAX];
    printf("Enter an expression: ");
    scanf("%s", expr);
    if (isParenthesisCorrect(expr)) {
        printf("Parenthesis are correct.\n");
    } else {
        printf("Parenthesis are incorrect.\n");
    }
    return 0;
}
