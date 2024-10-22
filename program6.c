#include <stdio.h>
#include <stdlib.h>

// Defining a node for the doubly linked list
struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNewNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert node at the end of the list
void insertAtEnd(struct Node** head, int val) {
    struct Node* newNode = createNewNode(val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Insert node at the beginning of the list
void insertAtBegin(struct Node** head, int val) {
    struct Node* newNode = createNewNode(val);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Insert node in the middle at a specific position
void insertNode(struct Node** head, int val, int pos) {
    if (pos == 1) {
        insertAtBegin(head, val);
        return;
    }

    struct Node* newNode = createNewNode(val);
    struct Node* temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        insertAtEnd(head, val);
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

// Delete node at the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

// Delete node at the beginning
void deleteAtBegin(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Delete node in the middle at a specific position
void deleteNode(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    if (pos == 1) {
        deleteAtBegin(head);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}

// Display the elements of the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <--> ", temp->value);
        temp = temp->next;
    }
    printf("X\n");
}

// Main function to drive the menu
int main() {
    struct Node* head = NULL;
    int choice, val, pos;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Into the List.\n");
        printf("2. Delete from List.\n");
        printf("3. Display List.\n");
        printf("4. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                printf("Enter position to insert at: ");
                scanf("%d", &pos);
                insertNode(&head, val, pos);
                break;
            case 2:
                printf("Enter position to delete from: ");
                scanf("%d", &pos);
                deleteNode(&head, pos);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
