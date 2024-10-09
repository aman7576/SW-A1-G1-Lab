#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to display the array
void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to delete an element at a given index
int deleteElement(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        printf("Invalid index! No element deleted.\n");
        return size;
    }

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;  // Reduce size by 1 after deletion
}

// Function to find the largest element in the array
int findLargest(int arr[], int size) {
    int largest = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

// Function to find the smallest element in the array
int findSmallest(int arr[], int size) {
    int smallest = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}

int main() {
    int arr[MAX], size = 0, choice, index, element;
    int largest, smallest;
    int running = 1;

    while (running) {
        printf("\nMenu:\n");
        printf("1. Enter elements into the array\n");
        printf("2. Delete an element at a given index\n");
        printf("3. Find the largest element\n");
        printf("4. Find the smallest element\n");
        printf("5. Display the array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements to add: ");
                scanf("%d", &element);
                for (int i = 0; i < element; i++) {
                    if (size >= MAX) {
                        printf("Array is full. Cannot add more elements.\n");
                        break;
                    }
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &arr[size++]);
                }
                break;

            case 2:
                printf("Enter the index of the element to delete: ");
                scanf("%d", &index);
                size = deleteElement(arr, size, index);
                break;

            case 3:
                if (size > 0) {
                    largest = findLargest(arr, size);
                    printf("Largest element: %d\n", largest);
                } else {
                    printf("Array is empty.\n");
                }
                break;

            case 4:
                if (size > 0) {
                    smallest = findSmallest(arr, size);
                    printf("Smallest element: %d\n", smallest);
                } else {
                    printf("Array is empty.\n");
                }
                break;

            case 5:
                displayArray(arr, size);
                break;

            case 6:
                running = 0;
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
