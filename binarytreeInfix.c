#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Stack structure for building the expression tree
struct Stack {
    int top;
    int capacity;
    struct Node** array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (struct Node**)malloc(stack->capacity * sizeof(struct Node*));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, struct Node* node) {
    stack->array[++stack->top] = node;
}

struct Node* pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

struct Node* buildExpressionTree(char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    struct Node* node, *node1, *node2;

    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];

        if (isalpha(ch)) {
            node = createNode(ch);
            push(stack, node);
        } else if (isOperator(ch)) {
            node = createNode(ch);
            node1 = pop(stack);
            node2 = pop(stack);
            node->right = node1;
            node->left = node2;
            push(stack, node);
        }
    }
    return pop(stack);
}

void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    if (isOperator(root->data))
        printf("(");
    inorderTraversal(root->left);
    printf("%c", root->data);
    inorderTraversal(root->right);
    if (isOperator(root->data))
        printf(")");
}

void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    printf("%c", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c", root->data);
}

int main() {
    char postfix[100];
    struct Node* root = NULL;
    int choice;

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    root = buildExpressionTree(postfix);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Infix Expression\n");
        printf("2. Prefix Expression\n");
        printf("3. Postfix Expression\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Infix Expression: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 2:
                printf("Prefix Expression: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Postfix Expression: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
