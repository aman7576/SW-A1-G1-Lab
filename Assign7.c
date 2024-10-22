#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}


Node* constructTree(char postfix[]) {
    Node* stack[200]; 
    int top = -1;     

    for (int i = 0; i < strlen(postfix); i++) {
        if (!isOperator(postfix[i])) {
            stack[++top] = createNode(postfix[i]);
        } else {
            Node* operatorNode = createNode(postfix[i]);

            operatorNode->right = stack[top--]; 
            operatorNode->left = stack[top--];  

            stack[++top] = operatorNode; 
        }
    }

    
    return stack[top];
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root) {
    if (root) {
        printf("%c ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    char postfix[] = "ac*w/wk*+q-";
    
    Node* root = constructTree(postfix);

    printf("Infix notation: ");
    inorderTraversal(root);
    printf("\n");

    printf("Prefix notation: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postfix notation: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
