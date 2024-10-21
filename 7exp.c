#include <stdio.h>
#include <stdlib.h>

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

void infixTraversal(struct Node* node) {
    if (node == NULL) return;
    infixTraversal(node->left);
    printf("%c ", node->data);
    infixTraversal(node->right);
}

void prefixTraversal(struct Node* node) {
    if (node == NULL) return;
    printf("%c ", node->data);
    prefixTraversal(node->left);
    prefixTraversal(node->right);
}

void postfixTraversal(struct Node* node) {
    if (node == NULL) return;
    postfixTraversal(node->left);
    postfixTraversal(node->right);
    printf("%c ", node->data);
}

int main() {
    struct Node* root = createNode('*');
    root->left = createNode('+');
    root->right = createNode('C');
    root->left->left = createNode('A');
    root->left->right = createNode('B');

    printf("Infix Expression: ");
    infixTraversal(root);
    printf("\n");

    printf("Prefix Expression: ");
    prefixTraversal(root);
    printf("\n");

    printf("Postfix Expression: ");
    postfixTraversal(root);
    printf("\n");

    return 0;
}
