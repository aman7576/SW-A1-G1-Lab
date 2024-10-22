#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front, rear, size;
    int* arr;
    int capacity;
} CircularQueue;

void initQueue(CircularQueue* q, int capacity) {
    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    q->arr = (int*)malloc(q->capacity * sizeof(int));
}


int isFull(CircularQueue* q) {
    return (q->size == q->capacity);
}


int isEmpty(CircularQueue* q) {
    return (q->size == 0);
}

void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }


    if (q->front == -1) {
        q->front = 0;
    }


    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = value;
    q->size++;
    printf("%d enqueued to queue\n", value);
}


int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int value = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;


    if (q->size == 0) {
        q->front = -1;
        q->rear = -1;
    }

    printf("%d dequeued from queue\n", value);
    return value;
}

void removeDuplicates(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    int* seen = (int*)calloc(1000, sizeof(int));  
    CircularQueue* newQueue = (CircularQueue*)malloc(sizeof(CircularQueue));
    initQueue(newQueue, q->capacity);

    int count = q->size;
    for (int i = 0; i < count; i++) {
        int elem = dequeue(q);
        if (!seen[elem]) {
            enqueue(newQueue, elem);
            seen[elem] = 1; 
        }
    }



    free(q->arr);

    q->arr = newQueue->arr;
    q->front = newQueue->front;
    q->rear = newQueue->rear;
    q->size = newQueue->size;
    q->capacity = newQueue->capacity;


    free(newQueue);
    free(seen);
}

void display(CircularQueue* q){
    int size=q->size;
    int j=q->front;
    for(int i=0;i<size;i++){
        printf("%d\n",q->arr[j]);
        j=(j+1)%q->capacity;
    }
}


int main() {
    CircularQueue* q=(CircularQueue*)malloc(sizeof(CircularQueue));
    int capacity = 5;
    initQueue(q, capacity);

    

    while(1){
        int choice;
        printf("enter your choice:\n");
        printf("1. display queue\n");
        printf("2. insert in queue\n");
        printf("3. delete from queue\n");
        printf("4. remove duplicates\n");
        scanf("%d",&choice);
        if(choice==1){
            display(q);
        }
        else if(choice==2){
            int x;
            printf("enter element:");
            scanf("%d",&x);
            enqueue(q,x);
        }
        else if(choice==3){
            dequeue(q);
        }
        else if(choice==4){
            removeDuplicates(q);
        }
        
        char ch;
        printf("want to continue:");
        getchar();
        scanf("%c",&ch);
        if(ch!='y'){
            break;
        }
        else{
            continue;
        }
    }


    
    free(q->arr);

    return 0;
}
