#include <stdio.h>
#include <limits.h>

int largest(int* arr, int n) {
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        if (maxi < arr[i]) maxi = arr[i];
    }

    return maxi;
}

int smallest(int* arr, int n) {
    int mini = INT_MAX;
    for(int i = 0; i < n; i++) {
        if (mini > arr[i]) mini = arr[i];
    }

    return mini;
}

void insert(int *arr, int n, int pos, int x) {
    int i = 0;
    while(i < pos) i++;
    int next = arr[i];
    arr[i] = x;
    int temp;
    while(i + 1 < n) {
        temp = arr[i+1];
        arr[i+1] = next;
        next = temp;
        i++;
    }

}

void delete_from(int *arr, int n, int pos) {
    int i = 0;
    while(i < pos) i++;
    int temp;
    while(i + 1 < n) {
        arr[i] = arr[i+1];
        i++;
    }
}

void display(int *arr, int n) {
    for(int i = 0; i < n; i++ ) {
        printf("%d ", arr[i]);
    }
}

int main(void) {

    int y = 1;
    int choice;
    int n = 0;
    int MAX_SIZE = 10;
    int arr[MAX_SIZE];
    for(int i =0; i < MAX_SIZE; i++) {
        arr[i] = -1;
    }
    printf("MENU DRIVER PROGRAM TO PERFORM OPERATIONS ON A ONE DIMENSIONAL ARRAY: \n");
    while(y) {
        printf("Choices: \n1. Insert elements into the array. \n2. Delete element from array.\n3. Find the smallest element in the array. \n4. Find the largest element in the array.\n");
        printf("choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                int position_insert;
                printf("Enter the position at which you want to insert element in the array :");
                scanf("%d", &position_insert);
                if (position_insert > MAX_SIZE - 1 || position_insert < 0) {printf("Invalid Position Passed. "); break;}
                printf("Enter the element that is to be inserted in the array :");
                int element;
                scanf("%d", &element);
                insert(arr, MAX_SIZE, position_insert, element);

                display(arr, MAX_SIZE);
                printf("\n");
                break;

            case 2:
                int position_delete;
                printf("Enter the position at which you want to delete element from the array :");
                scanf("%d", &position_delete);
                if (position_delete > MAX_SIZE - 1 || position_delete < 0) {printf("Invalid Position Passed. "); break;}
                delete_from(arr, MAX_SIZE, position_delete);

                display(arr, MAX_SIZE);
                printf("\n");
                break;

            case 4:
                printf("Maximum element in the array is: ");
                printf("%d\n", largest(arr, MAX_SIZE));
                break;
            
            case 3: 
                printf("Minimum element in the array is: ");
                printf("%d\n", smallest(arr, MAX_SIZE));
                break;

            default: 
                printf("Invalid choice inputted.");
                break;
        }
        

        printf("Do you wish to continue? (1: YES, 0: NO): ");
        scanf("%d", &y);
    }

}