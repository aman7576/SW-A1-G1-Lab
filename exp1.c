#include<stdio.h>
// Q1   :   Reverse an array
void main(){
    int arr[] = {1,23,34,2,112,10,21};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size/2;i++){
        int temp=arr[i];
        arr[i]=arr[size-i-1];
        arr[size-i-1]=temp;
    }
    for(int i=0;i<size;i++){
        printf("%d,",arr[i]);
    }
}