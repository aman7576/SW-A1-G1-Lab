#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// inorder traversal
void inorder(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        printf("(");
    }
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
    if (root->right != NULL)
    {
        printf(")");
    }
}

// pre-order traversal
void preorder(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

// post-order traversal
void postorder(struct Node* root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
}

int main()
{    
    // leaf nodes
    struct Node* A = createNode('A');
    struct Node* B = createNode('B');
    struct Node* C = createNode('C');
    struct Node* D = createNode('D');
    
    // internal nodes for operators
    struct Node* plus = createNode('+');
    struct Node* minus = createNode('-');
    struct Node* multiply = createNode('*');
    
    // tree
    plus->left = A;
    plus->right = B;
    
    minus->left = C;
    minus->right = D;
    
    multiply->left = plus;
    multiply->right = minus;

    printf("Infix Expression (In-order Traversal): ");
    inorder(multiply);
    printf("\n");

    printf("Prefix Expression (Pre-order Traversal): ");
    preorder(multiply);
    printf("\n");

    printf("Postfix Expression (Post-order Traversal): ");
    postorder(multiply);
    printf("\n");

    return 0;
}