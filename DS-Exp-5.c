#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

struct circularQueue {
    int items[MAX_SIZE];
    int first;
    int last;
};
void initialize(struct circularQueue *queue) {
    queue->first = -1;
    queue->last = -1;
}
int isEmpty(struct circularQueue *queue) {
    return queue->first == -1;
}
int isFull(struct circularQueue *queue) {
    return (queue->last + 1) % MAX_SIZE == queue->first;
}
void enterElementInQueue(struct circularQueue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot add Elements.\n");
    } else {
        if (isEmpty(queue)) {
            queue->first = 0;
        }
        queue->last = (queue->last + 1) % MAX_SIZE;
        queue->items[queue->last] = element;
    }
}
int deleteElementInQueue(struct circularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot delete element.\n");
        return -1;
    } else {
        int element = queue->items[queue->first];
        if (queue->first == queue->last) {
            queue->first = -1;
            queue->last = -1;
        } else {
            queue->first = (queue->first + 1) % MAX_SIZE;
        }
        return element;
    }
}
void display(struct circularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        for (int i = queue->first; i != (queue->last + 1) % MAX_SIZE; i = (i + 1) % MAX_SIZE) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}
void removeDuplicates(struct circularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        int tempQueue[MAX_SIZE];
        int tempFront = 0;
        int tempRear = -1;
        int seen[MAX_SIZE] = {0};
        for (int i = queue->first; i != (queue->last + 1) % MAX_SIZE; i = (i + 1) % MAX_SIZE) {
            if (!seen[queue->items[i]]) {
                seen[queue->items[i]] = 1;
                tempQueue[++tempRear] = queue->items[i];
            }
        }
        queue->first = tempFront;
        queue->last = tempRear;
        for (int i = 0; i <= tempRear; i++) {
            queue->items[i] = tempQueue[i];
        }
    }
}
int main() {
    struct circularQueue queue;
    initialize(&queue);
    int function, element;

    while (1) {
        printf("***************************************\n");
        printf("1. Enter an element in Circular Queue\n");
        printf("2. Delete an element in Circular Queue\n");
        printf("3. Display elements of Circular Queue\n");
        printf("4. Remove duplicates from Circular Queue\n");
        printf("5. Exit\n");
        printf("****************************************\n");
        printf("Enter your choice: ");
        scanf("%d", &function);

        switch (function) {
            case 1: printf("How many elements you want to enter : ");
                    int number;
                    scanf("%d", &number);
                    for(int i=0; i<number; i++) {
                       printf("Enter the %d element : ", i+1);
                       scanf("%d", &element);
                       enterElementInQueue(&queue, element);
                    }
                    break;
            case 2: element = deleteElementInQueue(&queue);
                    if (element != -1) {
                      printf("Deleted element: %d\n", element);
                    }
                    break;
            case 3: display(&queue);
                    break;
            case 4: removeDuplicates(&queue);
                    break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}