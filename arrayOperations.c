#include <stdio.h>
#include <stdlib.h>

int size;
int *arr;
void getElements()
{
    printf("Enter elements into the array: \n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void deleteElement()
{
    int index;
    printf("Enter the index of element to be deleted: \n");
    scanf("%d", &index);

    if(index >= size)
    {
        printf("Invalid \n");
        return;
    }

    for(int i = index; i < size; i++)
    arr[i] = arr[i + 1];

    free(arr[size]);
    size--;

    printf("Updated Array: \n");
    for(int i = 0; i < size; i++)
    printf("%d ", arr[i]);
}

void largestElement()
{
    int max = arr[0];
    for(int i = 1; i < size; i++)
    if(arr[i] > max)
    max = arr[i];

    printf("Max Element: %d", max);
}

void smallestElement()
{
    int min = arr[0];

    for(int i = 1; i < size; i++)
    if(arr[i] < min)
    min = arr[i];

    printf("Min Element: %d", min);
}

int main()
{
    int flag = 1;
    int choice;
    printf("Enter initial size of array: \n");
    scanf("%d", &size);

    arr = calloc(size, sizeof(int));

    printf("Enter \n 1 to enter elements into array \n 2 to delete an element from the array \n 3 to get the largest number in the array \n 4 to get the smallest number from the array :");
    
while(flag)
{

    printf("\n Enter choice : \n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
        getElements();
        break;

        case 2:
        deleteElement();
        break;

        case 3:
        largestElement();
        break;

        case 4:
        smallestElement();
        break;

        default:
        flag = 0;
    }
}
    
    return 0;
}