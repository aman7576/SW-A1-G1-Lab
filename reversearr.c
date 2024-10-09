#include <stdio.h>

void reverseArray(int arr[], int size)
{
    int start = 0, end = size - 1;
    int temp;

    while (start < end)
    {

        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements: \n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    displayArray(arr, size);

    reverseArray(arr, size);

    printf("Reversed array: ");
    displayArray(arr, size);

    return 0;
}
