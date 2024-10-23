#include <stdio.h>
#define MAX_SIZE 5 

int front = -1;
int rear = -1;

int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

int isEmpty() {
    return front == -1;
}

void push(int arr[], int k) {
    if (isFull()) {
        printf("Queue is full! Cannot add %d.\n", k);
        return;
    }
    if (isEmpty()) {
        front = 0; 
    }
    rear = (rear + 1) % MAX_SIZE;
    arr[rear] = k;
}

void pop(int arr[]) {
    if (isEmpty()) {
        printf("Queue is empty! Cannot remove element.\n");
        return;
    }
    if (front == rear) { 
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
}

void displayQueue(int arr[]) {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    do {
        printf("%d ", arr[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

void removeDuplicates(int arr[], int *size) {
    int hash[100] = {0};  
    int newSize = 0;

    for (int i = front; i != (rear + 1) % MAX_SIZE; i = (i + 1) % MAX_SIZE) {
        if (hash[arr[i]] == 0) {
            arr[newSize++] = arr[i];
            hash[arr[i]] = 1;
        }
    }

    front = 0;  
    rear = newSize - 1; 
    *size = newSize;
}

int main() {
    int Queue[MAX_SIZE];
    int flag = 1;
    int choice;

    while (flag) {
        printf("*****************************************************************************************\n");
        printf("Enter the number corresponding to the action you want to perform:\n");
        printf("1. Enter an element\n2. Remove an element\n3. Display the Queue\n4. Remove Duplicates\n5. Exit\n");
        scanf("%d", &choice);
        printf("*****************************************************************************************\n");

        switch (choice) {
            case 1: {
                printf("Enter the element you want to enter: ");
                int el;
                scanf("%d", &el);
                push(Queue, el);
            } 
            break;
            case 2: {
                pop(Queue);
            }
            break;
            case 3: {
                displayQueue(Queue);
            }
            break;
            case 4: {
                int size = (rear - front + MAX_SIZE) % MAX_SIZE + 1;
                if (size > 0) {
                    removeDuplicates(Queue, &size);
                    printf("Duplicates removed. New size of the queue: %d\n", size);
                    displayQueue(Queue);
                } else {
                    printf("Queue is empty!\n");
                }
            }
            break;
            case 5: {
                flag = 0;
            }
            break;
            default: {
                printf("Invalid choice! Please try again.\n");
            }
        }
    }

    return 0;
}
