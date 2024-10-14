#include <stdio.h>

#define MAX 100

void insert(int arr[], int *top, int num){
    if(*top==MAX){
        printf("Array Full\n");
    }
    else{
        arr[*top] = num;
        *top += 1;
    }
}

void DeleteAtStart(int arr[], int *top){
    if(*top==0){
        printf("Array Empty\n");
    }
    else{
        for(int i = 0; i<*top;i++){
            arr[i] = arr[i+1];
        }
        *top -=1;
    }
}

void DeleteAtEnd(int arr[], int *top){
    if(*top==0){
        printf("Array Empty\n");
    }
    else{
        *top -=1;
    }
}

void DeleteAtMiddle(int arr[], int *top){
    int pos;
    if(*top==0){
        printf("Array Empty\n");
    }
    else{
        printf("Enter the position at which you want to delete: ");
        scanf("%d", &pos);
        if(pos<0||pos>*top-1){
            printf("Invalid Position\n");
        }
        else{
            for(int i = pos; i<*top;i++){
                arr[i]=arr[i+1];
            }
            *top -=1;
        }
    }
}

void findMax(int arr[],int top){
    if(top==0){
        printf("Array Empty\n");
    }
    else{
        int max = arr[0];
        for (int i = 1; i < top; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        printf("Maximum value: %d\n", max);
    }
}

void findMin(int arr[],int top){
    if(top==0){
        printf("Array Empty\n");
    }
    else{
        int min = arr[0];
        for (int i = 1; i < top; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        printf("Maximum value: %d\n", min);
    }
}

void display(int arr[], int n) {
    if (n > 0) {
        printf("Array elements: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Array is empty\n");
    }
}

int main(){
    int arr[MAX];
    int top = 0;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete at Start\n");
        printf("3. Delete at Middle\n");
        printf("4. Delete at End\n");
        printf("5. Find Minimum\n");
        printf("6. Find Maximum\n");
        printf("7. Display Array\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(arr, &top, value);
                break;

            case 2:
                DeleteAtStart(arr, &top);
                break;

            case 3:
                DeleteAtMiddle(arr, &top);
                break;

            case 4:
                DeleteAtEnd(arr, &top);
                break;

            case 5:
                findMin(arr, top);
                break;

            case 6:
                findMax(arr, top);
                break;

            case 7:
                display(arr, top);
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 8);

    return 0;
}