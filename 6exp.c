#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (!*head) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    struct Node* last = *head;
    while (last->next) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

void deleteNode(struct Node** head, int key) {
    if (!*head) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = *head;

    while (current) {
        if (current->data == key) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            free(current);
            printf("Deleted %d from the list.\n", key);
            return;
        }
        current = current->next;
    }
    printf("Node with data %d not found.\n", key);
}

void displayList(struct Node* head) {
    struct Node* current = head;
    if (!current) {
        printf("List is empty.\n");
        return;
    }
    while (current) {
        printf("%d <=> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("****************************************************************************\n");
        printf("Enter the number corresponding to the action you want to perform:\n");
        printf("1. Insert an element\n2. Remove an element\n3. Display the linked list\n4. Exit\n");
        printf("****************************************************************************\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("Inserted %d at the end.\n", data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
