#include <stdio.h>
#define STACK_SIZE 100

char stackArray[STACK_SIZE];
int stackIndex = -1;

void addToStack(char ch) {
    if (stackIndex < STACK_SIZE - 1) {
        stackArray[++stackIndex] = ch;
    }
}

char removeFromStack() {
    if (stackIndex >= 0) {
        return stackArray[stackIndex--];
    }
    return '\0'; 
}

int isPairMatched(char opening, char closing) {
    if (opening == '(' && closing == ')') return 1;
    if (opening == '{' && closing == '}') return 1;
    if (opening == '[' && closing == ']') return 1;
    return 0;
}

int validateParentheses(char expression[]) {
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            addToStack(expression[i]);
        } else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            char topChar = removeFromStack();
            if (!isPairMatched(topChar, expression[i])) {
                return 0;
            }
        }
    }
    return (stackIndex == -1);
}

int main() {
    char expression[STACK_SIZE];
    printf("Input your expression: ");
    scanf("%s", expression);

    if (validateParentheses(expression)) {
        printf("Parentheses are balanced\n");
    } else {
        printf("Parentheses are not balanced\n");
    }

    return 0;
}
