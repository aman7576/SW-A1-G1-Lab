#include <stdio.h>

void deleteElement(int arr[], int *size, int position)
{
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int findMinimum(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int findMaximum(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];
    int size, choice, position;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Delete an element\n");
        printf("2. Find minimum element\n");
        printf("3. Find maximum element\n");
        printf("4. Display array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the position of the element to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                printf("Updated array: ");
                displayArray(arr, size);
                break;
            case 2:
                printf("Minimum element: %d\n", findMinimum(arr, size));
                break;
            case 3:
                printf("Maximum element: %d\n", findMaximum(arr, size));
                break;
            case 4:
                printf("Current array: ");
                displayArray(arr, size);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
