#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue
{
    int *arr;
    int front;
    int rear;
    int max;
}queue;

void queues(queue* q, int x)
{
    q -> max = x;
    q -> arr = (int *)malloc(sizeof(int) * q -> max);
    q -> front = q -> rear = -1;
}

bool empty(queue* q)
{
    if(q -> front == -1 && q -> rear == -1)
    return true;

    else
    return false;
}

bool isFull(queue* q)
{
    if(q -> front == 0 && q -> rear == q -> max - 1)
    return true;

    else if(q -> rear == q -> front - 1)
    return true;

    else
    return false;
}

void enqueue(queue* q, int x)
{
    if(isFull(q))
    printf("Overflow\n");

    else if(empty(q))
    {
        q -> front = q -> rear = 0;
        q -> arr[q -> rear] = x;
    }

    else if(q -> rear == q -> max - 1)
    {
        q -> rear = 0;
        q -> arr[q -> rear] = x;
    }

    else
    {
        q -> rear = q -> rear + 1;
        q -> arr[q -> rear] = x;
    }
}

int dequeue(queue* q)
{
    if(empty(q))
    {
    printf("Underflow\n");
    return -1;
    }

    else if(q -> front == q -> rear)
    {
    int temp = q -> arr[q -> front];
    q -> front = q -> rear = -1;
    return temp;
    }

    else
    {
        int temp = q -> arr[q -> front];
        (q -> front)++;
        if(q -> front == q -> max)
        q -> front = 0;
        return temp;
    }
}

void removes(queue *q)
{
    if (empty(q)) 
    {
        printf("Underflow\n");
        return;
    }
    
    int mark[100000] = {0}; 
    int i = q->front;
    int s = (q->rear >= q->front) ? q->rear - q->front + 1 : q->max - (q->front - q->rear - 1);
    
    while (s--) {
        int value = dequeue(q);
        if (!mark[value]) {
            enqueue(q, value);
            mark[value] = 1;
        }
}
}

void display(queue* q) 
{
    int index = q -> front;
    if(index == -1)
    printf("Underflow \n");

    else
    {
        while(index != q -> rear && !empty(q))
        {
            printf("%d ", q -> arr[index]);
            if(index == q -> max - 1 && q -> front >= 0)
            index = 0;

            else index++;
        }
    }
    printf("%d\n", q -> arr[q -> rear]);
}

int main()
{
    queue q;
    int flag = 1, size, choice;
    printf("Enter the size of the Circular Queue: \n");
    scanf("%d", &size);

    queues(&q, size);

    printf("Menu\n1. Insert Elements\n2. Delete elements\n3. Remove Duplicates from the Queue\n4. Display Queue\n\n");

    while(flag)
    {
        printf("Enter choice: \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            int num;
            printf("Enter number of elements to be enqueued\n");
            scanf("%d", &num);
            
            printf("Enter elements:\n");
            for(int i = 0; i < num; i++)
            {
                int x;
                scanf("%d", &x);
                enqueue(&q, x);
            }
            break;

            case 2:
            int num2;
            printf("Enter number of elements to be dequeued\n");
            scanf("%d", &num2);
            
            for(int i = 0; i < num2; i++)
            dequeue(&q);

            break;

            case 3:
            removes(&q);
            break;

            case 4:
            display(&q);
            break;

            default:
            flag = 0;

        }
    }
    

    return 0;
}