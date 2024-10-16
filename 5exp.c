#include <stdio.h>

#define MAX_SIZE 100

int front = -1;
int rear = -1;

void push(int arr[], int k) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full! Cannot add %d.\n", k);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    arr[++rear] = k;
}

void pop(int arr[]) {
    if (front == -1 || front > rear) {
        printf("Queue is empty! Cannot remove element.\n");
        return;
    }
    front++;
}

int top(int arr[]) {
    if (front == -1 || front > rear) {
        printf("Queue is empty! No top element.\n");
        return -1;
    }
    return arr[front];
}

void displayQueue(int arr[]) {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int removeDuplicates(int arr[], int *size) {
    int hash[100] = {0};
    int newSize = 0;

    for (int i = front; i <= rear; i++) {
        if (hash[arr[i]] == 0) {
            arr[newSize++] = arr[i];
            hash[arr[i]] = 1;
        }
    }

    rear = newSize - 1;
    *size = newSize;
    return newSize;
}

int main() {
    int n;
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
                int temp = top(Queue);
                if (temp != -1) {
                    pop(Queue);
                }
            }
            break;
            case 3: {
                displayQueue(Queue);
            }
            break;
            case 4: {
                int size = rear - front + 1;
                if (size > 0) {
                    removeDuplicates(Queue, &size);
                    printf("Duplicates removed. New size of the queue: %d\n", size);
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
