#include<stdio.h>
void print(int arr[], int n, int last_index)
{
    for(int i =0; i<=last_index; i++)
    {
        printf("%d     ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the number of elements in an array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter non-zero elements in the array: ");
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int last_index = n-1;
    int choice = 0;
    printf("Enter the number corresponding to the action you want to perform: \n");
    print(arr, n, last_index);
    printf("1. Delete an element\n2.Find the largest element\n3.Find the smallest element\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
        {
            printf("Enter the index of element you want to delete:");
            int el;
            scanf("%d", &el);
            arr[el] = 0;
            last_index--;
            for(int i = el; i<=last_index; i++)
            {
                arr[i] = arr[i+1];
            }
            print(arr,n, last_index);
        }
        break;
        
        case 2:
        {
            
            int max = -1000000000;
            for(int i = 0; i<n; i++)
            {
                if(arr[i]>max)
                {
                    max = arr[i];
                }
            }
            printf("The maximum number in the array is: %d", max);
        }
        break;

        case 3:
        {
            int min = 1000000000;
            for(int i = 0; i<n; i++)
            {
                if(arr[i]<min)
                {
                    min = arr[i];
                }
            }
            printf("The minimum number in the array is: %d", min);
        }
        break;

        default:
        {
            printf("SORRY! YOU ENTERED A WRONG CHOICE!!!!!!");
        }
    }

    
}