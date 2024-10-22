#include <stdio.h>

#define MAX_SIZE 10

char data[MAX_SIZE];
int top = -1;

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == MAX_SIZE - 1);
}

void push(char c) {
    if (isFull()) {
        printf("Stack is full. Cannot push %c\n", c);
    } else {
        data[++top] = c;
    }
}

// Function to pop an element from the stack
char pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop\n");
        return '\0';
    } else {
        return data[top--];
    }
}


int checkParenthesis(char str[]) {
    int i, len = 0;

    while (str[len] != '\0') {
        len++;
    }

    for (i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (isEmpty()) {
                return 0; 
            }

            char top = pop();

            
        }
    }

    if (isEmpty()) {
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    push('A');
    push('B');
    push('C');

    printf("Popped element: %c\n", pop());
    printf("Popped element: %c\n", pop());
    printf("Popped element: %c\n", pop());

    char str[] = "(A*B+(c*(D+E)))";
    char str1[] = "(a+b+(c-d*(e+f))";
    if (checkParenthesis(str)) {
        printf("Parenthesis are balanced in the string : %s\n", str);
    } else {
        printf("Parenthesis are not balanced in the string : %s\n", str1);
    }
    if (checkParenthesis(str1)) {
        printf("Parenthesis are balanced in the string : %s\n", str);
    } else {
        printf("Parenthesis are not balanced in the string : %s\n", str1);
    }

    return 0;
}