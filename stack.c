#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 

char stack[MAX];
int top = -1; 

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(char ch) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push '%c'.\n", ch);
    } else {
        stack[++top] = ch;
        printf("Pushed '%c' onto the stack.\n", ch);
    }
}

char pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop.\n");
        return '\0';  
    } else {
        char ch = stack[top--];
        printf("Popped '%c' from the stack.\n", ch);
        return ch;
    }
}

int isBalanced(char str[]) {
    top = -1; 

    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty()) {
                return 0;  
            }
            char topChar = pop();

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return 0; 
            }
        }
    }

    return isEmpty();
}

int main() {
    int choice;
    char ch;
    char expression[MAX];

    while (1) {
        printf("\nCharacter Stack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check Parentheses Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter the character to push: ");
                scanf("%c", &ch);
                push(ch);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Enter the expression to check: ");
                scanf("%s", expression);
                if (isBalanced(expression)) {
                    printf("The parentheses are balanced.\n");
                } else {
                    printf("The parentheses are NOT balanced.\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
