/*
choose a unique expression and store it in a binary tree. Use appropriate tree traversal to generate postfix , prefix and infix
*/


#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new tree node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inorder traversal (Infix expression)
void inorder(struct Node* node) {
    if (node == NULL)
        return;
    
    // Traverse the left subtree
    inorder(node->left);
    
    // Visit the root (current node)
    printf("%c ", node->data);
    
    // Traverse the right subtree
    inorder(node->right);
}

// Preorder traversal (Prefix expression)
void preorder(struct Node* node) {
    if (node == NULL)
        return;
    
    // Visit the root (current node)
    printf("%c ", node->data);
    
    // Traverse the left subtree
    preorder(node->left);
    
    // Traverse the right subtree
    preorder(node->right);
}

// Postorder traversal (Postfix expression)
void postorder(struct Node* node) {
    if (node == NULL)
        return;
    
    // Traverse the left subtree
    postorder(node->left);
    
    // Traverse the right subtree
    postorder(node->right);
    
    // Visit the root (current node)
    printf("%c ", node->data);
}

// Main function to demonstrate the traversals
int main() {
    // Manually constructing the binary tree for expression: ((3 + 2) * (5 - 4))
    
    // Creating nodes for the expression
    struct Node* root = createNode('*');
    
    root->left = createNode('+');
    root->right = createNode('-');
    
    root->left->left = createNode('3');
    root->left->right = createNode('2');
    
    root->right->left = createNode('5');
    root->right->right = createNode('4');
    
    printf("Infix Expression (Inorder Traversal): ");
    inorder(root);
    printf("\n");
    
    printf("Prefix Expression (Preorder Traversal): ");
    preorder(root);
    printf("\n");
    
    printf("Postfix Expression (Postorder Traversal): ");
    postorder(root);
    printf("\n");
    
    return 0;
}
