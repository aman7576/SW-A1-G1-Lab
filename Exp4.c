// Write a program to implement character stack using an array
// Push
// Popup function using boundry condition
// Also write paranthesis correctness in a string array
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int size;
    char* arr;
};

void newStack(struct Stack* stack, int size) {
    stack->top = -1;
    stack->size = size;
    stack->arr = (char*)malloc(size * sizeof(char));
    if (!stack->arr) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Memory allocated successfully\n");
}

void push(struct Stack* stack, char ch) {
    if (stack->top == stack->size - 1) {
        printf("Stack Overflow: Cannot push '%c', stack is full\n", ch);
        return;
    }
    stack->arr[++stack->top] = ch;
}

char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return '\0'; // Return null character when stack is empty
    }
    printf("Item Popped");
    return stack->arr[stack->top--];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isParenthesisBalanced(char* exp, int size) {
    struct Stack stack;
    newStack(&stack, size);

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack)) {
                return 0;
            }
            char top = pop(&stack);
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return 0; 
            }
        }
    }
    int balanced = isEmpty(&stack);
    free(stack.arr);
    return balanced;
}


int main(){
    int size;
    printf("Enter Size: ");
    scanf("%d",&size);
    char* expression = (char*)malloc((size + 1) * sizeof(char));
    if (!expression) {
        printf("Memory allocation failed\n");
        return 1;
    }
    struct Stack stack; // Use 'stack' (lowercase) here
    newStack(&stack, size);
    int choice;
    do{
    printf("\n****MENU*****\n1.Push\n2.Pop\n3.Check Paranthesis Check\n4. Exit\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

        switch (choice) {
                case 1: {
                    char ch;
                    printf("Enter a character to push: ");
                    scanf(" %c", &ch);
                    push(&stack, ch);
                    break;
                }
                case 2: {
                    pop(&stack);
                    break;
                }
                case 3: {
                    printf("Enter an expression with parentheses: ");
                    scanf("%s", expression);
                    if (isParenthesisBalanced(expression, size)) {
                        printf("The parentheses are balanced.\n");
                    } else {
                        printf("The parentheses are not balanced.\n");
                    }
                    break;
                }
                case 4:
                    printf("Exiting program...\n");
                    break;
                default:
                    printf("Please enter a valid choice.\n");
            }
        } while (choice != 4);
    free(stack.arr);
    free(expression);
    return 0;
}

