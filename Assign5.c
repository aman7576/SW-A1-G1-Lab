#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = 0, rear = 0;

void enqueue(int x) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is full. Cannot insert %d\n", x);
    } else {
        queue[rear] = x;
        rear = (rear + 1) % MAX_SIZE;
    }
}

int dequeue() {
    if (front == rear) {
        printf("Queue is empty. Cannot delete\n");
        return -1;
    } else {
        int x = queue[front];
        front = (front + 1) % MAX_SIZE;
        return x;
    }
}


void display() {
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

void removeDuplicates() {
    int i, j;
    for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
        for (j = i + 1; j != rear; j = (j + 1) % MAX_SIZE) {
            if (queue[i] == queue[j]) {
                for (int k = j; k != rear; k = (k + 1) % MAX_SIZE) {
                    queue[k] = queue[(k + 1) % MAX_SIZE];
                }
                rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
                j = (j - 1 + MAX_SIZE) % MAX_SIZE;
            }
        }
    }
}

int main() {
    int choice, x;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Remove duplicates\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                x = dequeue();
                if (x != -1) {
                    printf("Deleted element: %d\n", x);
                }
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
                printf("Invalid choice\n");
        }
    }
    return 0;
}