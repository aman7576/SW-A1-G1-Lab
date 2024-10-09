#include<stdio.h>

void printNumbers(int arr[],int n){
    for(int i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
}

int main(){
    int n;
    printf("enter the length : \n");
    scanf("%d", &n);
    int arr[n];
    int size=0;
    int counter=0;

    printf("1. for adding element \n");
    printf("2. for deleting element \n");
    printf("3. largest element \n");
    printf("4. smallest element \n");
    printf("______________________ \n");
    scanf("%d", &counter);

    do{
        if(counter==1){
            int num;
            printf("enter the number  : ");
            scanf("%d", &num);
            arr[size]=num;
            size++;
        } else if (counter==2){
            int idx;
            printf("enter the index : ");
            scanf("%d",&idx);
            for(int i=0;i<size-1;i++){
                if(i>=idx){
                    arr[i]=arr[i+1];
                }
            }
            size--;

        } else if (counter==3){
            int maxm=-99999;
            for(int i=0;i<size;i++){
                if (arr[i]>maxm){
                    maxm=arr[i];
                }
            }
            printf(" \nmaxm is : %d", maxm);

        } else {
            int  minm = 99999;
            for(int i=0;i<size;i++){
                if(arr[i]<minm){
                    minm=arr[i];
                }
            }
            printf("\nminimum is : %d", minm);
        }
        printf("\nenter the option : ");
        scanf("%d", &counter);

    } while(counter>0 && counter<5);

    for(int i=0;i<size;i++){
            printf("%d \t",arr[i]);
        }

    return 0;
}