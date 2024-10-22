#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct CircularQueue {
    struct Node* front;
    struct Node* rear;
};

void createQueue(struct CircularQueue* q) {
    q->front = q->rear = NULL;
}

void enqueue(struct CircularQueue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (!temp) {
        printf("Memory allocation failed, cannot enqueue\n");
        return;
    }
    temp->data = value;
    temp->next = NULL;

    if (q->front == NULL) {
        q->front = q->rear = temp;
        q->rear->next = q->front;
    } else {
        q->rear->next = temp;
        q->rear = temp;
        q->rear->next = q->front;
    }
    printf("Inserted %d into the queue\n", value);
}
void dequeue(struct CircularQueue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow: Cannot dequeue, queue is empty\n");
        return;
    }
    struct Node* temp = q->front;

    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front;
    }

    printf("Deleted %d from the queue\n", temp->data);
    free(temp);
}

void display(struct CircularQueue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

void removeDuplicates(struct CircularQueue* q) {
    if (q->front == NULL) {
        printf("Queue is empty, no duplicates to remove\n");
        return;
    }

    struct Node* current = q->front;
    do {
        struct Node* runner = current;
        while (runner->next != q->front) {
            if (runner->next->data == current->data) {
                struct Node* duplicate = runner->next;
                runner->next = duplicate->next;

                // Adjust rear if necessary
                if (duplicate == q->rear) {
                    q->rear = runner;
                }

                free(duplicate);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    } while (current != q->rear->next);

    printf("Duplicates removed\n");
}

int main() {
    struct CircularQueue q;
    createQueue(&q);

    int choice, value;
    do {
        printf("\n**** MENU ****\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Remove Duplicates\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                removeDuplicates(&q);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}