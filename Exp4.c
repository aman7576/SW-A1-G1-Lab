#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char *arr;
    int max;
    int top;
} Stack;

void initializeStack(Stack *s, int size) {
    s->max = size;
    s->top = -1;
    s->arr = (char *)malloc(sizeof(char) * s->max);
}

void push(Stack *s, char ch) {
    if (s->top == s->max - 1) {
        printf("Stack Overflow\n");
    } else {
        s->arr[++(s->top)] = ch;
    }
}

void pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
    } else {
        s->top--;
    }
}

char peek(Stack *s) {
    return s->arr[s->top];
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

int main() {
    Stack s;
    int length;

    printf("Enter the length of the string: ");
    scanf("%d", &length);

    initializeStack(&s, length);
    char str[length + 1]; // Adding 1 for the null terminator

    printf("Enter the string: ");
    scanf("%s", str);

    for (int i = 0; i < length; i++) {
        if (str[i] == '(') {
            push(&s, str[i]);
        } else if (str[i] == ')') {
            if (!isEmpty(&s) && peek(&s) == '(') {
                pop(&s);
            } else {
                push(&s, str[i]);
            }
        }
    }

    if (isEmpty(&s)) {
        printf("Valid String\n");
    } else {
        printf("Invalid String\n");
    }

    free(s.arr); // Free the dynamically allocated memory

    return 0;
}
