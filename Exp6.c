#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void displayList(struct Node* head)
{
    struct Node* temp = head;
    if (temp == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* insertAtBeginning(struct Node* head, int new_data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    new_node->prev = NULL;

    if (head != NULL)
    {
        head->prev = new_node;
    }

    head = new_node;
    printf("Inserted %d at the beginning\n", new_data);
    return head;
}

struct Node* insertAtEnd(struct Node* head, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = head;

    new_node->data = new_data;
    new_node->next = NULL;

    if(head == NULL)
    {
        new_node->prev = NULL;
        head = new_node;
        return head;
    }

    while(last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;

    printf("Inserted %d at the end\n", new_data);
    return head;
}

struct Node* deleteNode(struct Node* head, int key)
{
    struct Node* temp = head;

    if (temp == NULL)
    {
        printf("List is empty, cannot delete\n");
        return head;
    }

    while(temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element %d not found in the list\n", key);
        return head;
    }

    if (head == temp)
    {
        head = temp->next;
    }

    if(temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    if(temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    free(temp);
    printf("Deleted element %d\n", key);
    return head;
}

int main(){
    struct Node* head = NULL;
    int choice, value;

    while (1){
        printf("\nMenu:\n");
        printf("1. Display List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                displayList(head);
                break;
            case 2:
                printf("Enter the value to insert at beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 3:
                printf("Enter the value to insert at end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 4:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
