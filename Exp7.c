// choose a unique expression and store it in a binary tree. Use appropriate tree traversal to generate postfix , prefix and infix
//A * B - C / D + E ^ F + G * H
//((A * B) - (C / D)) + (E ^ F) + (G * H)

#include <stdio.h>
#include <stdlib.h>
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        if (root->left != NULL) printf("(");
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if (root->right != NULL) printf(")");
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int main() {
    struct Node* root = createNode('+');
    root->left = createNode('+');
    root->right = createNode('*');

    root->left->left = createNode('-');
    root->left->right = createNode('^');
    root->left->left->left = createNode('*');
    root->left->left->right = createNode('/');
    root->left->left->left->left = createNode('A');
    root->left->left->left->right = createNode('B');
    root->left->left->right->left = createNode('C');
    root->left->left->right->right = createNode('D');
    root->left->right->left = createNode('E');
    root->left->right->right = createNode('F');

    root->right->left = createNode('G');
    root->right->right = createNode('H');

    printf("Infix expression: ");
    inorder(root);
    printf("\n");

    printf("Prefix expression: ");
    preorder(root);
    printf("\n");

    printf("Postfix expression: ");
    postorder(root);
    printf("\n");

    return 0;
}
