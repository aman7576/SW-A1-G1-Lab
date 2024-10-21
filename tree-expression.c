#include <stdio.h>
#include <stdlib.h>
//arjun yadav 23/se/32
struct Node {
    char value;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void preOrder(struct Node* node) {
    if (node == NULL)
        return;
    printf("%c ", node->value);
    preOrder(node->left); 
    preOrder(node->right);    
}

void postOrder(struct Node* node) {
    if (node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%c ", node->value);
}

int main() {
    struct Node* root = createNode('/');
    root->left = createNode('*');
    root->right = createNode('D');

    root->left->left = createNode('A');
    root->left->right = createNode('+');

    root->left->right->left = createNode('B');
    root->left->right->right = createNode('C');
    int choice;
    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. prefix\n");
        printf("2. postfix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Prefix Expression: ");
                preOrder(root);
                printf("\n");
                break;
            case 2:
                printf("Postfix Expression: ");
                postOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Exit\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
