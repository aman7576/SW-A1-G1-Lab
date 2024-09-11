#include <stdio.h>
#include <limits.h>

void enterElements(int arr[], int *n) {
    int i;
    printf("How many elements do you want to enter? ");
    scanf("%d", n);
    printf("Enter the elements:\n");
    for (i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

void deleteElement(int arr[], int *n) {
    int pos, i;
    if (*n == 0) {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }
    printf("Enter the position of the element to delete: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > *n) {
        printf("Invalid position!\n");
    } else {
        for (i = pos - 1; i < *n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*n)--;
        printf("Element deleted.\n");
    }
}

void findLargestElement(int arr[], int n) {
    int i, maxElement;
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    maxElement = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    printf("The largest element is: %d\n", maxElement);
}

void findSmallestElement(int arr[], int n) {
    int i, minElement;

    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    minElement = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }
    printf("The smallest element is: %d\n", minElement);
}
void displayElement(int arr[], int *n){
    printf("Elements in array: ");
    for(int i = 0; i < *n; i++){
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[100];
    int n = 0;
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Enter elements in the array\n");
        printf("2. Delete an element from the array\n");
        printf("3. Find the largest element\n");
        printf("4. Find the smallest element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enterElements(arr, &n);
                displayElement(arr, &n);
                break;
            case 2:
                deleteElement(arr, &n);
                displayElement(arr, &n);
                break;
            case 3:
                findLargestElement(arr, n);
                break;
            case 4:
                findSmallestElement(arr, n);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}