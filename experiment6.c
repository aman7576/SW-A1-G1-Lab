#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    // If the list is empty, new node becomes the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node by value
void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;

    // If the list is empty
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Traverse the list to find the node to delete
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    // Node not found
    if (temp == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
    }

    // If the node is the head node
    if (temp == *head) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    // If the node is the last node
    if (temp->next == NULL) {
        temp->prev->next = NULL;
        free(temp);
        return;
    }

    // If the node is in between
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

// Function to display the list
void display(struct Node* head) {
    struct Node* temp = head;

    // If the list is empty
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Traverse and print the list
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert elements into the list
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);

    printf("List after insertion: ");
    display(head);

    // Delete an element from the list
    deleteNode(&head, 20);
    printf("List after deletion of 20: ");
    display(head);

    // Try to delete an element not in the list
    deleteNode(&head, 40);

    return 0;
}
