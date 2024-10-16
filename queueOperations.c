#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isFull() {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

void insert(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert element\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

void delete() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to delete\n");
        return;
    }

    printf("Deleted %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void removeDuplicates() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = front; i != rear; i = (i + 1) % MAX) {
        for (int j = (i + 1) % MAX; j != (rear + 1) % MAX; j = (j + 1) % MAX) {
            if (queue[i] == queue[j]) {
                for (int k = j; k != rear; k = (k + 1) % MAX) {
                    queue[k] = queue[(k + 1) % MAX];
                }
                rear = (rear - 1 + MAX) % MAX;
                j = (j - 1 + MAX) % MAX;  // Re-check the shifted element
            }
        }
    }

    printf("Duplicates removed.\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Remove Duplicates\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                removeDuplicates();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}