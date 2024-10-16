#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5  //MAX Capacity of queue.


struct CQueue {
    int elements[MAX_SIZE];
    int head;
    int tail;
};

void initializeQueue(struct CQueue *queue) {
    queue->head = -1;
    queue->tail = -1;
}

int isQueueFull(struct CQueue *queue) {
    return ((queue->head == 0 && queue->tail == MAX_SIZE - 1) || (queue->head == queue->tail + 1));
}


int isQueueEmpty(struct CQueue *queue) {
    return (queue->head == -1);
}


void addToTail(struct CQueue *queue, int data) {
    if (isQueueFull(queue)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (queue->head == -1)
        queue->head = 0;
    
    queue->tail = (queue->tail + 1) % MAX_SIZE;
    queue->elements[queue->tail] = data;
    printf("Element %d added to queue.\n", data);
}

int removeFromHead(struct CQueue *queue) {
    int removedElement;
    if (isQueueEmpty(queue)) {
        printf("Queue Underflow!\n");
        return -1;
    }

    removedElement = queue->elements[queue->head];
    if (queue->head == queue->tail) {
        queue->head = -1;
        queue->tail = -1;
    } else {
        queue->head = (queue->head + 1) % MAX_SIZE;
    }
    
    printf("Removed element: %d\n", removedElement);
    return removedElement;
}

void showQueue(struct CQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = queue->head; i != queue->tail; i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue->elements[i]);
    }
    printf("%d\n", queue->elements[queue->tail]);
}

void showFrontElement(struct CQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d\n", queue->elements[queue->head]);
    }
}

void deleteDuplicates(struct CQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("No duplicates to remove; queue is empty.\n");
        return;
    }

    int i, j, k;
    for (i = queue->head; i != queue->tail; i = (i + 1) % MAX_SIZE) {
        j = (i + 1) % MAX_SIZE;
        while (j != (queue->tail + 1) % MAX_SIZE) {
            if (queue->elements[i] == queue->elements[j]) {
                for (k = j; k != queue->tail; k = (k + 1) % MAX_SIZE) {
                    queue->elements[k] = queue->elements[(k + 1) % MAX_SIZE];
                }
                queue->tail = (queue->tail - 1 + MAX_SIZE) % MAX_SIZE;
            } else {
                j = (j + 1) % MAX_SIZE;
            }
        }
    }
    printf("Duplicates removed.\n");
}


int main() {
    struct CQueue queue;
    initializeQueue(&queue);

    int action, element;
    do {
        printf("\nMenu:\n");
        printf("1. Insert at Tail\n");
        printf("2. Remove from Head\n");
        printf("3. Display Queue\n");
        printf("4. Show Front Element\n");
        printf("5. Remove Duplicates\n");
        printf("6. Quit\n");
        printf("Select an option: ");
        scanf("%d", &action);

        switch (action) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &element);
                addToTail(&queue, element);
                break;
            case 2:
                removeFromHead(&queue);
                break;
            case 3:
                showQueue(&queue);
                break;
            case 4:
                showFrontElement(&queue);
                break;
            case 5:
                deleteDuplicates(&queue);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid selection.\n");
        }
    } while (action != 6);

    return 0;
}
