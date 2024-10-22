#include <stdio.h>
#define MAX_SIZE 10

void enqueue(int queue[], int data, int *front, int *rear){
   if ((*rear + 1)% MAX_SIZE == *front){
       printf("Queue overflow\n");
       return;
   }
   if (*front == -1) {
       *front = 0;
   }
   *rear = (*rear + 1) % MAX_SIZE;
   queue[*rear] = data;
}

int dequeue(int queue[], int *front, int *rear){
   if (*front == -1) {
       printf("Queue underflow\n");
       return -1;
   }
   int data = queue[*front];
   if (*front == *rear) {
       *front = *rear = -1;
   }
   else {
       *front = (*front + 1) % MAX_SIZE;
   }
   return data;
}

void display(int queue[], int front, int rear){
   if (front == -1) {
       printf("Queue is empty\n");
       return;
   }
   printf("Queue elements: ");
   int i = front;
   while (i != rear) {
       printf("%d ", queue[i]);
       i = (i + 1) % MAX_SIZE;
   }
   printf("%d\n", queue[rear]);
}

void removeDuplicates(int queue[], int *front, int *rear) {
   if (*front == -1) {
       printf("Queue is empty\n");
       return;
   }

   int i = *front;
   while (i != *rear) {
       int j = (i + 1) % MAX_SIZE;
       while (j != (*rear + 1) % MAX_SIZE) {
           if (queue[i] == queue[j]) {
               int k = j;
               while (k != *rear) {
                   queue[k] = queue[(k + 1) % MAX_SIZE];
                   k = (k + 1) % MAX_SIZE;
               }
               *rear = (*rear - 1 + MAX_SIZE) % MAX_SIZE;
               if (*rear == -1) *rear = MAX_SIZE - 1;
           } else {
               j = (j + 1) % MAX_SIZE;
           }
       }
       i = (i + 1) % MAX_SIZE;
   }

   printf("Duplicates removed from the queue\n");
}

int main(){
   int queue[MAX_SIZE], front=-1, rear=-1;
   int choice, value;

   while (1) {
       printf("Circular Queue Menu:\n");
       printf("1. Insert\n");
       printf("2. Delete\n");
       printf("3. Display\n");
       printf("4. Remove Duplicates\n");
       printf("5. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);

       switch (choice) {
           case 1:
               printf("Enter value to insert: ");
               scanf("%d", &value);
               enqueue(queue, value, &front, &rear);
               break;
           case 2:
               dequeue(queue, &front, &rear);
               break;
           case 3:
               display(queue, front, rear);
               break;
           case 4:
               removeDuplicates(queue, &front, &rear);
               break;
           case 5:
               printf("Exiting\n");
               return 0;
           default:
               printf("Invalid choice!\n");
       }
   }

   return 0;
}