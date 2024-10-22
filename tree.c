#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char value;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void preOrder(Node* root) {
    if (root == NULL) return;
    printf("%c ", root->value);
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node* root) {
    if (root == NULL) return;  
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->value);
}

void inorder(Node* root){
    if(root==NULL) return;

    inorder(root->left);
    printf("%c ",root->value);
    inorder(root->right);
}


int main(){
    Node* root=createNode('/');
    root->left=createNode('+');
    root->right=createNode('-');

    root->left->left=createNode('A');
    root->left->right=createNode('B');

    root->right->left=createNode('C');
    root->right->right=createNode('D');

    while(1){
        int choice;
        printf("options available:\n");
        printf("1. generate postfix expression\n");
        printf("2. generate prefix expression\n");
        printf("3. generate infix expression\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        if(choice==1){
            postOrder(root);
            printf("\n");
        }
        else if(choice==2){
            preOrder(root);
            printf("\n");
        }
        else if(choice==3){
            inorder(root);
            printf("\n");
        }
        else{
            printf("invalid choice");
        }
        printf("to continue press y:");
        char ch;
        getchar();
        scanf("%c",&ch);
        if(ch!='y'){
            break;
        }
    }
}
