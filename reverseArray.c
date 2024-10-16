#include <stdio.h>

void swaps(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int size;
    printf("Enter size of array : \n");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements :\n");

    for(int i = 0; i < size; i++)
    scanf("%d", &arr[i]);

    for(int i = size - 1; (double)i >= (double)size/2; i--)
    {
        swaps(&arr[i], &arr[size - i - 1]);
    }

    printf("\n");
    for(int i = 0; i < size; i++)
    printf("%d ", arr[i]);


    return 0;
}