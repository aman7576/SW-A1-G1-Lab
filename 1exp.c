#include<stdio.h>
//reverse a string
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int temp[10];
    for(int i = 9; i>=0; i--)
    {
        temp[9-i] = arr[i];
    } 
    for(int i =0; i<10; i++)
    {
        arr[i] = temp[i];
    }
    for(int i = 0; i<10; i++)
    {
        printf("%d     ",arr[i]);
    }
}