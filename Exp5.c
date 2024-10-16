#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} CircularQueue;

// Initialize the queue
void initialize(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// Insert an element into the queue
void insert(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue overflow! Cannot insert %d.\n", value);
        return;
    }
    
    if (isEmpty(q)) {
        q->front = 0;
    }
    
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
    printf("Inserted %d into the queue.\n", value);
}

// Delete an element from the queue
void delete(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow! Cannot delete.\n");
        return;
    }
    
    printf("Deleted %d from the queue.\n", q->arr[q->front]);
    if (q->front == q->rear) {
        q->front = q->rear = -1;  // Queue becomes empty
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

// Display elements in the queue
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty.\n");
        return;
    }
    
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Remove duplicate elements from the queue
void removeDuplicates(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty, nothing to remove.\n");
        return;
    }
    
    int i = q->front;
    int size = (q->rear >= q->front) ? (q->rear - q->front + 1) : (MAX - q->front + q->rear + 1);
    int unique[size];
    int count = 0;
    
    while (1) {
        int duplicate = 0;
        for (int j = 0; j < count; j++) {
            if (q->arr[i] == unique[j]) {
                duplicate = 1;
                break;
            }
        }
        
        if (!duplicate) {
            unique[count++] = q->arr[i];
        }
        
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    
    initialize(q);
    for (int k = 0; k < count; k++) {
        insert(q, unique[k]);
    }
    
    printf("Duplicates removed from the queue.\n");
}

int main() {
    CircularQueue q;
    initialize(&q);

    int choice, value;
    while (1) {
        printf("\n--- Circular Queue Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Remove Duplicates\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(&q, value);
                break;
            case 2:
                delete(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                removeDuplicates(&q);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
