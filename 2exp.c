#include <stdio.h>

void print(int arr[], int n, int last_index) {
    for (int i = 0; i <= last_index; i++) {
        printf("%d     ", arr[i]);
    }
    printf("\n");
}

int isempty(int last_index) {
    return last_index < 0;
}

int main() {
    int n;
    printf("Enter the number of elements in an array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter non-zero elements in the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int last_index = n - 1;
    int choice = 0;
    int flag = 1;

    while (flag == 1) {
        printf("*************************************************************************************************\n");
        printf("Enter the number corresponding to the action you want to perform: \n");
        print(arr, n, last_index);
        printf("1. Delete an element\n2. Find the largest element\n3. Find the smallest element\n4. Exit\n");
        printf("*************************************************************************************************\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                printf("Enter the index of the element you want to delete: ");
                int el;
                scanf("%d", &el);
                
                
                if (el < 0 || el > last_index) {
                    printf("Invalid index! Please try again.\n");
                    break;
                }
                
                
                for (int i = el; i < last_index; i++) {
                    arr[i] = arr[i + 1];
                }
                last_index--;
                print(arr, n, last_index);
            }
            break;
            
            case 2: {
                if (isempty(last_index)) {
                    printf("Array is empty!\n");
                    break;
                }

                int max = arr[0];
                for (int i = 1; i <= last_index; i++) {
                    if (arr[i] > max) {
                        max = arr[i];
                    }
                }
                printf("The maximum number in the array is: %d \n", max);
            }
            break;

            case 3: {
                if (isempty(last_index)) {
                    printf("Array is empty!\n");
                    break;
                }

                int min = arr[0];
                for (int i = 1; i <= last_index; i++) {
                    if (arr[i] < min) {
                        min = arr[i];
                    }
                }
                printf("The minimum number in the array is: %d \n", min);
            }
            break;

            case 4: 
                flag = 0;
                break;

            default:
                printf("SORRY! YOU ENTERED A WRONG CHOICE!!!!!!\n");
        }
    }

    return 0;
}
