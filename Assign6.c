#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(int data) {
    Node* newNode = createNode(data);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}

void insertAtEnd(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next; 
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Node not found\n");
}

void displayList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Insert at beginning\n2. Insert at end\n3. Delete node\n4. Display list\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 4:
                displayList();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}