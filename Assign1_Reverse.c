#include<stdio.h>

int reverse(int arr[], int n);
void printArr(int arr[], int n);


int main(){
    int n;
    printf("enter the length of array : ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        arr[i]=num;
    }
    reverse(arr,n);
    printArr(arr,n);
    
    return 0;
}

int reverse(int arr[], int n){
    for (int i=0; i<(n/2);i++){
        int v1=arr[i];
        int v2=arr[n-i-1];
        arr[i]=v2;
        arr[n-i-1]=v1;
    }
}

void printArr(int arr[], int n){
    for(int i=0 ;i<n; i++){
        printf("%d\t",arr[i]);
    }
}