#include <stdio.h>
#include <stdlib.h>

#define exp "A*B-C/D"

typedef struct TreeNode {
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* constructNode(char x) {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->left = NULL; node->right = NULL;
    node->val = x;
    return node;
}

void preorder(TreeNode* root) {
    if (root == NULL) return;
    printf("%c", root->val);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%c", root->val);
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->val);
}

TreeNode* constructExp(void) {
    TreeNode* root = constructNode('-');
    root->left = constructNode('*');
    root->right = constructNode('/');

    root->left->left = constructNode('A');
    root->left->right = constructNode('B');

    root->right->left = constructNode('C');
    root->right->right = constructNode('D');

    return root;
}

int main(void) {
    TreeNode* expRoot = constructExp();
    int choice;
    
    do {
        printf("\nMenu:\n");
        printf("1. Print Prefix Expression. \n");
        printf("2. Print Infix Expression.\n");
        printf("3. Print Postfix Expression.\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Prefix Expression: ");
                preorder(expRoot);
                printf("\n");
                break;
            case 2:
                printf("Infix Expression: ");
                inorder(expRoot);
                printf("\n");
                break;
            case 3:
                printf("Postfix Expression: ");
                postorder(expRoot);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
