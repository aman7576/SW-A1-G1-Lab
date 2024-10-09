#include <stdio.h>
#include <limits.h> // For INT_MAX and INT_MIN

#define MAX_SIZE 100

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Enter elements\n");
    printf("2. Delete element\n");
    printf("3. Find largest element\n");
    printf("4. Find smallest element\n");
    printf("5. Exit\n");
}

void enterElements(int arr[], int *size) {
    int n;
    printf("Enter number of elements to add: ");
    scanf("%d", &n);

    if (n > MAX_SIZE - *size) {
        printf("Cannot add more elements than the array can hold.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Element %d: ", *size + 1);
        scanf("%d", &arr[(*size)++]);
    }
}

void deleteElement(int arr[], int *size) {
    int index;
    if (*size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter index to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= *size) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element at index %d deleted.\n", index);
}

void findLargest(const int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    int largest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    printf("The largest element is: %d\n", largest);
}

void findSmallest(const int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    int smallest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    printf("The smallest element is: %d\n", smallest);
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                enterElements(arr, &size); 
                break;
            case 2: 
                deleteElement(arr, &size); 
                break;
            case 3: 
                findLargest(arr, size); 
                break;
            case 4: 
                findSmallest(arr, size); 
                break;
            case 5: 
                printf("Exiting the program.\n");
                return 0;
            default: 
                printf("Invalid choice. Please select a number between 1 and 5.\n");
            
        }
    };