#include <stdio.h>
#define MAX_size 100
int size = 0;

void inputAnElement(int arr[]);
void deleteAnElement(int arr[]);
void largestInArray(int arr[]);
void smallestInArray(int arr[]);
void display(int arr[]);

void inputAnElement(int arr[]) {
    int length, value;
    printf("Enter the number of elements you want to add: ");
    scanf("%d", &length);
    if(size + length > MAX_size) {
        printf("Limit reached, cannot add more elements.\n");
        return;
    }
    for(int i=0; i<length; i++) {
        printf("Enter element %d: ", size + 1);
        scanf("%d", &value);
        arr[size++] = value;
    }
}
void deleteAnElement(int arr[]) {
    if(size ==0) {
        printf("Array is empty.\n");
        return;
    }
    int key;
    printf("Enter the element to delete : ");
    scanf("%d", &key);
    for(int i=0; i<size-1; i++) {
        if(arr[i] == key) {
            arr[i] = arr[i+1];
        }
        size--;
    }
    printf("Element deleted.\n");
}
void largestInArray(int arr[]) {
    int largest = 0;
    for(int i=0; i<size; i++) {
        if(largest < arr[i]) {
            largest = arr[i];
        }
    }
    printf("Largest element is %d \n", largest);
}
void smallestInArray(int arr[]) {
    int smallest = 0;
    for(int i=0; i<size; i++) {
        if(smallest > arr[i]) {
            smallest = arr[i];
        }
    }
    printf("Smallest element is %d \n", smallest);
}
void display(int arr[]) {
    for(int i=0; i<size; i++) {
        printf("%d", arr[i]);
    }
}

int main() {
    int arr[MAX_size];
    int flag = 1;
    while(flag) {
        printf("Please select an input \n");
        printf("1. Enter elements in the Array \n");
        printf("2. Delete element in the Array \n");
        printf("3. Find the largest element \n");
        printf("4. Find the smallest element \n");
        printf("5. Display the Array \n");
        printf("6. EXIT \n");

        int n;
        scanf("%d", &n);
        switch(n) {
            case 1: inputAnElement(arr);
                    break;
            case 2: deleteAnElement(arr);
                    break;
            case 3: largestInArray(arr);
                    break;
            case 4: smallestInArray(arr);
                    break;
            case 5: display(arr);
                    break;
            case 6: flag=0;
                    break;
            default: printf("INVALID INPUT");
        }
    }
}