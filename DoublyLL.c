#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* prev;
    struct node* next;
};

void InsertAtHead(struct node** head, int n){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new -> value = n;
    if (*head == NULL) {
        *head = new;
        return;
    }
    new->next = *head;
    (*head)->prev = new;
    *head = new;
    printf("Node inserted at head\n");
}

void DeleteAtHead(struct node** head){
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head) -> next;
    if (*head != NULL) {
        (*head) -> prev = NULL;
    }
    free(temp);
    printf("Node deleted from head.\n");
}

void DisplayList(struct node* head) {
    struct node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node* head;
    head = NULL;
    int choice, value;
    do{
        printf("1. Display list\n");
        printf("2. Insert element at head\n");
        printf("3. Delete element from head\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                DisplayList(head);
                break;
            case 2:
                printf("Enter the element to insert at head: ");
                scanf("%d", &value);
                InsertAtHead(&head, value);
                break;
            case 3:
                DeleteAtHead(&head);
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice!=4);
    return 0;
}