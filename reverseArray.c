#include <stdio.h>
int main()
{
  int size;
    printf("Enter size of the array: \n");
    scanf("%d", &size);
    
    int arr[size];
    
     printf("Enter elements of the array: \n");
     
     for(int i = 0; i < size; i++)

{
  scanf("%d", &arr[i]);
}    
    
    int new_arr[size];
    for(int i = size - 1; i>=0; i--)
    {
        new_arr[size - 1-i] = arr[i];
    } 
    for(int i =0; i<size; i++)
    {
        arr[i] = new_arr[i];
    }
    printf("Reversed Array: \n");
    for(int i = 0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}