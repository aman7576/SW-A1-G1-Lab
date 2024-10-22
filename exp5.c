#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct
{
    int arr[MAX];
    int front;
    int rear;
    int count;
} CircularQueue;

void initQueue(CircularQueue *queue)
{
    queue->front = -1;
    queue->rear = -1;
    queue->count = 0;
}

bool isFull(CircularQueue *queue)
{
    return (queue->count == MAX);
}

bool isEmpty(CircularQueue *queue)
{
    return (queue->count == 0);
}

void insert(CircularQueue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (queue->front == -1)
    {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->arr[queue->rear] = value;
    queue->count++;
    printf("%d inserted into the queue.\n", value);
}

void delete(CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue Underflow! Cannot delete element.\n");
        return;
    }
    int deletedValue = queue->arr[queue->front];
    queue->front = (queue->front + 1) % MAX;
    queue->count--;
    if (queue->count == 0)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    printf("Deleted element: %d\n", deletedValue);
}

void display(CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i;
    for (i = 0; i < queue->count; i++)
    {
        int index = (queue->front + i) % MAX;
        printf("%d ", queue->arr[index]);
    }
    printf("\n");
}

void removeDuplicates(CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty, no duplicates to remove!\n");
        return;
    }

    int i, j, k;
    for (i = 0; i < queue->count; i++)
    {
        int index = (queue->front + i) % MAX;
        for (j = i + 1; j < queue->count; j++)
        {
            int nextIndex = (queue->front + j) % MAX;
            if (queue->arr[index] == queue->arr[nextIndex])
            {
                for (k = j; k < queue->count - 1; k++)
                {
                    int shiftIndex = (queue->front + k) % MAX;
                    int nextShiftIndex = (queue->front + k + 1) % MAX;
                    queue->arr[shiftIndex] = queue->arr[nextShiftIndex];
                }
                queue->rear = (queue->rear - 1 + MAX) % MAX;
                queue->count--;
                j--;
            }
        }
    }
    printf("Duplicates removed from the queue.\n");
}

int main()
{
    CircularQueue queue;
    initQueue(&queue);

    int choice, value;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Remove Duplicates\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(&queue, value);
            break;

        case 2:
            delete (&queue);
            break;

        case 3:
            display(&queue);
            break;

        case 4:
            removeDuplicates(&queue);
            break;

        case 5:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice! Please choose again.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}
