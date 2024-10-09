#include<stdio.h>

int reverse(int arr[], int n);
void printArr(int arr[], int n);

int main(){
    int arr[]={1,2,3,4,5,6,7};
    reverse(arr,7);
    printArr(arr,7);
    
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