#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

void enterelements(int arr[], int *n) {
    int i;
    printf("Enter the number of elements: ");
    scanf("%d", n);
    if (*n > MAX_SIZE) {
        printf("Number of elements exceeds maximum array size (%d).\n", MAX_SIZE);
        return;
    }
    printf("Enter the elements:\n");
    for (i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

void deleteelement(int arr[], int *n) {
    int choice, index, i;
    if (*n == 0) {
        printf("Array is empty, nothing to delete.\n");
        return;
    }
    
    printf("Delete element from:\n");
    printf("1. Beginning\n");
    printf("2. Middle\n");
    printf("3. End\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            index = 0;
            break;
        case 2:
            if (*n % 2 == 0) {
                index = (*n / 2) - 1;
            } else {
                index = *n / 2;
            }
            break;
        case 3:
            index = *n - 1;
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }
    for (i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    } 
    (*n)--;
    printf("Element deleted successfully.\n");
}

void findlargestsmallest(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    int i, largest = INT_MIN, smallest = INT_MAX;
    for (i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);
}

int main() {
    int arr[MAX_SIZE];
    int n = 0, choice;

    do {
        printf("\nMenu:\n");
        printf("1. Enter elements in the array\n");
        printf("2. Delete elements in the array\n");
        printf("3. Find the largest and smallest element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterelements(arr, &n);
                break;
            case 2:
                deleteelement(arr, &n);
                break;
            case 3:
                findlargestsmallest(arr, n);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);
    return 0;
}