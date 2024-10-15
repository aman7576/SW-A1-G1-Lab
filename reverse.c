#include<stdio.h>
#include<stdlib.h>

void reverse(int* arr,int n){
    int i=0;
    int j=n-1;

    while(j>i){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}
int main(){
    int n;
    printf("input size:");
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    printf("enter data:");
    for(int i=0;i<n;i++){
        
        
        scanf("%c",&arr[i]);
    }  

    reverse(arr,n);
    for(int i=0;i<n;i++){
        printf("%c",arr[i]);
    }
}
