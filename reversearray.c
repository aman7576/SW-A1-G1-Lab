#include <stdio.h>

void reverse(int arr[], int n) {
    for(int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

int main(void) {
    int n;
    printf("Enter The number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements space seperated: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    reverse(arr, n);

    printf("Elements in array after reversal: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}