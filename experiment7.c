#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Infix traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL) {
        printf("(");
    }
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
    if (root->right != NULL) {
        printf(")");
    }
}

// Prefix traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postfix traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
}

int main() {
    // Manually constructing the expression tree for (A + B) * (C - D)
    // Expression: * ( + A B ) ( - C D )

    struct Node* root = createNode('*');
    root->left = createNode('+');
    root->right = createNode('-');

    root->left->left = createNode('A');
    root->left->right = createNode('B');
    root->right->left = createNode('C');
    root->right->right = createNode('D');

    // Displaying Infix, Prefix, and Postfix traversals
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
