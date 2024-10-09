#include <stdio.h>

void enterElement(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter the element %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void deleteElement(int arr[], int *n) {
    int pos;
    printf("Enter the position of the element you want to delete: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--; 
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int flag = 0;
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int arr[size];

    while (flag == 0) {
        printf("Enter 1 to add elements to your array\n");
        printf("Enter 2 to delete an element from your array\n");
        printf("Enter 3 to find the maximum element in your array\n");
        printf("Enter 4 to print your array\n");
        printf("Enter 0 to exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterElement(arr, size);
                break;
            case 2:
                deleteElement(arr, &size);
                break;
            case 3: {
                int max = findMax(arr, size);
                printf("The maximum element is: %d\n", max);
                break;
            }
            case 4:
                printArray(arr, size);
                break;
            case 0:
                flag = 1;
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
