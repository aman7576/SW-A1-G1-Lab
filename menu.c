#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void add(int *arr,int index,int value,int size){
    if(size==0 && index==0){
        arr[index]=value;
    }
    else{
        for(int i=size-1;i>=index;i--){
            arr[i+1]=arr[i];
        }
        arr[index]=value;
        
    }

}
void deleteFromArray(int* arr,int index,int size){
    if(size==0){
        printf("no value to delete \n");
    }
    if(index==size-1){
        arr[index]=-1;
    }
    for(int i=index;i<size;i++){
        arr[i]=arr[i+1];
    }
}
int findMax(int *arr,int size){
    int maxi=-1e9;
    for(int i=0;i<size;i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
        
    }
    return maxi;
}
int findMin(int *arr,int size){
    int mini=1e9;
    for(int i=0;i<size;i++){
        if(arr[i]<mini){
            mini=arr[i];
        }
    }
    return mini;

}
void display(int*arr,int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("size is:%d",size);
}
int main(){
    char ch;
    int arr[100];
    int size=0;
    while(1){
        int choice;
        printf("enter your choice:");
        scanf("%d",&choice);
        if(choice==1){
            printf("enter value to add:");
            int value;
            scanf("%d",&value);
            printf("enter index:");
            int index;
            scanf("%d",&index);
            add(arr,index,value,size);
            size++;
        }
        else if(choice==2){
            int index;
            printf("enter index to delete:");
            scanf("%d",&index);
            deleteFromArray(arr,index,size);
            size--;
        }
        else if(choice==3){
            printf("maximum element is %d \n",findMax(arr,size));
        }
        else if(choice==4){
            printf("mainimum element is %d \n",findMin(arr,size));
        }
        else{
            display(arr,size);
        }
        printf("to continue press y:");
        getchar();
        scanf("%c",&ch);
        if(ch!='y'){
            break;
        }
    }
}