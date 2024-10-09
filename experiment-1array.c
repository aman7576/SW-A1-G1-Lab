#include<stdio.h>
#define MAX_size 100
int size = 0;


void inputarr(int arr[]);
void deletearr(int arr[]);
void largest(int arr[]);
void smallest(int arr[]);
void display(int arr[]);

void inputarr(int arr[]) {
    int n, elem;
    printf("Enter the number of elements you want to add: ");
    scanf("%d", &n);

    if (size + n > MAX_size) {
        printf("Cannot add more elements. Array limit reached.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", size + 1);
        scanf("%d", &elem);
        arr[size++] = elem;
    }
}

void deletearr(int arr[]){
    if (size == 0) {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }

    int num;
    printf("Enter the element to delete: ");
    scanf("%d", &num);

    for (int i = 0; i < size - 1; i++) {
        if (arr[i]==num){
            arr[i] = arr[i + 1];}
    }

    size--;
    printf("Element deleted.\n");
}

void largest(int arr[]){
    int largest=-1e7;
    for(int i=0;i<size;i++){
        if(largest<arr[i]){
            largest=arr[i];
        }
    }
    printf("largest element is %d \n",largest);
}

void display(int arr[]){
    for(int i=0;i<size;i++){
        printf("%d",arr[i]);
    }
}

void smallest(int arr[]){
    int smallest=1e7;
    for(int i=0;i<size;i++){
        if(smallest>arr[i]){
            smallest=arr[i];
        }
    }
    printf("largest element is %d \n",smallest);
}

int main(){
    int arr[MAX_size];
    int flag=1;
    while(flag){
        printf("Please Select an input \n");
        printf("1. Enter elements in a one dimensional array \n");
        printf("2. delete element in a one dimensional array (have all conditions, beginning, last, middle index)  \n");
        printf("3, Find the largest element \n");
        printf("4. Find the smallest element \n");
        printf("5. diaplay\n");
        printf("6.exit \n");
        int n;
        scanf("%d",&n);
        switch(n){
            case 1:
            inputarr(arr);
            break;
            case 2:
            deletearr(arr);
            break;
            case 3:
            largest(arr);
            break;
            case 4:
            smallest(arr);
            break;
            case 5:
            display(arr);
            case 6:
            flag=0;
            break;
            default:
            printf("invalid input");

        }
    }
}