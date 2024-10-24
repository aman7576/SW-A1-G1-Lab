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
void preorder(struct Node* node) {
    if (node == NULL)
        return;
    printf("%c ", node->data);  
    preorder(node->left);     
    preorder(node->right);      
}
void inorder(struct Node* node) {
    if (node == NULL)
        return;
    
    if (node->left != NULL) printf("(");  
    inorder(node->left);        
    printf("%c ", node->data);  
    inorder(node->right);       
    if (node->right != NULL) printf(")");
}
void postorder(struct Node* node) {
    if (node == NULL)
        return;
    
    postorder(node->left);      
    postorder(node->right);    
    printf("%c ", node->data); 
}

int main() {
    struct Node* root = createNode('+');
    root->left = createNode('a');
    root->right = createNode('*');
    root->right->left = createNode('b');
    root->right->right = createNode('c');

    printf("Prefix (Preorder) expression: ");
    preorder(root);
    printf("\n");

    printf("Infix (Inorder) expression: ");
    inorder(root);
    printf("\n");

    printf("Postfix (Postorder) expression: ");
    postorder(root);
    printf("\n");

    return 0;
}