#include <stdio.h>
#include <stdlib.h>
//arjun yadav 23/se/32
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;

}

void display(struct Node* head) {

    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}

void insertdata(struct Node** head, int data) {

    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Inserted %d at the beginning.\n", data);

}

void deletedata(struct Node** head) {

    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    printf("Deleted %d from the list.\n", temp->data);
    free(temp);

}

int main() {

    struct Node* head = NULL;
    int choice, data;
    
    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Display list\n");
        printf("2. Insert data\n");
        printf("3. Delete data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(head);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertdata(&head, data);
                break;
            case 3:
                deletedata(&head);
                break;
            case 4:
                printf("Exit\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}