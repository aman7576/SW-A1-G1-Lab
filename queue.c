#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Define the maximum size of the queue

// Structure for the circular queue
typedef struct {
    int data[SIZE];
    int front, rear;
} CircularQueue;

// Function Prototypes
void initializeQueue(CircularQueue *q);
int isFull(CircularQueue *q);
int isEmpty(CircularQueue *q);
void insert(CircularQueue *q, int value);
int delete(CircularQueue *q);
void removeDuplicates(CircularQueue *q);
void display(CircularQueue *q);

// Main function: Menu-driven interface
int main() {
    CircularQueue q;
    initializeQueue(&q);

    int choice, value;

    while (1) {
        printf("\n---- Circular Queue Menu ----\n");
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
                value = delete(&q);
                if (value != -1)
                    printf("Deleted element: %d\n", value);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                removeDuplicates(&q);
                printf("Duplicates removed (if any).\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Initialize the circular queue
void initializeQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(CircularQueue *q) {
    return ((q->rear + 1) % SIZE == q->front);
}

// Check if the queue is empty
int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

// Insert an element into the queue
void insert(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert %d.\n", value);
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % SIZE;
    }
    q->data[q->rear] = value;
    printf("%d inserted into the queue.\n", value);
}

// Delete an element from the queue
int delete(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! No elements to delete.\n");
        return -1;
    }

    int value = q->data[q->front];
    if (q->front == q->rear) {
        // Reset the queue if it's empty after deletion
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    return value;
}

// Remove duplicate elements from the queue
void removeDuplicates(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No duplicates to remove.\n");
        return;
    }

    int temp[SIZE];  // Temporary array to store unique elements
    int tempIndex = 0;

    for (int i = q->front; ; i = (i + 1) % SIZE) {
        int isDuplicate = 0;
        // Check if the current element is already in the temporary array
        for (int j = 0; j < tempIndex; j++) {
            if (temp[j] == q->data[i]) {
                isDuplicate = 1;
                break;
            }
        }
        // If not a duplicate, store it in the temporary array
        if (!isDuplicate) {
            temp[tempIndex++] = q->data[i];
        }
        if (i == q->rear) break;
    }

    // Reinitialize the queue with unique elements only
    initializeQueue(q);
    for (int i = 0; i < tempIndex; i++) {
        insert(q, temp[i]);
    }
}

// Display the elements in the queue
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; ; i = (i + 1) % SIZE) {
        printf("%d ", q->data[i]);
        if (i == q->rear) break;
    }
    printf("\n");
}
