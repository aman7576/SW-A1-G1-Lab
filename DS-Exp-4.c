#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

struct Stack {
    char items[MAX_SIZE];
    int top;
};
void initialize(struct Stack *stack) {
    stack->top = -1;
}
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(struct Stack *stack, char element) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot add element.\n");
    } else {
        stack->top++;
        stack->items[stack->top] = element;
    }
}
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Nothing to pop.\n");
        return '\0';
    } else {
        char element = stack->items[stack->top];
        stack->top--;
        return element;
    }
}
int parenthesis(char *str) {
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(&stack, str[i]);
        } else {
            if (isEmpty(&stack)) {
                return 0; 
            }

            char top = pop(&stack);
            if ((str[i] == ')' && top != '(') ||
                (str[i] == '}' && top != '{') ||
                (str[i] == ']' && top != '[')) {
                return 0; 
            }
        }
    }
    return isEmpty(&stack); 
}
int main() {
    struct Stack stack;
    initialize(&stack);

    int function, element;
    char str[MAX_SIZE];

    while (1) {
        printf("*********************************\n");
        printf("1. Push an Element\n");
        printf("2. Pop an Element\n");
        printf("3. Check parenthesis correctness\n");
        printf("4. Exit\n");
        printf("*********************************\n");
        printf("Enter your choice: ");
        scanf("%d", &function);

        switch (function) {
            case 1: int numbers;
                    printf("Enter the number of elements you want to push: ");
                    scanf("%d", &numbers);
                    for(int i=0; i<numbers; i++) {
                      printf("Enter the %d element to push: ", i+1);
                      scanf(" %c", &element);
                      push(&stack, element);
                    }
                    break;
                    
            case 2: element = pop(&stack);
                    if (element != '\0') {
                       printf("Popped element: %c\n", element);
                    }
                    break;
            case 3: printf("Enter the string: ");
                    scanf("%s", str);
                    if (parenthesis(str)) {
                        printf("Parenthesis are balanced\n");
                    } else {
                        printf("Parenthesis are not balanced\n");
                    }
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}