#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        if (root->left) {
            printf("(");
        }
        inOrder(root->left);
        printf("%c ", root->data);
        inOrder(root->right);
        if (root->right) {
            printf(")");
        }
    }
}

void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    struct Node* root = createNode('*');
    
    root->left = createNode('+');
    root->right = createNode('-');
    
    root->left->left = createNode('A');
    root->left->right = createNode('B');
    
    root->right->left = createNode('C');
    root->right->right = createNode('D');

    printf("Prefix expression: ");
    preOrder(root);
    printf("\n");

    printf("Infix expression: ");
    inOrder(root);
    printf("\n");

    printf("Postfix expression: ");
    postOrder(root);
    printf("\n");

    return 0;
}