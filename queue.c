#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

int queue[MAX];
int front = -1, rear = -1;
int isEmpty() {
    return front == -1;
}
int isFull() {
    return (front == (rear + 1) % MAX);
}
void insert(int data) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    } else {
        if (front == -1) { 
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = data;
        printf("Inserted %d into the queue.\n", data);
    }
}
void delete() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot delete.\n");
        return;
    } else {
        printf("Deleted %d from the queue.\n", queue[front]);
        if (front == rear) {

            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Circular Queue elements are: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}
void removeDuplicates() {
    if (isEmpty()) {
        printf("Queue is empty! No duplicates to remove.\n");
        return;
    }

    int temp[MAX]; 
    int tempIndex = 0;
    int i = front;

    while (1) {
        int found = 0;
        for (int j = 0; j < tempIndex; j++) {
            if (temp[j] == queue[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            temp[tempIndex++] = queue[i];
        }

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
    front = 0;
    rear = -1;
    for (int j = 0; j < tempIndex; j++) {
        rear = (rear + 1) % MAX;
        queue[rear] = temp[j];
    }

    printf("Duplicates removed successfully.\n");
}
void menu() {
    int choice, data;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Remove Duplicates\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert(data);
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
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
