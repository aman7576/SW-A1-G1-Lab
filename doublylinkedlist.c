#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int x) {
    Node* newElement = (Node*)malloc(sizeof(Node));
    newElement->data = x;
    newElement->prev = NULL;
    newElement->next = NULL;
    return newElement;
}

void display(Node* head) {
    Node* temp = head;
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

Node* insertNode(int x, Node* head, int position) {
    Node* newElement = createNode(x);
    if (position == 1) {
        newElement->next = head;
        if (head != NULL) {
            head->prev = newElement;
        }
        head = newElement;
        return head;
    }
    Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        free(newElement);
        return head;
    }
    newElement->next = temp->next;
    newElement->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newElement;
    }
    temp->next = newElement;
    return head;
}

Node* deleteNode(Node* head, int position) {
    if (head == NULL) return head;

    Node* temp = head;
    if (position == 1) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return head;

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}

int main() {
    Node* head = NULL;
    int choice, data, size;
    while (1) {
        printf("Doubly Linked List Operations:\n");
        printf("1. Display list\n");
        printf("2. Insert data\n");
        printf("3. Delete data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            display(head);
        } else if (choice == 2) {
            int value;
            printf("enter value to add: ");
            scanf("%d", &value);
            int pos;
            printf("enter position: ");
            scanf("%d", &pos);
            head = insertNode(value, head, pos);
        } else if (choice == 3) {
            int pos;
            printf("enter position: ");
            scanf("%d", &pos);
            head = deleteNode(head, pos);
        } else if (choice == 4) {
            break;
        } else {
            printf("invalid choice\n");
        }
        char ch;
        printf("to continue press y: ");
        getchar(); 
        scanf("%c", &ch);
        if (ch != 'y') {
            break;
        }
    }
    return 0;
}
