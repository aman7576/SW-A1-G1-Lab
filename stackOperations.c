#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    char stackArray[MAX];
} CharStack;

void initialize(CharStack* s) {
    s->top = -1;
}

bool isFull(CharStack* s) {
    return s->top == MAX - 1;
}

bool isEmpty(CharStack* s) {
    return s->top == -1;
}

void push(CharStack* s, char c) {
    if (!isFull(s)) {
        s->stackArray[++(s->top)] = c;
    }
}

char pop(CharStack* s) {
    if (!isEmpty(s)) {
        return s->stackArray[(s->top)--];
    }
    return '\0';
}

bool checkParentheses(const char* expr) {
    CharStack s;
    initialize(&s);
    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s)) return false;
            char top = pop(&s);
            if ((ch == ')' && top != '(') || 
                (ch == '}' && top != '{') || 
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return isEmpty(&s);
}

int main() {
    char expr[] = "{[()]}";
    if (checkParentheses(expr)) {
        printf("Parentheses are balanced\n");
    } else {
        printf("Parentheses are not balanced\n");
    }
    return 0;
}
