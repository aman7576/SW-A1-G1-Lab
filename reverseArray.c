// reversing an array
#include<stdio.h>
void reverseArray(int arr[],int n){
    int left=0;
    int right=n-1;
    while(left<right){
        int temp = arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
        left++;
        right--;
    }
  
}
void printArray(int arr[],int n){
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
}

int main(){
  int arr[]={1,2,3,4,5,6};
  int n=sizeof(arr)/sizeof(int);
  reverseArray(arr,n);
  printArray(arr,n);
}