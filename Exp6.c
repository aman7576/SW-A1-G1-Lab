#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d as the first element\n", data);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at the end\n", data);
}

void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty, cannot delete %d\n", data);
        return;
    }
    struct Node* temp = *head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found in the list\n", data);
        return;
    }
    if (temp == *head) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    } else if (temp->next == NULL) {
        temp->prev->next = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Deleted element %d from the list\n", data);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\n**** MENU ****\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
