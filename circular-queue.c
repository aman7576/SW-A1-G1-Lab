#include <stdio.h>
#include <stdlib.h>
// Arjujn yadav 16/10/24

#define MAX 100

int arr[MAX];
int front = -1;
int rear = -1;

void initialize() {
    front = -1;
    rear = -1;
}

int isFull() {
    return (front == (rear + 1) % MAX);
}

int isEmpty() {
    return (front == -1);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    int i = front;
    printf("Queue elements: ");
    do {
        printf("%d ", arr[i]);
        i = (i + 1) % MAX;
    } while (i != (rear + 1) % MAX);
    printf("\n");
}

void insert(int n) {
    int a;
    
    for (int i = 0; i < n; i++) {
        if (isFull()) {
            printf("Queue Overflow. Cannot insert more elements.\n");
            return;
        }

        printf("Enter element %d: ", i + 1);
        scanf("%d", &a);

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = a;
    }
}

void deleteElement() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", arr[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void removeDuplicates() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    int i = front;
    int j;
    do {
        j = (i + 1) % MAX;
        while (j != (rear + 1) % MAX) {
            if (arr[i] == arr[j]) {
                for (int k = j; k != rear; k = (k + 1) % MAX) {
                    arr[k] = arr[(k + 1) % MAX];
                }
                rear = (rear - 1 + MAX) % MAX;
            } else {
                j = (j + 1) % MAX;
            }
        }
        i = (i + 1) % MAX;
    } while (i != rear);
}

int main() {
    int n, a;

    do {
        printf("\nCircular Queue Menu:\n");
        printf("1. Display elements\n");
        printf("2. Insert an element\n");
        printf("3. Delete an element\n");
        printf("4. Remove duplicates\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter the no of element you want to insert: ");
                scanf("%d", &a);
                insert(a);
                break;
            case 3:
                deleteElement();
                break;
            case 4:
                removeDuplicates();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (n != 5);

    return 0;
}
